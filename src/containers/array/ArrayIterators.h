#ifndef S21_ITERATORS_H
#define S21_ITERATORS_H

namespace s21 {

template <class T, std::size_t N>
class ArrayIterator {
  friend class array<T, N>;
  friend class ArrayConstIterator<T, N>;

 public:
  using value_type = T;
  using pointer = value_type*;
  using reference = value_type&;

  ArrayIterator();
  ArrayIterator(pointer ptr);

  pointer operator&();
  reference operator*();
  ArrayIterator& operator+(int n);
  ArrayIterator& operator++();
  ArrayIterator& operator--();
  bool operator==(const ArrayIterator n);
  bool operator!=(const ArrayIterator n);

 private:
  pointer ptr_;
};

template <class T, std::size_t N>
class ArrayConstIterator {
  friend class array<T, N>;
  friend class ArrayIterator<T, N>;

 public:
  using value_type = T;
  using pointer = const value_type*;
  using reference = const value_type&;

  ArrayConstIterator();
  ArrayConstIterator(pointer ptr);

  pointer operator&() const;
  reference operator*() const;
  ArrayConstIterator operator+(int n) const;
  ArrayConstIterator& operator++();
  ArrayConstIterator& operator--();
  bool operator==(ArrayConstIterator n) const;
  bool operator!=(ArrayConstIterator n) const;

 private:
  pointer ptr_;
};

}  // namespace s21
#endif  // S21_ITERATORS_H
