#ifndef S21_QUEUE_H
#define S21_QUEUE_H

#include "../list/s21_list.h"

namespace s21 {

template <typename T>
class queue {
 public:
  // Queue Member type
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = std::size_t;

  // Queue Member functions
  queue() : data_() {}

  queue(std::initializer_list<value_type> const &items) {
    data_.clear();
    for (const auto &item : items) {
      push(item);
    }
  }

  queue(const queue &q) : data_(q.data_) {}

  queue(queue &&q) : data_(std::move(q.data_)) {}

  ~queue() {}

  queue &operator=(const queue &q) {
    data_ = q.data_;
    return *this;
  }

  queue &operator=(queue &&q) {
    data_ = std::move(q.data_);
    return *this;
  }

  // Queue Element access
  const_reference front() { return data_.front(); }
  const_reference back() { return data_.back(); }

  // Queue Capacity
  bool empty() const { return data_.empty(); }
  size_type size() const { return data_.size(); }

  // Queue Modifiers
  void push(const_reference value) { data_.push_back(value); }
  void pop() { data_.pop_front(); }
  void swap(queue &other) { data_.swap(other.data_); }

  template <typename... Args>
  void InsertManyBack(Args &&...args) {
    data_.InsertManyBack();
  }

 private:
  list<T> data_;
};

}  // namespace s21

#endif  // S21_QUEUE_H
