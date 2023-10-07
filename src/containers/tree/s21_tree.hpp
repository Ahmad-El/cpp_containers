#include "s21_tree.h"

// CONSTRUCTORs AND COPY AND MOVE OPERATORS
// ***************************************
template <class key_type, class value_type>
AVLTree<key_type, value_type>::AVLTree() : root_(nullptr) {}

template <class key_type, class value_type>
AVLTree<key_type, value_type>::AVLTree(const AVLTree& other) {
  *this = other;
}

template <class key_type, class value_type>
AVLTree<key_type, value_type>& AVLTree<key_type, value_type>::operator=(
    const AVLTree& other) {
  if (this == &other) {
    return *this;
  }
  clear();
  CopyTree(other.root_);
  repeate_ = other.repeate_;
  size_ = other.size_;
  return *this;
}
template <class key_type, class value_type>
AVLTree<key_type, value_type>::AVLTree(AVLTree&& other) noexcept {
  *this = std::move(other);
}

template <class key_type, class value_type>
AVLTree<key_type, value_type>& AVLTree<key_type, value_type>::operator=(
    AVLTree&& other) noexcept {
  if (this == &other) {
    return *this;
  }
  size_ = other.size_;
  repeate_ = other.repeate_;
  root_ = other.root_;
  other.size_ = 0;
  other.repeate_ = false;
  other.root_ = nullptr;
  return *this;
}

template <class key_type, class value_type>
AVLTree<key_type, value_type>::~AVLTree() {
  clear();
  delete end_;
}

// PUBLIC METHODS
// **************************************************************

template <class key_type, class value_type>
void AVLTree<key_type, value_type>::change_repeate(bool repeate) {
  repeate_ = repeate;
}

template <class key_type, class value_type>
void AVLTree<key_type, value_type>::clear() {
  DeleteTree(root_);
  root_ = nullptr;
  size_ = 0;
}

template <class key_type, class value_type>
void AVLTree<key_type, value_type>::insert(key_type key, value_type value) {
  // data_pointer max_key = get_max();
  root_ = Insert(root_, key, value);
  end_->prev = get_max();
}

template <class key_type, class value_type>
void AVLTree<key_type, value_type>::print() {
  PrettyPrintTree(root_);
}

template <class key_type, class value_type>
typename AVLTree<key_type, value_type>::data_pointer
AVLTree<key_type, value_type>::get_root_() {
  return root_;
}

template <class key_type, class value_type>
typename AVLTree<key_type, value_type>::data_pointer
AVLTree<key_type, value_type>::make_search(key_type key) {
  return SearchNode(root_, key);
}

template <class key_type, class value_type>
typename AVLTree<key_type, value_type>::data_pointer
AVLTree<key_type, value_type>::get_max() {
  return GetMax(root_);
}

template <class key_type, class value_type>
typename AVLTree<key_type, value_type>::data_pointer
AVLTree<key_type, value_type>::get_min() {
  return GetMin(root_);
}

template <class key_type, class value_type>
typename AVLTree<key_type, value_type>::size_type
AVLTree<key_type, value_type>::get_size() {
  return size_;
}

template <class key_type, class value_type>
void AVLTree<key_type, value_type>::remove(key_type key) {
  if (root_ == nullptr) return;
  data_pointer pointer = make_search(key);
  if (pointer != nullptr) {
    if (pointer->value != nullptr) delete pointer->value;
    root_ = Remove(root_, key);
  }
}

template <class key_type, class value_type>
value_type AVLTree<key_type, value_type>::get_value(key_type key) {
  return make_search(key)->value;
}

template <class key_type, class value_type>
typename AVLTree<key_type, value_type>::data_pointer
AVLTree<key_type, value_type>::begin() {
  data_pointer temp_min = get_min();
  data_pointer temp_max = get_max();

  if (temp_min != nullptr) temp_min->prev = nullptr;
  if (temp_max != nullptr) temp_max->next = end_;
  if (temp_min == nullptr) temp_min = end_;
  return temp_min;
}

template <class key_type, class value_type>
typename AVLTree<key_type, value_type>::data_pointer
AVLTree<key_type, value_type>::end() {
  return end_;
}

template <class key_type, class value_type>
void AVLTree<key_type, value_type>::count(const key_type& key, size_type* cnt,
                                          data_pointer root) {
  if (root == nullptr) return;
  count(key, cnt, root->left);
  count(key, cnt, root->right);
  if (root->key == key) *cnt = *cnt + 1;
}

// PRIVATE METHODS
// *************************************************************
template <class key_type, class value_type>
typename AVLTree<key_type, value_type>::data_pointer
AVLTree<key_type, value_type>::Insert(data_pointer root, key_type key,
                                      value_type value) {
  if (root == nullptr) {
    size_++;
    data_pointer node = new data_type(key);
    node->value = new value_type(value);
    node->balance = 0;
    node->right = nullptr;
    node->left = nullptr;
    return node;
  }
  if (key < root->key) {
    bool is_null = root->left == nullptr;
    root->left = Insert(root->left, key, value);
    if (is_null) SetLeftRoot(root);

  } else if (key > root->key) {
    bool is_null = root->right == nullptr;
    root->right = Insert(root->right, key, value);
    if (is_null) SetRightRoot(root);

  } else if (key == root->key && repeate_ == true) {
    bool is_null = root->left == nullptr;
    root->left = Insert(root->left, key, value);
    if (is_null) SetLeftRoot(root);
  }
  UpdateHeight(root);
  return Rebalance(root);
}

