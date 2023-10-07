#ifndef _S21_MAP_
#define _S21_MAP_

#include <initializer_list>
#include <iostream>
#include <limits>
#include <vector>

#include "../tree/s21_iterator.h"
#include "../tree/s21_tree.h"

namespace s21 {

template <class Key, class T>
class map {
 public:
  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<const key_type, mapped_type>;
  using reference = value_type&;
  using const_reference = const value_type&;
  using iterator = Iterator<map<Key, T>, false>;
  using const_iterator = Iterator<map<Key, T>, true>;
  using size_type = size_t;
  using node_type = Node<key_type, value_type>;
  using node_pointer = Node<key_type, value_type>*;

 public:
  map();
  map(std::initializer_list<value_type> const& items);
  map(const map& m);
  map& operator=(const map& s);
  map(map&& m);
  map& operator=(map&& m);
  ~map();

 public:
  bool empty();
  void clear();
  size_type size();
  size_type max_size();
  void swap(map& other);
  void merge(map& other);
  void erase(iterator pos);
  void print() { tree_.print(); }
  void erase(const key_type& value);
  bool contains(const key_type& key);
  mapped_type& at(const key_type& key);
  mapped_type& operator[](const key_type& key);
  std::pair<iterator, bool> insert(const value_type& value);
  std::pair<iterator, bool> insert(const key_type& key, const mapped_type& obj);
  std::pair<iterator, bool> insert_or_assign(const key_type& key,
                                             const mapped_type& obj);
  template <typename... Args>
  std::vector<std::pair<iterator, bool>> insert_many(Args&&... args);

  iterator begin();
  iterator end();
  const_iterator cbegin();
  const_iterator cend();

 private:
  void SortFoldExtression(std::vector<key_type>* key,
                          std::vector<mapped_type>* mapp, key_type variable);
  void SortFoldExtression(std::vector<key_type>* key,
                          std::vector<mapped_type>* mapp, mapped_type variable);

