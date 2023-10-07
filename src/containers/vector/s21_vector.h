#ifndef CPP2_S21_CONTAINERS_1_SRC_CONTAINERS_VECTOR_S21_VECTOR_H
#define CPP2_S21_CONTAINERS_1_SRC_CONTAINERS_VECTOR_S21_VECTOR_H

#include <cmath>
#include <iostream>
#include <limits>

namespace s21 {

template <class T>
class VectorIterator;

template <class T>
class VectorConstIterator;

template <class T>
class vector {
 public:
  // Vector Member type
  using value_type = T;
  using pointer = value_type *;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = VectorIterator<value_type>;
  using const_iterator = VectorConstIterator<value_type>;
  using size_type = std::size_t;

  // Vector Member functions
  vector();
  vector(size_type n);
  vector(std::initializer_list<value_type> const &items);
  vector(const vector &v);
  vector(vector &&v);
  ~vector();

  // Vector Capacity
  bool empty() const;
  size_type size() const;
  size_type max_size() const;
  void reserve(size_type n);
  size_type capacity() const;
  void shrink_to_fit();

  // Vector Element access
  reference at(size_type pos);
  reference operator[](size_type pos);
  const_reference front() const;
  const_reference back() const;
  pointer data();

  // Vector Element constant access
  const_reference operator[](size_type pos) const;

  // Vector Iterators
  iterator begin();
  iterator end();
  const_iterator cbegin() const;
  const_iterator cend() const;

  // Overload operators
  bool operator==(const vector &v);
  vector &operator=(const vector &v);
  vector &operator=(vector &&v);

  // Vector Modifiers
  void clear();
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void swap(vector &other);

  // Bonus part
  template <typename... Args>
  iterator insert_many(const_iterator pos, Args &&...args);

  template <typename... Args>
  void insert_many_back(Args &&...args);

 private:
  size_type size_;
  size_type capacity_;
  pointer vector_;

  // My own functions
  void NullVector();
  void InitVector(size_type n);
  void DeleteVector();
  void CopyVector(const vector &v);
  void MoveVector(vector &&v);
  void fill(const_reference value);
};

}  // namespace s21

#include "VectorIterators.tpp"
#include "s21_vector.tpp"
#endif  // CPP2_S21_CONTAINERS_1_SRC_CONTAINERS_VECTOR_S21_VECTOR_H
