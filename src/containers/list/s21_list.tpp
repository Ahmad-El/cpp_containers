// #include "s21_list.h"

namespace s21 {
//  List Functions
template <typename T>
list<T>::list() : end_(nullptr), size_(0) {
  initialization();
}

template <typename T>
list<T>::list(size_type n) : end_(nullptr), size_(0) {
  if (n >= max_size())
    throw std::out_of_range("Limit of the container is exceeded");
  initialization();
  for (; n > 0; --n) {
    push_back(end_->value_);
  }
}

template <typename T>
list<T>::list(std::initializer_list<T> const &items) : end_(nullptr), size_(0) {
  initialization();
  for (const auto &item : items) {
    push_back(item);
  }
}

template <typename T>
list<T>::list(const list &l) : end_(nullptr), size_(0) {
  initialization();
  *this = l;
}

template <typename T>
void list<T>::initialization() {
  end_ = new Node<T>();
  end_->next_ = end_;
  end_->prev_ = end_;
  size_ = 0;
}

template <typename T>
list<T>::list(list &&l) : end_(nullptr), size_(0) {
  if (this == &l) {
    throw std::invalid_argument("Error move!");
  }
  initialization();
  swap(l);
}

template <typename T>
list<T>::~list() {
  clear();
  delete end_;
}

template <typename T>
typename list<T>::list &list<T>::operator=(list &&l) {
  if (this != &l) {
    clear();
    swap(l);
  }
  return *this;
}

template <typename T>
list<T> &list<T>::operator=(const list &other) {
  if (this != &other) {
    clear();
    Node<T> *tmp = other.end_->next_;
    for (size_type i = 0; i < other.size_; ++i) {
      push_back(tmp->value_);
      tmp = tmp->next_;
    }
  }
  return *this;
}
// List Element access

template <typename T>
typename list<T>::const_reference list<T>::front() {
  if (size_ == 0) {
    throw std::out_of_range("Front(): the list is empty");
  }
  return end_->next_->value_;
}

template <typename T>
typename list<T>::const_reference list<T>::back() {
  if (size_ == 0) {
    throw std::out_of_range("Front(): the list is empty");
  }
  return end_->prev_->value_;
}

// List Iterators
template <typename T>
typename list<T>::iterator list<T>::begin() const {
  return iterator(end_->next_);
}

template <typename T>
typename list<T>::iterator list<T>::end() const {
  return iterator(end_);
}

template <typename T>
typename list<T>::const_iterator list<T>::cbegin() const {
  return const_iterator(end_->next_);
}

template <typename T>
typename list<T>::const_iterator list<T>::cend() const {
  return const_iterator(end_);
}

// List Capacity
template <typename T>
bool list<T>::empty() const {
  return size_ == 0;
}

template <typename T>
typename list<T>::size_type list<T>::size() const {
  return size_;
}

template <typename T>
typename list<T>::size_type list<T>::max_size() {
  return (std::numeric_limits<size_type>::max() / sizeof(Node<T>) / 2);
}

// List Modifiers
template <typename T>
void list<T>::clear() {
  Node<T> *node_ptr = end_->next_;
  Node<T> *end_node_ptr = end_;
  while (node_ptr != end_node_ptr) {
    Node<T> *next_node_ptr = node_ptr->next_;
    delete node_ptr;
    node_ptr = next_node_ptr;
  }
  end_->next_ = end_;
  end_->prev_ = end_;
  size_ = 0;
}

template <typename T>
typename list<T>::iterator list<T>::insert(iterator pos,
                                           const_reference value) {
  Node<T> *element = pos.ptr_;
  Node<T> *new_value = new Node(value);
  new_value->next_ = element;
  new_value->prev_ = element->prev_;
  element->prev_->next_ = new_value;
  element->prev_ = new_value;
  size_++;
  return iterator(new_value);
}

template <typename T>
void list<T>::erase(iterator pos) {
  if (pos == end()) {
    throw std::invalid_argument("Invalid argument");
  }
  Node<T> *element = pos.ptr_;
  element->prev_->next_ = element->next_;
  element->next_->prev_ = element->prev_;
  delete element;
  size_--;
}

template <typename T>
void list<T>::push_back(const_reference value) {
  if (size() >= max_size()) {
    throw std::out_of_range("Limit of the container is exceeded");
  }
  Node<T> *tmp = new Node(value);
  tmp->next_ = end_;
  tmp->prev_ = end_->prev_;
  end_->prev_->next_ = tmp;
  end_->prev_ = tmp;
  size_++;
}

template <typename T>
void list<T>::pop_back() {
  if (empty()) {
    throw std::invalid_argument("the list is empty");
  }
  Node<T> *tmp;
  tmp = end_->prev_;
  end_->prev_ = end_->prev_->prev_;
  end_->prev_->next_ = end_;
  delete tmp;
  size_--;
}

template <typename T>
void list<T>::push_front(const_reference value) {
  if (size() >= max_size()) {
    throw std::out_of_range("Limit of the container is exceeded");
  }
  Node<T> *tmp = new Node(value);
  tmp->prev_ = end_;
  tmp->next_ = end_->next_;
  end_->next_->prev_ = tmp;
  end_->next_ = tmp;
  size_++;
}

template <typename T>
void list<T>::pop_front() {
  if (empty()) {
    throw std::invalid_argument("the list is empty");
  }
  Node<T> *tmp;
  tmp = end_->next_;
  end_->next_ = end_->next_->next_;
  end_->next_->prev_ = end_;
  delete tmp;
  size_--;
}

template <typename T>
void list<T>::swap(list &other) {
  using std::swap;
  swap(this->size_, other.size_);
  swap(this->end_, other.end_);
}

template <typename T>
void list<T>::merge(list &other) {
  if (this != &other) {
    iterator iter_other = other.begin();
    iterator iter_this = begin();
    while (!other.empty()) {
      if (iter_this == end()) {
        insert(iter_this, *iter_other);
        other.erase(iter_other);
        ++iter_other;
      } else if (*iter_other < *iter_this) {
        insert(iter_this, *iter_other);
        other.erase(iter_other);
        ++iter_other;
      } else {
        ++iter_this;
      }
    }
  }
}

template <typename T>
void list<T>::splice(const_iterator pos, list &other) {
  iterator tmp_iter(pos.ptr_);
  for (iterator iter = other.begin(); iter != other.end(); ++iter) {
    insert(tmp_iter, *iter);
    other.erase(iter);
  }
}

template <typename T>
void list<T>::reverse() {
  using std::swap;
  Node<T> *tmp = end_->next_;
  swap(end_->next_, end_->prev_);
  while (tmp != end_) {
    swap(tmp->prev_, tmp->next_);
    tmp = tmp->prev_;
  }
}

template <typename T>
void list<T>::unique() {
  if (!empty()) {
    for (iterator iter = begin(); iter != end(); iter++) {
      if (iter.ptr_->value_ == iter.ptr_->prev_->value_) {
        iterator delete_iter = (iter - 1);
        erase(delete_iter);
      }
    }
  }
}

template <typename T>
void list<T>::sort() {
  if (size_ > 1) {
    quick_sort(begin(), end());
  }
}

template <typename T>
void list<T>::quick_sort(iterator begin, iterator end) {
  value_type pivot = *begin;
  iterator current_iter = begin;
  ++current_iter;
  iterator new_begin = begin;

  while (current_iter != end) {
    iterator tmp_iter = current_iter + 1;
    if (*current_iter < pivot) {
      if (new_begin == begin) new_begin = current_iter;

      current_iter.ptr_->prev_->next_ = current_iter.ptr_->next_;
      current_iter.ptr_->next_->prev_ = current_iter.ptr_->prev_;

      current_iter.ptr_->prev_ = begin.ptr_->prev_;
      current_iter.ptr_->next_ = begin.ptr_;

      begin.ptr_->prev_->next_ = current_iter.ptr_;
      begin.ptr_->prev_ = current_iter.ptr_;
    }
    current_iter = tmp_iter;
  }
  if (new_begin != begin) quick_sort(new_begin, begin);
  if (begin.ptr_->next_ != end.ptr_) quick_sort(++begin, end);
}

template <typename T>
template <typename... Args>
typename list<T>::iterator list<T>::InsertMany(const_iterator pos,
                                               Args &&...args) {
  iterator tmp_iter(pos.ptr_);
  (insert(tmp_iter, std::forward<Args>(args)), ...);
  return --tmp_iter;
}

template <typename T>
template <typename... Args>
void list<T>::InsertManyBack(Args &&...args) {
  (insert(end(), std::forward<Args>(args)), ...);
}

template <typename T>
template <typename... Args>
void list<T>::InsertManyFront(Args &&...args) {
  iterator tmp_iter = begin();
  (insert(tmp_iter, std::forward<Args>(args)), ...);
}

}  // namespace s21