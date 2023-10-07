#include "VectorIterators.h"

namespace s21 {
template <class value_type>
VectorIterator<value_type>::VectorIterator() {
  ptr_ = nullptr;
}

template <class value_type>
VectorIterator<value_type>::VectorIterator(pointer ptr) {
  ptr_ = ptr;
}

template <class value_type>
typename VectorIterator<value_type>::reference
VectorIterator<value_type>::operator*() {
  return *ptr_;
}

template <class value_type>
typename VectorIterator<value_type>::pointer
VectorIterator<value_type>::operator&() {
  return ptr_;
}

template <class value_type>
VectorIterator<value_type>& VectorIterator<value_type>::operator+(int n) {
  ptr_ = ptr_ + n;
  return *this;
}

template <class value_type>
VectorIterator<value_type>& VectorIterator<value_type>::operator++() {
  ++ptr_;
  return *this;
}

template <class value_type>
VectorIterator<value_type>& VectorIterator<value_type>::operator--() {
  --ptr_;
  return *this;
}

template <class value_type>
bool VectorIterator<value_type>::operator==(const VectorIterator n) {
  return ptr_ == n.ptr_;
}

template <class value_type>
bool VectorIterator<value_type>::operator!=(const VectorIterator n) {
  return ptr_ != n.ptr_;
}

}  // namespace s21

namespace s21 {
template <class value_type>
VectorConstIterator<value_type>::VectorConstIterator() {
  ptr_ = nullptr;
}

template <class value_type>
VectorConstIterator<value_type>::VectorConstIterator(pointer ptr) {
  ptr_ = ptr;
}

template <class value_type>
typename VectorConstIterator<value_type>::reference
VectorConstIterator<value_type>::operator*() const {
  return *ptr_;
}

template <class value_type>
typename VectorConstIterator<value_type>::pointer
VectorConstIterator<value_type>::operator&() const {
  return ptr_;
}

template <class value_type>
VectorConstIterator<value_type> VectorConstIterator<value_type>::operator+(
    int n) const {
  VectorConstIterator<value_type> tmp(*this);
  for (int i = 0; i < n; i++) {
    ++tmp;
  }
  return tmp;
}

template <class value_type>
VectorConstIterator<value_type>& VectorConstIterator<value_type>::operator++() {
  ++ptr_;
  return *this;
}

template <class value_type>
VectorConstIterator<value_type>& VectorConstIterator<value_type>::operator--() {
  --ptr_;
  return *this;
}

template <class value_type>
bool VectorConstIterator<value_type>::operator==(VectorConstIterator n) {
  return ptr_ == n.ptr_;
}

template <class value_type>
bool VectorConstIterator<value_type>::operator!=(VectorConstIterator n) {
  return ptr_ != n.ptr_;
}

}  // namespace s21