#ifndef S21_ARRAY_H
#define S21_ARRAY_H

#include <cmath>
#include <iostream>
#include <limits>

namespace s21 {

template <class T, std::size_t N>
class ArrayIterator;

template <class T, std::size_t N>
class ArrayConstIterator;

template <class T, std::size_t N>
class array {
 public:
  // Array Member type
  using value_type = T;
  using pointer = value_type *;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = ArrayIterator<value_type, N>;
  using const_iterator = ArrayConstIterator<value_type, N>;
  using size_type = std::size_t;

  // Array Member functions
  array();
  array(std::initializer_list<value_type> const &items);
  array(const array &v);
  array(array &&v);
  ~array();

  // Array Capacity
  bool empty() const;
  size_type size() const;
  size_type max_size() const;

  // Array Element access
  reference at(size_type pos);
  const_reference at(size_type pos) const;
  reference operator[](size_type pos);
  const_reference operator[](size_type pos) const;
  const_reference front() const;
  const_reference back() const;
  pointer data();

  // Array Iterators
  iterator begin();
  iterator end();
  const_iterator cbegin() const;
  const_iterator cend() const;

  // Overload operators
  bool operator==(const array &v);
  array &operator=(const array &v);
  array &operator=(array &&v);

  // Array Modifiers
  void swap(array &other);
  void fill(const_reference value);

 private:
  size_type size_;
  pointer array_;

  // My own functions
  void NullArray();
  void InitArray();
  void DeleteArray();
  void CopyArray(const array &v);
  void MoveArray(array &&v);
};

}  // namespace s21

#include "ArrayIterators.tpp"
#include "s21_array.tpp"
#endif  // S21_ARRAY_H
