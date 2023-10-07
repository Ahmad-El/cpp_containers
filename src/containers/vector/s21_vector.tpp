#include "s21_vector.h"

namespace s21 {

// Vector Member functions
template <class value_type>
vector<value_type>::vector() {
  NullVector();
}

template <class value_type>
vector<value_type>::vector(size_type n) {
  InitVector(n);
}

template <class value_type>
vector<value_type>::vector(std::initializer_list<value_type> const &items) {
  size_ = capacity_ = items.size();
  vector_ = new value_type[size_];
  std::copy(items.begin(), items.end(), vector_);
}

template <class value_type>
vector<value_type>::vector(const vector &v) {
  InitVector(v.size());
  CopyVector(v);
}

template <class value_type>
vector<value_type>::vector(vector &&v) {
  MoveVector(std::move(v));
}

template <class value_type>
vector<value_type>::~vector() {
  DeleteVector();
}

template <class value_type>
typename s21::vector<value_type> &vector<value_type>::operator=(
    const vector &v) {
  if (this != &v) {
    DeleteVector();
    InitVector(v.size());
    CopyVector(v);
  }
  return *this;
}

template <class value_type>
typename s21::vector<value_type> &vector<value_type>::operator=(vector &&v) {
  if (this != &v) {
    DeleteVector();
    swap(v);
    v.NullVector();
  }
  return *this;
}

// My own functions
template <class value_type>
void vector<value_type>::NullVector() {
  size_ = 0;
  capacity_ = 0;
  vector_ = nullptr;
};

template <class value_type>
void vector<value_type>::InitVector(size_type n) {
  size_ = n;
  capacity_ = n;
  vector_ = new value_type[n];
  fill(0);
};

template <class value_type>
void vector<value_type>::DeleteVector() {
  if (vector_ != nullptr) {
    delete[] vector_;
  }
  NullVector();
};

template <class value_type>
void vector<value_type>::CopyVector(const vector &v) {
  size_type temp = v.size();
  for (size_type i = 0; i < temp; i++) {
    vector_[i] = v.vector_[i];
  }
};

template <class value_type>
void vector<value_type>::MoveVector(vector &&v) {
  size_ = v.size_;
  capacity_ = v.capacity_;
  vector_ = v.vector_;
  v.NullVector();
}

template <class value_type>
bool vector<value_type>::operator==(const vector &v) {
  size_type cursize = size();
  bool flag = true;
  if (cursize != v.size()) flag = false;
  for (size_type i = 0; i < cursize && flag; i++) {
    if (vector_[i] != v.vector_[i]) flag = false;
  }
  return flag;
}

// Vector Capacity
template <class value_type>
bool vector<value_type>::empty() const {
  return size() == 0;
}

template <class value_type>
typename vector<value_type>::size_type vector<value_type>::size() const {
  return size_;
}

template <class value_type>
typename vector<value_type>::size_type vector<value_type>::max_size() const {
  return std::numeric_limits<size_type>::max() / sizeof(size_type);
}

template <class value_type>
void vector<value_type>::reserve(size_type n) {
  if (n > capacity()) {
    size_type size_temp = size();
    vector<value_type> temp(n);
    temp.CopyVector(*this);
    DeleteVector();
    swap(temp);
    size_ = size_temp;
  }
}

template <class value_type>
typename vector<value_type>::size_type vector<value_type>::capacity() const {
  return capacity_;
}

template <class value_type>
void vector<value_type>::shrink_to_fit() {
  vector<value_type> temp(*this);
  swap(temp);
}

// Vector Element access
template <class value_type>
typename vector<value_type>::reference vector<value_type>::at(size_type pos) {
  if (pos >= size()) {
    throw std::out_of_range("out of range");
  }
  return vector_[pos];
}

template <class value_type>
typename vector<value_type>::reference vector<value_type>::operator[](
    size_type pos) {
  if (pos >= size()) {
    throw std::out_of_range("out of range");
  }
  return vector_[pos];
}

template <class value_type>
typename vector<value_type>::const_reference vector<value_type>::operator[](
    size_type pos) const {
  if (pos >= size()) {
    throw std::out_of_range("out of range");
  }
  return vector_[pos];
}

template <class value_type>
typename vector<value_type>::const_reference vector<value_type>::front() const {
  if (size_ == 0) {
    throw std::out_of_range("out of range");
  }
  return vector_[0];
}

template <class value_type>
typename vector<value_type>::const_reference vector<value_type>::back() const {
  if (size_ == 0) {
    throw std::out_of_range("out of range");
  }
  return vector_[size_ - 1];
}

template <class value_type>
typename vector<value_type>::pointer vector<value_type>::data() {
  return vector_;
}

// Vector Iterators
template <class value_type>
typename vector<value_type>::iterator vector<value_type>::begin() {
  return iterator(vector_);
}

template <class value_type>
typename vector<value_type>::const_iterator vector<value_type>::cbegin() const {
  return const_iterator(vector_);
}

template <class value_type>
typename vector<value_type>::iterator vector<value_type>::end() {
  return iterator(vector_ + size_);
}

template <class value_type>
typename vector<value_type>::const_iterator vector<value_type>::cend() const {
  return const_iterator(vector_ + size_);
}

// Vector Modifiers
template <class value_type>
void vector<value_type>::clear() {
  DeleteVector();
}

template <class value_type>
typename vector<value_type>::iterator vector<value_type>::insert(
    iterator pos, const_reference value) {
  size_type temp_ret = &pos - &begin();
  vector<value_type> temp(capacity_ + (size_ == capacity_));
  iterator index_temp = temp.begin();
  iterator index = begin();
  if (begin() == pos) {
    *index_temp = value;
    ++index_temp;
  }
  for (; index != pos && index != end(); ++index) {
    *index_temp = *index;
    ++index_temp;
  }
  if (begin() != pos) {
    *index_temp = value;
    ++index_temp;
  }
  for (; index != end(); ++index) {
    *index_temp = *index;
    ++index_temp;
  }
  temp.size_ = size_ + 1;
  swap(temp);
  return begin() + temp_ret;
}

template <class value_type>
void vector<value_type>::erase(iterator pos) {
  if (pos == end() && size_ == 0) {
    throw std::out_of_range("out of range");
  }

  vector<value_type> temp(capacity_);

  if (begin() != --end()) {
    iterator index_temp = temp.begin();
    iterator index = begin();

    if (begin() == pos) {
      ++index;
    }
    for (; index != pos && index != end(); ++index) {
      *index_temp = *index;
      ++index_temp;
    }
    if (begin() != pos) {
      ++index;
    }
    for (; index != end(); ++index) {
      *index_temp = *index;
      ++index_temp;
    }
  }

  temp.size_ = size_ - 1;
  swap(temp);
}

template <class value_type>
void vector<value_type>::push_back(const_reference value) {
  insert(end(), value);
}

template <class value_type>
void vector<value_type>::pop_back() {
  erase(--end());
}

template <class value_type>
void vector<value_type>::swap(vector &other) {
  vector<value_type> temp(capacity_);
  temp.CopyVector(*this);
  temp.size_ = size();
  DeleteVector();
  InitVector(other.capacity_);
  size_ = other.size();
  CopyVector(other);
  other.DeleteVector();
  other.InitVector(temp.capacity_);
  other.CopyVector(temp);
}

template <class value_type>
void vector<value_type>::fill(const_reference value) {
  for (iterator i = begin(); i != end(); ++i) {
    *i = value;
  }
}

// Bonus part
template <class value_type>
template <typename... Args>
typename vector<value_type>::iterator vector<value_type>::insert_many(
    const_iterator pos, Args &&...args) {
  vector<value_type> temp{args...};
  iterator ret = begin() + (&pos - &cbegin());
  for (size_t i = 0; i < temp.size(); ++i) {
    ret = insert(ret, temp[i]);
    ++ret;
  }
  return ret;
}

template <class value_type>
template <typename... Args>
void vector<value_type>::insert_many_back(Args &&...args) {
  vector<value_type> temp{args...};
  for (size_t i = 0; i < temp.size(); ++i) {
    insert(end(), temp[i]);
  }
}
}  // namespace s21