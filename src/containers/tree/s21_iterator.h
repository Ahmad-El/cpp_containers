#ifndef S21_ITERATOR_H_
#define S21_ITERATOR_H_

#include <iostream>

#include "s21_tree.h"

template <typename container, bool IsConst>
class Iterator {
 public:
  using key_type = typename container::key_type;
  using value_type = typename container::value_type;
  using reference =
      typename std::conditional<IsConst, const value_type&, value_type&>::type;
  using pointer =
      typename std::conditional<IsConst, const value_type*, value_type*>::type;
  using data_type = Node<key_type, value_type>;
  using data_pointer = Node<key_type, value_type>*;

 public:
  Iterator(){};
  Iterator(data_pointer ptr) : ptr_(ptr){};
  ~Iterator() {}
  Iterator(const Iterator& other) {
    ptr_ = other.ptr_;
    end_ = other.end_;
    temp = other.temp;
  }

  Iterator& operator++(int) {
    if (ptr_ != nullptr && ptr_->next != nullptr) ptr_ = ptr_->next;
    return *this;
  }
  bool operator!=(const Iterator& ptr) {
    if (ptr_ == nullptr) return false;
    return !(*this == ptr);
  }

  Iterator operator=(const Iterator& it) {
    this->ptr_ = nullptr;

    if (this == &it) {
      return *this;
    }
    ptr_ = it.ptr_;
    return *this;
  }
  bool operator==(const Iterator& it) { return (ptr_ == it.ptr_); }
  Iterator operator++() {
    Iterator it = *this;
    (*this)++;
    return it;
  }
  Iterator& operator--(int) {
    if (ptr_ == nullptr) return *this;
    if (ptr_->prev != nullptr) ptr_ = ptr_->prev;
    return *this;
  }
  Iterator operator--() {
    Iterator it = *this;
    (*this)--;
    return it;
  }
  virtual reference operator*() {
    if (ptr_ == nullptr) return *temp.value;
    return *ptr_->value;
  }

 protected:
  data_pointer ptr_;
  data_pointer end_ = nullptr;
  data_type temp;
};

#endif  // S21_ITERATOR_H_