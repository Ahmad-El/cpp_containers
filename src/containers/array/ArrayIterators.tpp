#include "ArrayIterators.h"

namespace s21 {
template <class value_type, std::size_t N>
ArrayIterator<value_type, N>::ArrayIterator() {
  ptr_ = nullptr;
}

template <class value_type, std::size_t N>
ArrayIterator<value_type, N>::ArrayIterator(pointer ptr) {
  ptr_ = ptr;
}

template <class value_type, std::size_t N>
typename ArrayIterator<value_type, N>::reference
ArrayIterator<value_type, N>::operator*() {
  return *ptr_;
}

template <class value_type, std::size_t N>
typename ArrayIterator<value_type, N>::pointer
ArrayIterator<value_type, N>::operator&() {
  return ptr_;
}

template <class value_type, std::size_t N>
ArrayIterator<value_type, N>& ArrayIterator<value_type, N>::operator+(int n) {
  ptr_ = ptr_ + n;
  return *this;
}

template <class value_type, std::size_t N>
ArrayIterator<value_type, N>& ArrayIterator<value_type, N>::operator++() {
  ++ptr_;
  return *this;
}

template <class value_type, std::size_t N>
ArrayIterator<value_type, N>& ArrayIterator<value_type, N>::operator--() {
  --ptr_;
  return *this;
}

template <class value_type, std::size_t N>
bool ArrayIterator<value_type, N>::operator==(const ArrayIterator n) {
  return ptr_ == n.ptr_;
}

template <class value_type, std::size_t N>
bool ArrayIterator<value_type, N>::operator!=(const ArrayIterator n) {
  return ptr_ != n.ptr_;
}

}  // namespace s21

namespace s21 {
template <class value_type, std::size_t N>
ArrayConstIterator<value_type, N>::ArrayConstIterator() {
  ptr_ = nullptr;
}

template <class value_type, std::size_t N>
ArrayConstIterator<value_type, N>::ArrayConstIterator(pointer ptr) {
  ptr_ = ptr;
}

template <class value_type, std::size_t N>
typename ArrayConstIterator<value_type, N>::reference
ArrayConstIterator<value_type, N>::operator*() const {
  return *ptr_;
}

template <class value_type, std::size_t N>
typename ArrayConstIterator<value_type, N>::pointer
ArrayConstIterator<value_type, N>::operator&() const {
  return ptr_;
}

template <class value_type, std::size_t N>
ArrayConstIterator<value_type, N> ArrayConstIterator<value_type, N>::operator+(
    int n) const {
  ArrayConstIterator<value_type, N> tmp(*this);
  for (int i = 0; i < n; i++) {
    ++tmp;
  }
  return tmp;
}

template <class value_type, std::size_t N>
ArrayConstIterator<value_type, N>&
ArrayConstIterator<value_type, N>::operator++() {
  ++ptr_;
  return *this;
}

template <class value_type, std::size_t N>
ArrayConstIterator<value_type, N>&
ArrayConstIterator<value_type, N>::operator--() {
  --ptr_;
  return *this;
}

template <class value_type, std::size_t N>
bool ArrayConstIterator<value_type, N>::operator==(
    const ArrayConstIterator n) const {
  return ptr_ == n.ptr_;
}

template <class value_type, std::size_t N>
bool ArrayConstIterator<value_type, N>::operator!=(
    const ArrayConstIterator n) const {
  return ptr_ != n.ptr_;
}

}  // namespace s21