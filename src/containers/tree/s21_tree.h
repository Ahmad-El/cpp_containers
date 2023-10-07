#ifndef S21_TREE_H_
#define S21_TREE_H_

#include <iostream>

template <class key_type, class value_type>
struct Node {
  int balance;
  key_type key;
  value_type* value;
  Node* left = nullptr;
  Node* right = nullptr;
  Node* next = nullptr;
  Node* prev = nullptr;
  Node(){};
  Node(key_type _key) : key(_key) { value = nullptr; };
  Node(key_type _key, value_type _value) : key(_key), value(_value){};
};

template <class T, class U>
class AVLTree {
 public:
  using key_type = T;
  using value_type = U;
  using size_type = size_t;
  using data_type = Node<key_type, value_type>;
  using data_pointer = Node<key_type, value_type>*;

 public:
  AVLTree();
  AVLTree(const AVLTree& other);
  AVLTree& operator=(const AVLTree& other);
  AVLTree(AVLTree&& other) noexcept;
  AVLTree& operator=(AVLTree&& other) noexcept;
  ~AVLTree();

 public:
  void clear();
  void print();
  void insert(key_type key, value_type value);
  data_pointer make_search(key_type);
  data_pointer get_root_();
  data_pointer get_max();
  data_pointer get_min();
  size_type get_size();
  void remove(key_type key);
  value_type get_value(key_type key);
  data_pointer begin();
  data_pointer end();
  void change_repeate(bool repeate);
  void count(const key_type& key, size_type* cnt, data_pointer root);

 private:
  data_pointer Insert(data_pointer root, key_type key, value_type value);
  void SetLeftRoot(data_pointer root);
  void SetRightRoot(data_pointer root);
  int GetBalance(data_pointer root);
  int GetHeight(data_pointer root);
  void UpdateHeight(data_pointer root);
  data_pointer Rebalance(data_pointer root);
  data_pointer RightRotation(data_pointer root);
  data_pointer LeftRotation(data_pointer root);
  void PrettyPrintTree(data_pointer node, std::string prefix = "",
                       bool isLeft = true);
  void DeleteTree(data_pointer root);
  data_pointer SearchNode(data_pointer root, key_type key);
  data_pointer GetMin(data_pointer root);
  data_pointer GetMax(data_pointer root);
  data_pointer Remove(data_pointer root, key_type key);
  void CopyTree(data_pointer root);

 private:
  data_pointer root_;
  size_type size_ = 0;
  bool repeate_ = false;
  data_pointer end_ = new data_type;
};
#include "s21_tree.hpp"
#endif  // S21_TREE_H_