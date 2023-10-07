#ifndef S21_MULTISET_H
#define S21_MULTISET_H
#include "../set/s21_set.h"

namespace s21 {
template <class T>
class multiset : public set<T> {
 public:
  using key_type = typename set<T>::key_type;
  using value_type = typename set<key_type>::value_type;
  using reference = typename set<key_type>::reference;
  using const_reference = typename set<key_type>::const_reference;
  using iterator = typename set<key_type>::iterator;
  using const_iterator = typename set<key_type>::const_iterator;
  using size_type = typename set<key_type>::size_type;
  using node_type = typename set<key_type>::node_type;
  using node_pointer = typename set<key_type>::node_pointer;

 public:  // constructor and operators;
  multiset();
  multiset(std::initializer_list<key_type> const& items);
  multiset(const multiset& other) : set<key_type>() {
    this->set_repeate_value(true);
    *this = other;
  }
  multiset& operator=(const multiset& other) {
    if (this == &other) {
      return *this;
    }
    this->set_repeate_value(true);
    set<key_type>::operator=(other);
    return *this;
  }
  multiset(multiset&& other) noexcept {
    set<key_type>();
    this->set_repeate_value(true);

    *this = std::move(other);
  }
  multiset& operator=(multiset&& other) {
    this->clear();
    if (this == &other) return *this;
    this->set_repeate_value(true);
    set<key_type>::operator=(std::move(other));
    return *this;
  }

 public:  // Methods
  iterator insert(const key_type& key);
  size_type count(const key_type& key);
  iterator lower_bound(const key_type& key);
  iterator upper_bound(const key_type& key);
  std::pair<iterator, iterator> equal_range(const key_type& key);
};

template <class key_type>
multiset<key_type>::multiset() : set<key_type>() {
  this->set_repeate_value(true);
}

template <class key_type>
multiset<key_type>::multiset(std::initializer_list<key_type> const& items)
    : set<key_type>() {
  this->set_repeate_value(true);
  for (auto it = items.begin(); it != items.end(); it++) {
    this->AddItem(*it);
  }
}

template <class key_type>
typename multiset<key_type>::iterator multiset<key_type>::insert(
    const key_type& key) {
  this->AddItem(key);
  return this->find(key);
}

template <class key_type>
typename multiset<key_type>::size_type multiset<key_type>::count(
    const key_type& key) {
  return this->CountMe(key);
}

template <class key_type>
typename multiset<key_type>::iterator multiset<key_type>::lower_bound(
    const key_type& key) {
  return this->search_initial(key);
}

template <class key_type>
typename multiset<key_type>::iterator multiset<key_type>::upper_bound(
    const key_type& key) {
  return this->search_upper(key);
}

template <class key_type>
std::pair<typename multiset<key_type>::iterator,
          typename multiset<key_type>::iterator>
multiset<key_type>::equal_range(const key_type& key) {
  iterator lower = this->search_initial(key);
  iterator higher = this->search_upper(key);
  return {lower, higher};
}

}  // namespace s21

#endif  // S21_MULTISET_H