 private:
  AVLTree<key_type, value_type> tree_;
  node_pointer end_ = nullptr;
};

template <class key_type, class mapped_type>
typename map<key_type, mapped_type>::const_iterator
map<key_type, mapped_type>::cbegin() {
  node_pointer pointer = tree_.begin();
  end_ = tree_.end();
  const_iterator it(pointer);
  return it;
}
template <class key_type, class mapped_type>
typename map<key_type, mapped_type>::const_iterator
map<key_type, mapped_type>::cend() {
  end_ = tree_.end();
  return const_iterator(end_);
}

template <class key_type, class mapped_type>
typename map<key_type, mapped_type>::iterator
map<key_type, mapped_type>::begin() {
  node_pointer pointer = tree_.begin();
  end_ = tree_.end();
  iterator it(pointer);
  return it;
}

template <class key_type, class mapped_type>
typename map<key_type, mapped_type>::iterator
map<key_type, mapped_type>::end() {
  end_ = tree_.end();
  return iterator(end_);
}

template <class key_type, class mapped_type>
map<key_type, mapped_type>::map(){};

template <class key_type, class mapped_type>
map<key_type, mapped_type>::map(
    std::initializer_list<map::value_type> const& items) {
  for (auto it = items.begin(); it != items.end(); it++) {
    value_type temp = *it;
    tree_.insert(temp.first, temp);
  }
}

template <class key_type, class mapped_type>
map<key_type, mapped_type>::map(const map& m) {
  *this = m;
}

template <class key_type, class mapped_type>
map<key_type, mapped_type>& map<key_type, mapped_type>::operator=(
    const map& m) {
  if (this == &m) {
    return *this;
  }
  tree_ = m.tree_;
  return *this;
}

template <class key_type, class mapped_type>
map<key_type, mapped_type>::map(map&& m) {
  *this = std::move(m);
}

template <class key_type, class mapped_type>
map<key_type, mapped_type>& map<key_type, mapped_type>::operator=(map&& m) {
  tree_.clear();
  if (this == &m) {
    return *this;
  }
  tree_.clear();
  if (this == &m) return *this;
  tree_ = std::move(m.tree_);
  return *this;
}

template <class key_type, class mapped_type>
map<key_type, mapped_type>::~map() {
  tree_.clear();
}

template <class key_type, class mapped_type>
mapped_type& map<key_type, mapped_type>::operator[](const key_type& key) {
  if (tree_.make_search(key) == nullptr)
    tree_.insert(key, {key, mapped_type{}});
  return tree_.make_search(key)->value->second;
}

template <class key_type, class mapped_type>
mapped_type& map<key_type, mapped_type>::at(const key_type& key) {
  node_pointer pointer = tree_.make_search(key);
  if (pointer == nullptr)
    throw ::std::out_of_range("such key doesn't exist !!!");
  return pointer->value->second;
}

template <class key_type, class mapped_type>
bool map<key_type, mapped_type>::empty() {
  return tree_.get_root_() == nullptr;
}

template <class key_type, class mapped_type>
typename map<key_type, mapped_type>::size_type
map<key_type, mapped_type>::size() {
  return tree_.get_size();
}

template <class key_type, class mapped_type>
typename map<key_type, mapped_type>::size_type
map<key_type, mapped_type>::max_size() {
  size_type _set_size = sizeof(node_type);
  return (std::numeric_limits<size_type>::max() / _set_size) - size();
}

template <class key_type, class mapped_type>
void map<key_type, mapped_type>::clear() {
  tree_.clear();
}

template <class key_type, class mapped_type>
std::pair<typename map<key_type, mapped_type>::iterator, bool>
map<key_type, mapped_type>::insert(const value_type& value) {
  node_pointer pointer = tree_.make_search(value.first);
  bool existance = false;
  if (pointer == nullptr) {
    existance = true;
    tree_.insert(value.first, value);
    pointer = tree_.make_search(value.first);
  }
  iterator it(pointer);
  return {it, existance};
}

template <class key_type, class mapped_type>
std::pair<typename map<key_type, mapped_type>::iterator, bool>
map<key_type, mapped_type>::insert(const key_type& key,
                                   const mapped_type& obj) {
  return insert({key, obj});
}

template <class key_type, class mapped_type>
std::pair<typename map<key_type, mapped_type>::iterator, bool>
map<key_type, mapped_type>::insert_or_assign(const key_type& key,
                                             const mapped_type& obj) {
  if (contains(key)) {
    node_pointer pointer = tree_.make_search(key);
    pointer->value->second = obj;
    return {iterator(pointer), false};
  } else {
    return insert({key, obj});
  }
}

template <class key_type, class mapped_type>
void map<key_type, mapped_type>::erase(iterator pos) {
  if (tree_.get_root_() != nullptr) tree_.remove((*pos).first);
}

template <class key_type, class mapped_type>
void map<key_type, mapped_type>::erase(const key_type& key) {
  tree_.remove(key);
}

template <class key_type, class mapped_type>
void map<key_type, mapped_type>::swap(map& other) {
  map<key_type, mapped_type> temp = std::move(other);
  other = std::move(*this);
  *this = std::move(temp);
}

template <class key_type, class mapped_type>
void map<key_type, mapped_type>::merge(map& other) {
  for (auto item : other) {
    insert(item);
  }
  other.clear();
}

template <class key_type, class mapped_type>
bool map<key_type, mapped_type>::contains(const key_type& key) {
  return tree_.make_search(key) != nullptr;
}

// BONUS INSERT_MANY
// **********************************************************************
template <class key_type, class mapped_type>
template <typename... Args>
std::vector<std::pair<typename map<key_type, mapped_type>::iterator, bool>>
map<key_type, mapped_type>::insert_many(Args&&... args) {
  std::vector<std::pair<iterator, bool>> result;
  std::vector<key_type> keys;
  std::vector<mapped_type> mapp;
  (((SortFoldExtression(&keys, &mapp, (args)))), ...);
  for (int i = 0; i < keys.size(); i++) {
    result.push_back(insert({keys[i], mapp[i]}));
  }
  keys.clear();
  mapp.clear();
  return result;
}

template <class key_type, class mapped_type>
void map<key_type, mapped_type>::SortFoldExtression(
    std::vector<key_type>* key, std::vector<mapped_type>* mapp,
    key_type variable) {
  key->push_back(variable);
}

template <class key_type, class mapped_type>
void map<key_type, mapped_type>::SortFoldExtression(
    std::vector<key_type>* key, std::vector<mapped_type>* mapp,
    mapped_type variable) {
  mapp->push_back(variable);
}

}  // namespace s21
#endif  // _S21_MAP_
