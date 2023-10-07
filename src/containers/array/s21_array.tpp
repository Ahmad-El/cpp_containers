#include "s21_array.h"

namespace s21 {

// array Member functions
template <class value_type, std::size_t N>
array<value_type, N>::array() {
  InitArray();
}

template <class value_type, std::size_t N>
array<value_type, N>::array(std::initializer_list<value_type> const &items) {
  size_ = N;
  array_ = new value_type[N];
  std::copy(items.begin(), items.end(), array_);
}

template <class value_type, std::size_t N>
array<value_type, N>::array(const array &v) {
  InitArray();
  CopyArray(v);
}

template <class value_type, std::size_t N>
array<value_type, N>::array(array &&v) {
  MoveArray(std::move(v));
}

template <class value_type, std::size_t N>
array<value_type, N>::~array() {
  DeleteArray();
}

// My own functions
template <class value_type, std::size_t N>
void array<value_type, N>::NullArray() {
  size_ = 0;
  array_ = nullptr;
};

template <class value_type, std::size_t N>
void array<value_type, N>::InitArray() {
  size_ = N;
  array_ = new value_type[size_];
  fill(0);
};

template <class value_type, std::size_t N>
void array<value_type, N>::DeleteArray() {
  if (array_ != nullptr) {
    delete[] array_;
    array_ = nullptr;
  }
  NullArray();
};

template <class value_type, std::size_t N>
void array<value_type, N>::CopyArray(const array &v) {
  size_ = N;
  for (size_type i = 0; i < size_; i++) {
    array_[i] = v.array_[i];
  }
};

template <class value_type, std::size_t N>
void array<value_type, N>::MoveArray(array &&v) {
  size_ = N;
  array_ = v.array_;
  v.NullArray();
}

template <class value_type, std::size_t N>
typename array<value_type, N>::array &array<value_type, N>::operator=(
    const array &v) {
  for (size_t i = 0; i < N; ++i) {
    array_[i] = v.array_[i];
  }
  return *this;
}

template <class value_type, std::size_t N>
typename array<value_type, N>::array &array<value_type, N>::operator=(
    array &&v) {
  for (size_t i = 0; i < N; ++i) {
    array_[i] = std::move(v.array_[i]);
  }
  return *this;
}

template <class value_type, std::size_t N>
bool array<value_type, N>::operator==(const array &v) {
  bool flag = true;
  if (N != v.size()) flag = false;
  for (size_type i = 0; i < N && flag; i++) {
    if (array_[i] != v.array_[i]) flag = false;
  }
  return flag;
}

// array
template <class value_type, std::size_t N>
bool array<value_type, N>::empty() const {
  return size_ == 0;
}

template <class value_type, std::size_t N>
typename array<value_type, N>::size_type array<value_type, N>::size() const {
  return size_;
}

template <class value_type, std::size_t N>
typename array<value_type, N>::size_type array<value_type, N>::max_size()
    const {
  return N;
}

// array Element access
template <class value_type, std::size_t N>
typename array<value_type, N>::reference array<value_type, N>::at(
    size_type pos) {
  if (pos >= N) {
    throw std::out_of_range("[at]: out of range");
  }
  return array_[pos];
}

template <class value_type, std::size_t N>
typename array<value_type, N>::const_reference array<value_type, N>::at(
    size_type pos) const {
  if (pos >= N) {
    throw std::out_of_range("[at]: out of range");
  }
  return array_[pos];
}

template <class value_type, std::size_t N>
typename array<value_type, N>::reference array<value_type, N>::operator[](
    size_type pos) {
  return at(pos);
}

template <class value_type, std::size_t N>
typename array<value_type, N>::const_reference array<value_type, N>::operator[](
    size_type pos) const {
  return at(pos);
}

template <class value_type, std::size_t N>
typename array<value_type, N>::const_reference array<value_type, N>::front()
    const {
  return at(0);
}

template <class value_type, std::size_t N>
typename array<value_type, N>::const_reference array<value_type, N>::back()
    const {
  return at(N - 1);
}

template <class value_type, std::size_t N>
typename array<value_type, N>::pointer array<value_type, N>::data() {
  return array_;
}

// array Iterators
template <class value_type, std::size_t N>
typename array<value_type, N>::iterator array<value_type, N>::begin() {
  return iterator(array_);
}

template <class value_type, std::size_t N>
typename array<value_type, N>::iterator array<value_type, N>::end() {
  return iterator(array_ + size_);
}

template <class value_type, std::size_t N>
typename array<value_type, N>::const_iterator array<value_type, N>::cbegin()
    const {
  return const_iterator(array_);
}

template <class value_type, std::size_t N>
typename array<value_type, N>::const_iterator array<value_type, N>::cend()
    const {
  return const_iterator(array_ + size_);
}

// Array Modifiers
template <class value_type, std::size_t N>
void array<value_type, N>::swap(array &other) {
  array<value_type, N> temp(*this);
  DeleteArray();
  InitArray();
  CopyArray(other);
  other.DeleteArray();
  other.InitArray();
  other.CopyArray(temp);
}

template <class value_type, std::size_t N>
void array<value_type, N>::fill(const_reference value) {
  for (iterator i = begin(); i != end(); ++i) {
    *i = value;
  }
}

}  // namespace s21