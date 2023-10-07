#ifndef CPP2_S21_CONTAINERS_1_SRC_CONTAINERS_VECTOR_VECTORITERATORS_H
#define CPP2_S21_CONTAINERS_1_SRC_CONTAINERS_VECTOR_VECTORITERATORS_H

namespace s21 {

template <class T>
class VectorIterator {
  friend class vector<T>;
  friend class VectorConstIterator<T>;

 public:
  using value_type = T;
  using pointer = value_type*;
  using reference = value_type&;

  VectorIterator();
  VectorIterator(pointer ptr);

  pointer operator&();
  reference operator*();
  VectorIterator& operator+(int n);
  VectorIterator& operator++();
  VectorIterator& operator--();
  bool operator==(const VectorIterator n);
  bool operator!=(const VectorIterator n);

 private:
  pointer ptr_;
};

template <class T>
class VectorConstIterator {
  friend class vector<T>;
  friend class VectorIterator<T>;

 public:
  using value_type = T;
  using pointer = const value_type*;
  using reference = const value_type&;

  VectorConstIterator();
  VectorConstIterator(pointer ptr);

  pointer operator&() const;
  reference operator*() const;
  VectorConstIterator operator+(int n) const;
  VectorConstIterator& operator++();
  VectorConstIterator& operator--();
  bool operator==(VectorConstIterator n);
  bool operator!=(VectorConstIterator n);

 private:
  pointer ptr_;
};

}  // namespace s21
#endif  // CPP2_S21_CONTAINERS_1_SRC_CONTAINERS_VECTOR_VECTORITERATORS_H
