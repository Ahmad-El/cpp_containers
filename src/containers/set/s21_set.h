#ifndef S21_SET_H
#define S21_SET_H

#include <initializer_list>
#include <iostream>
#include <limits>
#include <utility>
#include <vector>

#include "../tree/s21_iterator.h"
#include "../tree/s21_tree.h"

namespace s21 {
template <class T1, class T2>
struct pair {
  T1 first;
  T2 second;
};

template <class T>
class set {
 public:
  using key_type = T;
  using value_type = T;
  using reference = value_type&;
  using const_reference = const value_type&;
  using iterator = Iterator<set<T>, true>;
  using const_iterator = iterator;
  using node_type = Node<T, T>;
  using node_pointer = node_type*;
  using size_type = size_t;

 public:
  set();
  set(std::initializer_list<value_type> const& items);
  set(const set& s);
  set& operator=(const set& s);
  set(set&& s) noexcept;
  set& operator=(set&& s);
  ~set();

 public:
  template <typename... Args>
  std::vector<pair<iterator, bool>> insert_many(Args&&... args);
  //   s21::vector<pair<iterator, bool>> insert_many(Args&&... args);

  bool empty();
  void clear();
  iterator end();
  iterator begin();
  size_type size();
  size_type max_size();
  void swap(set& other);
  void merge(set& other);
  void erase(iterator pos);
  void erase(const key_type& value);
  bool contains(const key_type& key);
  iterator find(const key_type& value);
  pair<iterator, bool> insert(key_type key);

 private:
  AVLTree<key_type, value_type> tree_;
  node_pointer end_ = nullptr;

 protected:
  void AddItem(value_type arg);
  void set_repeate_value(bool repeate);
  size_type CountMe(const key_type& key);
  iterator search_initial(key_type key);
  iterator search_upper(key_type key);
};

template <class key_type>
typename set<key_type>::iterator set<key_type>::search_initial(key_type key) {
  node_pointer initial = tree_.make_search(key);
  if (initial == nullptr) {
    return iterator(end_);
  }
  while (initial->prev != nullptr && initial->prev->key == key)
    initial = initial->prev;
  return iterator(initial);
}
template <class key_type>
typename set<key_type>::iterator set<key_type>::search_upper(key_type key) {
  node_pointer last = tree_.make_search(key);
  if (last == nullptr) {
    return iterator(end_);
  }
  while (last->next != nullptr && last->key == last->next->key)
    last = last->next;
  if (last->next == nullptr)
    return end();
  else
    last = last->next;
  return iterator(last);
}

template <class value_type>
void set<value_type>::set_repeate_value(bool repeate) {
  tree_.change_repeate(repeate);
}

template <class value_type>
typename set<value_type>::size_type set<value_type>::CountMe(
    const key_type& key) {
  size_type cnt = 0;
  tree_.count(key, &cnt, tree_.get_root_());
  return cnt;
}

template <class value_type>
set<value_type>::set() {}

template <class value_type>
set<value_type>::set(std::initializer_list<value_type> const& items) {
  for (auto it = items.begin(); it != items.end(); it++) {
    AddItem(*it);
  }
}

template <class value_type>
set<value_type>::set(const set& s) {
  *this = s;
}

template <class value_type>
set<value_type>& set<value_type>::operator=(const set& s) {
  if (this == &s) {
    return *this;
  }
  tree_ = s.tree_;
  return *this;
}

template <class value_type>
set<value_type>::set(set&& s) noexcept {
  *this = std::move(s);
}

template <class value_type>
set<value_type>& set<value_type>::operator=(set&& s) {
  tree_.clear();
  if (this == &s) return *this;
  tree_ = std::move(s.tree_);
  return *this;
}
template <class value_type>
set<value_type>::~set() {
  tree_.clear();
}

template <class value_type>
void set<value_type>::AddItem(value_type arg) {
  tree_.insert(arg, arg);
}

template <class key_type>
pair<typename set<key_type>::iterator, bool> set<key_type>::insert(
    key_type key) {
  bool _exist = false;
  set::node_pointer pointer = tree_.make_search(key);
  if (pointer == nullptr) {
    _exist = true;
    AddItem(key);
    pointer = tree_.make_search(key);
  }
  pair<set::iterator, bool> item;
  set::iterator it(pointer);
  item.first = it;
  item.second = _exist;
  return item;
}

template <class value_type>
void set<value_type>::merge(set& other) {
  for (auto item : other) {
    AddItem(item);
  }
  other.clear();
}

template <class value_type>
void set<value_type>::swap(set& other) {
  set<value_type> temp = std::move(other);
  other = std::move(*this);
  *this = std::move(temp);
}

template <class value_type>
void set<value_type>::erase(const key_type& value) {
  tree_.remove(value);
}

template <class value_type>
void set<value_type>::erase(iterator pos) {
  if (pos != end()) tree_.remove(*pos);
}

template <class value_type>
template <typename... Args>
std::vector<pair<typename set<value_type>::iterator, bool>>
set<value_type>::insert_many(Args&&... args) {
  std::vector<pair<set::iterator, bool>> result;
  ((result.emplace_back(insert(std::forward<Args>(args))), ...));
  return result;
}

template <class value_type>
bool set<value_type>::empty() {
  return tree_.get_root_() == nullptr;
}

template <class value_type>
typename set<value_type>::size_type set<value_type>::size() {
  return tree_.get_size();
}

template <class value_type>
typename set<value_type>::size_type set<value_type>::max_size() {
  size_type _set_size = sizeof(node_type);
  return (std::numeric_limits<size_type>::max() / _set_size) - size();
}
template <class value_type>
void set<value_type>::clear() {
  tree_.clear();
}

template <class value_type>
typename set<value_type>::iterator set<value_type>::begin() {
  node_pointer pointer = tree_.begin();
  end_ = tree_.end();
  iterator it(pointer);
  return it;
}
template <class value_type>
typename set<value_type>::iterator set<value_type>::end() {
  return iterator(end_);
}

template <class value_type>
typename set<value_type>::iterator set<value_type>::find(
    const key_type& value) {
  node_pointer pointer = tree_.make_search(value);
  if (pointer == nullptr) return end();
  return iterator(pointer);
}

template <class value_type>
bool set<value_type>::contains(const key_type& key) {
  return tree_.make_search(key) != nullptr;
}

}  // namespace s21

#endif  // S21_SET_H
