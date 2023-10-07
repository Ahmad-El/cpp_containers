#include <gtest/gtest.h>

#include <set>

#include "s21_multiset.h"

TEST(multiset_test, basic_constr) {
  s21::multiset<int> tree_d;
  s21::multiset<double> tree_i;
  s21::multiset<char> tree_c;
  EXPECT_EQ(tree_d.size(), 0);
  EXPECT_EQ(tree_i.size(), 0);
  EXPECT_EQ(tree_c.size(), 0);
}

TEST(multiset_test, constr_with_indefinite_number_of_elements) {
  s21::multiset<double> multiset_1({1.1, 2.2, 3.3, 3.3, 4.4, 5.5, 1.1});
  std::multiset<double> orignal_multiset_1({1.1, 2.2, 3.3, 3.3, 4.4, 5.5, 1.1});
  EXPECT_EQ(multiset_1.size(), 7);
  auto it = multiset_1.begin();
  auto it_2 = orignal_multiset_1.begin();
  for (; it != multiset_1.end(); ++it) {
    EXPECT_DOUBLE_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(multiset_test, constr_with_indefinite_number_of_elements_string) {
  s21::multiset<char> multiset_1({'t', 'w', 't', 'r'});
  std::multiset<char> orignal_multiset_1({'t', 'w', 't', 'r'});
  EXPECT_EQ(multiset_1.size(), 4);
  auto it = multiset_1.begin();
  auto it_2 = orignal_multiset_1.begin();
  for (; it != multiset_1.end(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(multiset_test, copy_constr) {
  s21::multiset<char> multiset_1({'t', 'w', 't', 'r'});
  EXPECT_EQ(multiset_1.size(), 4);
  s21::multiset<char> multiset_2(multiset_1);

  EXPECT_EQ(multiset_1.size(), 4);
  EXPECT_EQ(multiset_2.size(), 4);

  auto it = multiset_1.begin();
  auto it_2 = multiset_2.begin();
  for (; it != multiset_1.end(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(multiset_test, copy_constr_01) {
  s21::multiset<char> multiset_1;
  EXPECT_EQ(multiset_1.size(), 0);
  s21::multiset<char> multiset_2(multiset_1);

  EXPECT_EQ(multiset_1.size(), 0);
  EXPECT_EQ(multiset_2.size(), 0);

  auto it = multiset_1.begin();
  auto it_2 = multiset_2.begin();
  for (; it != multiset_1.end(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(multiset_test, copy_operator_01) {
  s21::multiset<char> multiset_1({'t', 'w', 't', 'r'});
  EXPECT_EQ(multiset_1.size(), 4);
  s21::multiset<char> multiset_2({'J', 'P', 'M', 'J', 'P', 'M'});
  EXPECT_EQ(multiset_2.size(), 6);

  multiset_1 = multiset_2;
  EXPECT_EQ(multiset_1.size(), 6);
  EXPECT_EQ(multiset_2.size(), 6);
  auto it = multiset_1.begin();
  auto it_2 = multiset_2.begin();
  for (; it != multiset_1.end(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(multiset_test, copy_operator_02) {
  s21::multiset<int> multiset_1({1, 2, 1});
  s21::multiset<int> multiset_2;

  std::multiset<int> orignal_multiset_1({1, 2, 1});
  std::multiset<int> orignal_multiset_2;

  EXPECT_EQ(multiset_1.size(), 3);

  multiset_1 = multiset_2;
  orignal_multiset_1 = orignal_multiset_2;
  EXPECT_EQ(multiset_1.size(), orignal_multiset_1.size());
  EXPECT_EQ(multiset_1.size(), 0);
  EXPECT_EQ(multiset_2.size(), 0);
}

TEST(multiset_test, copy_operator_06) {
  s21::multiset<int> multiset_1({1, 2, 1});

  std::multiset<int> orignal_multiset_1({1, 2, 1});

  EXPECT_EQ(multiset_1.size(), 3);

  multiset_1 = multiset_1;
  orignal_multiset_1 = orignal_multiset_1;

  EXPECT_EQ(multiset_1.size(), orignal_multiset_1.size());
  EXPECT_EQ(multiset_1.size(), 3);
  EXPECT_EQ(orignal_multiset_1.size(), 3);
}

TEST(multiset_test, copy_operator_05) {
  s21::multiset<int> multiset_1;
  s21::multiset<int> multiset_2;

  EXPECT_EQ(multiset_1.size(), 0);

  multiset_1 = multiset_2;
  EXPECT_EQ(multiset_1.size(), 0);
  EXPECT_EQ(multiset_2.size(), 0);
}

TEST(multiset_test, copy_operator_03) {
  s21::multiset<int> multiset_1({1, 2, 2});
  s21::multiset<int> multiset_2({11, 22, 33, 11});

  EXPECT_EQ(multiset_1.size(), 3);
  EXPECT_EQ(multiset_2.size(), 4);

  multiset_1 = multiset_2;
  EXPECT_EQ(multiset_1.size(), 4);
  EXPECT_EQ(multiset_2.size(), 4);

  auto it = multiset_1.begin();
  EXPECT_EQ(*it, 11);
  ++it;
  EXPECT_EQ(*it, 11);
  ++it;
  EXPECT_EQ(*it, 22);
  ++it;
  EXPECT_EQ(*it, 33);
  it = multiset_1.begin();
  auto it_2 = multiset_2.begin();
  for (; it != multiset_1.end(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(multiset_test, copy_operator_04) {
  s21::multiset<int> multiset_1({1, 2, 1});
  std::multiset<int> orignal_multiset_1({1, 2, 1});
  EXPECT_EQ(multiset_1.size(), 3);

  multiset_1 = multiset_1;
  orignal_multiset_1 = orignal_multiset_1;
  EXPECT_EQ(multiset_1.size(), 3);
  EXPECT_EQ(multiset_1.size(), orignal_multiset_1.size());
}

TEST(multiset_test, move_constr) {
  s21::multiset<int> multiset_1({5, 3, 1, 2, 2, 5});
  EXPECT_EQ(multiset_1.size(), 6);
  s21::multiset<int> multiset_2(std::move(multiset_1));

  EXPECT_EQ(multiset_1.size(), 0);
  EXPECT_EQ(multiset_2.size(), 6);

  std::multiset<int> orignal_multiset_1({5, 3, 1, 2, 2, 5});

  auto it = multiset_2.begin();
  EXPECT_EQ(*it, 1);
  ++it;
  EXPECT_EQ(*it, 2);
  ++it;
  EXPECT_EQ(*it, 2);
  ++it;
  EXPECT_EQ(*it, 3);
  ++it;
  EXPECT_EQ(*it, 5);
  ++it;
  EXPECT_EQ(*it, 5);

  it = multiset_2.begin();
  auto it_2 = orignal_multiset_1.begin();
  for (; it != multiset_2.end(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(multiset_test, constr_move_to_yourself) {
  s21::multiset<char> multiset_1(std::move(multiset_1));
  EXPECT_EQ(multiset_1.size(), 0);
}

TEST(multiset_test, move_operator) {
  s21::multiset<int> multiset_1({1, 2, 2});
  EXPECT_EQ(multiset_1.size(), 3);
  s21::multiset<int> multiset_2({11, 22, 33, 11});
  EXPECT_EQ(multiset_2.size(), 4);

  multiset_1 = std::move(multiset_2);

  EXPECT_EQ(multiset_1.size(), 4);
  EXPECT_EQ(multiset_2.size(), 0);

  auto it = multiset_1.begin();
  EXPECT_EQ(*it, 11);
  ++it;
  EXPECT_EQ(*it, 11);
  ++it;
  EXPECT_EQ(*it, 22);
  ++it;
  EXPECT_EQ(*it, 33);
}

TEST(multiset_test, move_operator_05) {
  s21::multiset<int> multiset_1({5, 3, 1, 2, 2, 2});
  s21::multiset<int> multiset_2({11, 22, 33, 11});

  EXPECT_EQ(multiset_1.size(), 6);
  EXPECT_EQ(multiset_2.size(), 4);

  std::multiset<int> orignal_multiset_1({5, 3, 1, 2, 2, 2});
  std::multiset<int> orignal_multiset_2({11, 22, 33, 11});

  multiset_2 = std::move(multiset_1);
  orignal_multiset_2 = std::move(orignal_multiset_1);

  s21::multiset<int>::iterator it = multiset_2.begin();
  EXPECT_EQ(*it, 1);
  ++it;
  EXPECT_EQ(*it, 2);
  ++it;
  EXPECT_EQ(*it, 2);
  ++it;
  EXPECT_EQ(*it, 2);
  ++it;
  EXPECT_EQ(*it, 3);
  ++it;
  EXPECT_EQ(*it, 5);

  it = multiset_2.begin();
  auto it_2 = orignal_multiset_2.begin();
  for (; it != multiset_2.end() && it_2 != orignal_multiset_2.end(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }

  EXPECT_EQ(multiset_2.size(), orignal_multiset_2.size());
  EXPECT_EQ(multiset_1.size(), orignal_multiset_1.size());
}

TEST(multiset_test, move_operator_02) {
  s21::multiset<int> multiset_1({1, 2, 1});
  EXPECT_EQ(multiset_1.size(), 3);
  s21::multiset<int> multiset_2({11, 22, 33, 11});
  EXPECT_EQ(multiset_2.size(), 4);

  multiset_2 = std::move(multiset_1);

  EXPECT_EQ(multiset_1.size(), 0);
  EXPECT_EQ(multiset_2.size(), 3);

  auto it = multiset_2.begin();
  EXPECT_EQ(*it, 1);
  ++it;
  EXPECT_EQ(*it, 1);
  ++it;
  EXPECT_EQ(*it, 2);
}

TEST(multiset_test, move_operator_to_yourself) {
  s21::multiset<int> multiset_1({1, 2, 1});
  std::multiset<int> orignal_multiset_1({1, 2, 1});
  EXPECT_EQ(multiset_1.size(), 3);

  multiset_1 = std::move(multiset_1);

  orignal_multiset_1 = std::move(orignal_multiset_1);

  EXPECT_EQ(multiset_1.size(), 0);
  EXPECT_EQ(orignal_multiset_1.size(), 0);
  EXPECT_EQ(multiset_1.size(), orignal_multiset_1.size());
}

TEST(multiset_test, move_operator_03) {
  s21::multiset<int> multiset_1;
  EXPECT_EQ(multiset_1.size(), 0);
  s21::multiset<int> multiset_2;
  EXPECT_EQ(multiset_2.size(), 0);

  multiset_2 = std::move(multiset_1);

  EXPECT_EQ(multiset_1.size(), 0);
  EXPECT_EQ(multiset_2.size(), 0);
}

TEST(multiset_test, move_operator_04) {
  s21::multiset<int> multiset_1({1, 2});
  EXPECT_EQ(multiset_1.size(), 2);
  s21::multiset<int> multiset_2;
  EXPECT_EQ(multiset_2.size(), 0);

  multiset_1 = std::move(multiset_2);

  EXPECT_EQ(multiset_1.size(), 0);
  EXPECT_EQ(multiset_2.size(), 0);
}

TEST(multiset_test, test_empty) {
  s21::multiset<int> multiset_1({2, 4, 6, 8});
  s21::multiset<int> multiset_2;

  EXPECT_EQ(multiset_1.empty(), false);
  EXPECT_EQ(multiset_2.empty(), true);
}

TEST(multiset_test, test_size) {
  s21::multiset<double> multiset_1({1.1, 2.2, 3.3, 4.4, 5.5, 1.1, 5.5});
  std::multiset<double> orignal_multiset_1({1.1, 2.2, 3.3, 4.4, 5.5, 1.1, 5.5});
  EXPECT_EQ(multiset_1.size(), 7);
  EXPECT_EQ(multiset_1.size(), orignal_multiset_1.size());
}

TEST(multiset_test, test_clear) {
  s21::multiset<int> multiset_1({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12});
  s21::multiset<int> multiset_2({1});
  s21::multiset<int> multiset_3;
  EXPECT_EQ(multiset_1.size(), 12);
  EXPECT_EQ(multiset_2.size(), 1);
  EXPECT_EQ(multiset_3.size(), 0);

  multiset_1.clear();
  multiset_2.clear();
  multiset_3.clear();

  EXPECT_EQ(multiset_1.size(), 0);
  EXPECT_EQ(multiset_2.size(), 0);
  EXPECT_EQ(multiset_3.size(), 0);
}

TEST(multiset_test, test_insert) {
  s21::multiset<double> multiset_1({1.1, 2.2, 3.3, 4.4, 5.5, 5.5, 1.1});
  std::multiset<double> orignal_multiset_1({1.1, 2.2, 3.3, 4.4, 5.5, 5.5, 1.1});
  EXPECT_EQ(multiset_1.size(), 7);

  auto res_test_1 = multiset_1.insert(3.2);
  EXPECT_DOUBLE_EQ(res_test_1.operator*(), 3.2);

  auto res_orignal_multiset_1 = orignal_multiset_1.insert(3.2);
  EXPECT_DOUBLE_EQ(res_test_1.operator*(), res_orignal_multiset_1.operator*());

  EXPECT_EQ(multiset_1.size(), 8);
  EXPECT_EQ(multiset_1.size(), orignal_multiset_1.size());
  auto it = multiset_1.begin();
  auto it_2 = orignal_multiset_1.begin();
  for (; it != multiset_1.end(); ++it) {
    EXPECT_DOUBLE_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(multiset_test, test_insert_02) {
  s21::multiset<double> multiset_1({1.1, 2.2, 3.3, 4.4, 5.5, 5.5, 1.1});
  std::multiset<double> orignal_multiset_1({1.1, 2.2, 3.3, 4.4, 5.5, 5.5, 1.1});
  EXPECT_EQ(multiset_1.size(), 7);

  auto res_test_1 = multiset_1.insert(3.3);
  EXPECT_DOUBLE_EQ(res_test_1.operator*(), 3.3);

  auto res_orignal_multiset_1 = orignal_multiset_1.insert(3.3);
  EXPECT_DOUBLE_EQ(res_test_1.operator*(), res_orignal_multiset_1.operator*());

  EXPECT_EQ(multiset_1.size(), 8);
  EXPECT_EQ(multiset_1.size(), orignal_multiset_1.size());
  auto it = multiset_1.begin();
  auto it_2 = orignal_multiset_1.begin();
  for (; it != multiset_1.end(); ++it) {
    EXPECT_DOUBLE_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(multiset_test, test_insert_03) {
  s21::multiset<double> multiset_1;
  std::multiset<double> orignal_multiset_1;
  EXPECT_EQ(multiset_1.size(), 0);

  auto res_test_1 = multiset_1.insert(3.2);
  EXPECT_DOUBLE_EQ(res_test_1.operator*(), 3.2);

  auto res_orignal_multiset_1 = orignal_multiset_1.insert(3.2);
  EXPECT_DOUBLE_EQ(res_test_1.operator*(), res_orignal_multiset_1.operator*());

  EXPECT_EQ(multiset_1.size(), 1);
  EXPECT_EQ(multiset_1.size(), orignal_multiset_1.size());

  auto it = multiset_1.begin();
  auto it_2 = orignal_multiset_1.begin();
  for (; it != multiset_1.end(); ++it) {
    EXPECT_DOUBLE_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(multiset_test, test_erase) {
  s21::multiset<int> multiset_1(
      {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 12, 1, 4, 5, 9, 9, 2, 3});
  std::multiset<int> orignal_multiset_1(
      {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 12, 1, 4, 5, 9, 9, 2, 3});

  EXPECT_EQ(multiset_1.size(), 20);
  EXPECT_EQ(multiset_1.size(), orignal_multiset_1.size());

  auto it = multiset_1.insert(9);
  auto it_2 = orignal_multiset_1.insert(9);
  EXPECT_EQ(multiset_1.size(), 21);
  EXPECT_EQ(multiset_1.size(), orignal_multiset_1.size());

  multiset_1.erase(it);
  orignal_multiset_1.erase(it_2);
  EXPECT_EQ(multiset_1.size(), 20);
  EXPECT_EQ(multiset_1.size(), orignal_multiset_1.size());

  it = multiset_1.begin();
  it_2 = orignal_multiset_1.begin();
  for (; it != multiset_1.end(); ++it) {
    EXPECT_DOUBLE_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(multiset_test, test_erase_03) {
  s21::multiset<int> multiset_1;
  std::multiset<int> orignal_multiset_1;

  EXPECT_EQ(multiset_1.size(), 0);
  EXPECT_EQ(multiset_1.size(), orignal_multiset_1.size());

  auto it = multiset_1.begin();

  multiset_1.erase(it);
  EXPECT_EQ(multiset_1.size(), 0);
}

TEST(multiset_test, test_swap) {
  s21::multiset<int> multiset_1({1, 3, 5});
  s21::multiset<int> multiset_2({2, 4, 6, 8});

  EXPECT_EQ(multiset_1.size(), 3);
  EXPECT_EQ(multiset_2.size(), 4);

  std::multiset<int> orignal_multiset_1({1, 3, 5});
  std::multiset<int> orignal_multiset_2({2, 4, 6, 8});

  multiset_1.swap(multiset_2);
  orignal_multiset_1.swap(orignal_multiset_2);

  EXPECT_EQ(multiset_1.size(), 4);
  EXPECT_EQ(multiset_2.size(), 3);
  EXPECT_EQ(multiset_1.size(), orignal_multiset_1.size());
  EXPECT_EQ(multiset_2.size(), orignal_multiset_2.size());

  auto it = multiset_1.begin();
  auto it_2 = orignal_multiset_1.begin();
  for (; it != multiset_1.end(); ++it) {
    EXPECT_DOUBLE_EQ((*it), (*it_2));
    ++it_2;
  }

  auto it_3 = multiset_2.begin();
  auto it_4 = orignal_multiset_2.begin();
  for (; it_3 != multiset_2.end(); ++it_3) {
    EXPECT_DOUBLE_EQ((*it_3), (*it_4));
    ++it_4;
  }
}

TEST(multiset_test, test_swap_yourself) {
  s21::multiset<int> set_1({1, 3, 5});

  EXPECT_EQ(set_1.size(), 3);

  std::multiset<int> orignal_multiset_1({1, 3, 5});

  set_1.swap(set_1);
  orignal_multiset_1.swap(orignal_multiset_1);

  EXPECT_EQ(set_1.size(), 3);
  EXPECT_EQ(set_1.size(), orignal_multiset_1.size());

  s21::multiset<int>::iterator it = set_1.begin();
  auto it_2 = orignal_multiset_1.begin();
  for (; it != set_1.end(); ++it) {
    EXPECT_DOUBLE_EQ((*it), (*it_2));
    ++it_2;
  }
}

TEST(multiset_test, test_merge) {
  s21::multiset<int> multiset_1({1, 3, 5, 5, 1});
  s21::multiset<int> multiset_2({2, 4, 6, 8, 4, 2});

  EXPECT_EQ(multiset_1.size(), 5);
  EXPECT_EQ(multiset_2.size(), 6);

  std::multiset<int> orignal_multiset_1({1, 3, 5, 5, 1, 2, 4, 6, 8, 4, 2});
  //  std::multiset<int> orignal_multiset_1({1, 3, 5});
  //  std::multiset<int> orignal_multiset_2({2, 4, 6, 8});
  //  std::merge(orignal_multiset_2.begin(), orignal_multiset_2.end(),
  //  orignal_multiset_1);

  multiset_1.merge(multiset_2);

  EXPECT_EQ(multiset_1.size(), 11);
  EXPECT_EQ(multiset_2.size(), 0);
  EXPECT_EQ(multiset_1.size(), orignal_multiset_1.size());

  auto it = multiset_1.begin();
  auto it_2 = orignal_multiset_1.begin();
  for (; it != multiset_1.end(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(multiset_test, test_merge_02) {
  s21::multiset<int> multiset_1({2, 4, 6, 8, 4, 2});
  s21::multiset<int> multiset_2({1, 3, 5, 5, 1});

  EXPECT_EQ(multiset_1.size(), 6);
  EXPECT_EQ(multiset_2.size(), 5);

  std::multiset<int> orignal_multiset_1({1, 3, 5, 5, 1, 2, 4, 6, 8, 4, 2});

  //  EXPECT_EQ(orignal_multiset_1.size(), 3);
  //  EXPECT_EQ(orignal_multiset_2.size(), 4);

  multiset_1.merge(multiset_2);

  EXPECT_EQ(multiset_1.size(), 11);
  EXPECT_EQ(multiset_2.size(), 0);
  EXPECT_EQ(multiset_1.size(), orignal_multiset_1.size());

  auto it = multiset_1.begin();
  auto it_2 = orignal_multiset_1.begin();
  for (; it != multiset_1.end(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(multiset_test, test_merge_03) {
  s21::multiset<int> multiset_1;
  s21::multiset<int> multiset_2({1, 3, 5, 5, 1});

  EXPECT_EQ(multiset_1.size(), 0);
  EXPECT_EQ(multiset_2.size(), 5);

  std::multiset<int> orignal_multiset_1({1, 3, 5, 5, 1});

  //  EXPECT_EQ(orignal_multiset_1.size(), 3);
  //  EXPECT_EQ(orignal_multiset_2.size(), 4);

  multiset_1.merge(multiset_2);

  EXPECT_EQ(multiset_1.size(), 5);
  EXPECT_EQ(multiset_2.size(), 0);
  EXPECT_EQ(multiset_1.size(), orignal_multiset_1.size());

  auto it = multiset_1.begin();
  auto it_2 = orignal_multiset_1.begin();
  for (; it != multiset_1.end(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(multiset_test, test_merge_04) {
  s21::multiset<int> multiset_1({2, 4, 6, 8, 4, 2});
  s21::multiset<int> multiset_2;

  EXPECT_EQ(multiset_1.size(), 6);
  EXPECT_EQ(multiset_2.size(), 0);

  std::multiset<int> orignal_multiset_1({2, 4, 6, 8, 4, 2});

  //  EXPECT_EQ(orignal_multiset_1.size(), 3);
  //  EXPECT_EQ(orignal_multiset_2.size(), 4);

  multiset_1.merge(multiset_2);

  EXPECT_EQ(multiset_1.size(), 6);
  EXPECT_EQ(multiset_2.size(), 0);
  EXPECT_EQ(multiset_1.size(), orignal_multiset_1.size());

  auto it = multiset_1.begin();
  auto it_2 = orignal_multiset_1.begin();
  for (; it != multiset_1.end(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(multiset_test, test_merge_05) {
  s21::multiset<int> multiset_1;
  s21::multiset<int> multiset_2;

  EXPECT_EQ(multiset_1.size(), 0);
  EXPECT_EQ(multiset_2.size(), 0);

  std::multiset<int> orignal_multiset_1;

  //  EXPECT_EQ(orignal_multiset_1.size(), 3);
  //  EXPECT_EQ(orignal_multiset_2.size(), 4);

  multiset_1.merge(multiset_2);

  EXPECT_EQ(multiset_1.size(), 0);
  EXPECT_EQ(multiset_2.size(), 0);
  EXPECT_EQ(multiset_1.size(), orignal_multiset_1.size());

  auto it = multiset_1.begin();
  auto it_2 = orignal_multiset_1.begin();
  for (; it != multiset_1.end(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(multiset_test, test_merge_06) {
  s21::multiset<int> multiset_1;
  s21::multiset<int> multiset_2;

  EXPECT_EQ(multiset_1.size(), 0);
  EXPECT_EQ(multiset_2.size(), 0);

  std::multiset<int> orignal_multiset_1;

  //  EXPECT_EQ(orignal_multiset_1.size(), 3);
  //  EXPECT_EQ(orignal_multiset_2.size(), 4);

  multiset_1.merge(multiset_1);
  multiset_2.merge(multiset_2);

  EXPECT_EQ(multiset_1.size(), 0);
  EXPECT_EQ(multiset_2.size(), 0);
  EXPECT_EQ(multiset_1.size(), orignal_multiset_1.size());

  auto it = multiset_1.begin();
  auto it_2 = orignal_multiset_1.begin();
  for (; it != multiset_1.end(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(multiset_test, test_contains) {
  s21::multiset<double> multiset_1({1.1, 2.2, 3.3, 4.4, 5.5, 3.3});
  s21::multiset<double> multiset_2;
  EXPECT_EQ(multiset_1.size(), 6);

  auto res_test_1 = multiset_1.contains(3.3);
  EXPECT_EQ(res_test_1, true);
  res_test_1 = multiset_1.contains(3.2);
  EXPECT_EQ(res_test_1, false);
  auto res_test_2 = multiset_2.contains(3.3);
  EXPECT_EQ(res_test_2, false);
}

TEST(multiset_test, test_find) {
  s21::multiset<double> multiset_1({1.1, 2.2, 3.3, 4.4, 5.5, 4.4, 1.1});
  std::multiset<double> orignal_multiset_1({1.1, 2.2, 3.3, 4.4, 5.5, 4.4, 1.1});
  EXPECT_EQ(multiset_1.size(), 7);

  auto res_test_1 = multiset_1.find(4.4);
  EXPECT_DOUBLE_EQ(res_test_1.operator*(), 4.4);
  auto orig_test_1 = orignal_multiset_1.find(4.4);
  EXPECT_DOUBLE_EQ(res_test_1.operator*(), orig_test_1.operator*());

  res_test_1 = multiset_1.find(3.2);
}

// TEST(multiset_test, test_find_02) {
//   s21::multiset<double> multiset_1;
//   EXPECT_EQ(multiset_1.size(), 0);

//   auto res_test_1 = multiset_1.find(4.4);
//   // EXPECT_DOUBLE_EQ(res_test_1.operator*(), 0);
// }

TEST(multiset_test, test_count) {
  s21::multiset<int> multiset_1({1, 1, 3, 4, 5, 6, 7, 8, 4, 10, 4, 12});
  std::multiset<int> orignal_multiset_1({1, 1, 3, 4, 5, 6, 7, 8, 4, 10, 4, 12});
  EXPECT_EQ(multiset_1.size(), 12);

  auto res_test_1 = multiset_1.count(4);
  EXPECT_EQ(res_test_1, 3);
  auto orig_test_1 = orignal_multiset_1.count(4);
  EXPECT_EQ(res_test_1, orig_test_1);

  res_test_1 = multiset_1.count(1);
  EXPECT_EQ(res_test_1, 2);
  orig_test_1 = orignal_multiset_1.count(1);
  EXPECT_EQ(res_test_1, orig_test_1);

  res_test_1 = multiset_1.count(50);
  EXPECT_EQ(res_test_1, 0);
  orig_test_1 = orignal_multiset_1.count(50);
  EXPECT_EQ(res_test_1, orig_test_1);
}

TEST(multiset_test, test_count_02) {
  s21::multiset<int> multiset_1;
  std::multiset<int> orignal_multiset_1;
  EXPECT_EQ(multiset_1.size(), 0);

  auto res_test_1 = multiset_1.count(4);
  EXPECT_EQ(res_test_1, 0);
  auto orig_test_1 = orignal_multiset_1.count(4);
  EXPECT_EQ(res_test_1, orig_test_1);

  res_test_1 = multiset_1.count(1);
  EXPECT_EQ(res_test_1, 0);
  orig_test_1 = orignal_multiset_1.count(1);
  EXPECT_EQ(res_test_1, orig_test_1);

  res_test_1 = multiset_1.count(0);
  EXPECT_EQ(res_test_1, 0);
  orig_test_1 = orignal_multiset_1.count(0);
  EXPECT_EQ(res_test_1, orig_test_1);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