template <class key_type, class value_type>
void AVLTree<key_type, value_type>::SetLeftRoot(data_pointer root) {
  root->left->next = root;
  if (root->prev != nullptr) {
    root->left->prev = root->prev;
    root->left->prev->next = root->left;
  }
  root->prev = root->left;
}

template <class key_type, class value_type>
void AVLTree<key_type, value_type>::SetRightRoot(data_pointer root) {
  root->right->prev = root;
  if (root->next != nullptr) {
    root->right->next = root->next;
    root->right->next->prev = root->right;
  }
  root->next = root->right;
}

template <class key_type, class value_type>
int AVLTree<key_type, value_type>::GetHeight(data_pointer root) {
  return root == nullptr ? -1 : root->balance;
}

template <class key_type, class value_type>
int AVLTree<key_type, value_type>::GetBalance(data_pointer root) {
  return (root == nullptr) ? 0 : GetHeight(root->right) - GetHeight(root->left);
}

template <class key_type, class value_type>
void AVLTree<key_type, value_type>::UpdateHeight(data_pointer root) {
  root->balance = std::max(GetHeight(root->left), GetHeight(root->right)) + 1;
}

template <class key_type, class value_type>
typename AVLTree<key_type, value_type>::data_pointer
AVLTree<key_type, value_type>::Rebalance(data_pointer root) {
  int balance = GetBalance(root);
  if (balance == -2) {
    if (GetBalance(root->left) == 1) {
      root->left = LeftRotation(root->left);
    }
    root = RightRotation(root);
  } else if (balance == 2) {
    if (GetBalance(root->right) == -1) {
      root->right = RightRotation(root->right);
    }
    root = LeftRotation(root);
  }
  return root;
}

template <class key_type, class value_type>
typename AVLTree<key_type, value_type>::data_pointer
AVLTree<key_type, value_type>::RightRotation(data_pointer root) {
  data_pointer ltemp;
  data_pointer lrtemp;
  ltemp = root->left;
  lrtemp = ltemp->right;
  ltemp->right = root;
  root->left = lrtemp;
  root = ltemp;
  UpdateHeight(root->right);
  UpdateHeight(root);
  return root;
}

template <class key_type, class value_type>
typename AVLTree<key_type, value_type>::data_pointer
AVLTree<key_type, value_type>::LeftRotation(data_pointer root) {
  data_pointer rtemp;
  data_pointer rltemp;
  rtemp = root->right;
  rltemp = rtemp->left;
  rtemp->left = root;
  root->right = rltemp;
  root = rtemp;
  UpdateHeight(root->left);
  UpdateHeight(root);
  return root;
}

template <class key_type, class value_type>
void AVLTree<key_type, value_type>::PrettyPrintTree(data_pointer node,
                                                    std::string prefix,
                                                    bool isLeft) {
  if (node == nullptr) {
    std::cout << "Empty tree";
    return;
  }

  if (node->right) {
    PrettyPrintTree(node->right, prefix + (isLeft ? "│   " : "    "), false);
  }
  std::cout << prefix + (isLeft ? "└── " : "┌── ") + std::to_string(node->key) +
                   "\n";

  if (node->left) {
    PrettyPrintTree(node->left, prefix + (isLeft ? "    " : "│   "), true);
  }
}

template <class key_type, class value_type>
void AVLTree<key_type, value_type>::DeleteTree(data_pointer root) {
  if (root == nullptr) return;
  DeleteTree(root->left);
  DeleteTree(root->right);
  if (root->value != nullptr) delete root->value;
  delete root;
}

template <class key_type, class value_type>
typename AVLTree<key_type, value_type>::data_pointer
AVLTree<key_type, value_type>::SearchNode(data_pointer root, key_type key) {
  if (root == nullptr || root->key == key) return root;
  return (key < root->key) ? SearchNode(root->left, key)
                           : SearchNode(root->right, key);
}

template <class key_type, class value_type>
typename AVLTree<key_type, value_type>::data_pointer
AVLTree<key_type, value_type>::GetMin(data_pointer root) {
  if (root == nullptr || root->left == nullptr) return root;
  return GetMin(root->left);
}

template <class key_type, class value_type>
typename AVLTree<key_type, value_type>::data_pointer
AVLTree<key_type, value_type>::GetMax(data_pointer root) {
  if (root == nullptr || root->right == nullptr) return root;
  return GetMax(root->right);
}

template <class key_type, class value_type>
typename AVLTree<key_type, value_type>::data_pointer
AVLTree<key_type, value_type>::Remove(data_pointer root, key_type key) {
  if (root == nullptr)
    return root;
  else if (key < root->key)
    root->left = Remove(root->left, key);
  else if (key > root->key)
    root->right = Remove(root->right, key);
  else {
    if (root->left == nullptr || root->right == nullptr) {
      size_ -= 1;
      data_pointer new_root =
          (root->left == nullptr) ? root->right : root->left;

      if (root->prev != nullptr) root->prev->next = root->next;
      if (root->next != nullptr) root->next->prev = root->prev;

      delete root;
      root = new_root;
      new_root = nullptr;
    } else {
      data_pointer temp = GetMin(root->right);
      root->key = temp->key;
      root->value = temp->value;
      root->right = Remove(root->right, temp->key);
    }
  }
  if (root != nullptr) {
    UpdateHeight(root);
    root = Rebalance(root);
  }
  return root;
}

template <class key_type, class value_type>
void AVLTree<key_type, value_type>::CopyTree(data_pointer root) {
  if (root != nullptr) {
    this->insert(root->key, *root->value);
    CopyTree(root->left);
    CopyTree(root->right);
  }
}
