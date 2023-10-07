
#include <gtest/gtest.h>

#include <map>

#include "s21_map.h"

TEST(map_test, basic_constr) {
  s21::map<int, char> map_d;
  s21::map<double, char> map_i;
  s21::map<char, std::string> map_c;
  EXPECT_EQ(map_d.size(), 0);
  EXPECT_EQ(map_i.size(), 0);
  EXPECT_EQ(map_c.size(), 0);
}

TEST(map_test, constr_with_indefinite_number_of_elements) {
  s21::map<double, char> map_1({{1.1, 'a'},
                                {2.2, 'b'},
                                {3.3, 'c'},
                                {4.4, 'd'},
                                {5.5, 'e'},
                                {3.3, 'c'},
                                {4.4, 'd'},
                                {5.5, 'e'}});
  std::map<double, char> orignal_map_1({{1.1, 'a'},
                                        {2.2, 'b'},
                                        {3.3, 'c'},
                                        {4.4, 'd'},
                                        {5.5, 'e'},
                                        {3.3, 'c'},
                                        {4.4, 'd'},
                                        {5.5, 'e'}});
  EXPECT_EQ(map_1.size(), 5);
  auto it = map_1.begin();
  EXPECT_EQ((*it).first, 1.1);
  EXPECT_EQ((*it).second, 'a');
  ++it;
  EXPECT_EQ((*it).first, 2.2);
  EXPECT_EQ((*it).second, 'b');
  ++it;
  EXPECT_EQ((*it).first, 3.3);
  EXPECT_EQ((*it).second, 'c');
  ++it;
  EXPECT_EQ((*it).first, 4.4);
  EXPECT_EQ((*it).second, 'd');
  ++it;
  EXPECT_EQ((*it).first, 5.5);
  EXPECT_EQ((*it).second, 'e');

  it = map_1.begin();
  auto it_2 = orignal_map_1.begin();
  for (; it != map_1.end(); ++it) {
    EXPECT_EQ((*it).first, (*it_2).first);
    EXPECT_EQ((*it).second, (*it_2).second);
    ++it_2;
  }
}

TEST(map_test, constr_with_indefinite_number_of_elements_string) {
  s21::map<double, std::string> map_1(
      {{5, "apple"},  {3, "banana"},      {10, "orange"},  {2, "grape"},
       {7, "dog"},    {1, "cat"},         {8, "elephant"}, {4, "giraffe"},
       {2, "zebra"},  {6, "lion"},        {3, "cherry"},   {9, "peach"},
       {4, "pear"},   {11, "watermelon"}, {1, "turtle"},   {12, "frog"},
       {6, "spider"}, {15, "snake"},      {13, "koala"},   {16, "monkey"}});
  std::map<double, std::string> orignal_map_1(
      {{5, "apple"},  {3, "banana"},      {10, "orange"},  {2, "grape"},
       {7, "dog"},    {1, "cat"},         {8, "elephant"}, {4, "giraffe"},
       {2, "zebra"},  {6, "lion"},        {3, "cherry"},   {9, "peach"},
       {4, "pear"},   {11, "watermelon"}, {1, "turtle"},   {12, "frog"},
       {6, "spider"}, {15, "snake"},      {13, "koala"},   {16, "monkey"}});
  EXPECT_EQ(map_1.size(), 15);
  EXPECT_EQ(map_1.size(), orignal_map_1.size());
  auto it = map_1.begin();
  auto it_2 = orignal_map_1.begin();
  for (; it != map_1.end(); ++it) {
    EXPECT_EQ((*it).first, (*it_2).first);
    EXPECT_EQ((*it).second, (*it_2).second);
    ++it_2;
  }
}

TEST(map_test, copy_constr) {
  s21::map<double, char> map_1(
      {{1.1, 'a'}, {2.2, 'b'}, {3.3, 'c'}, {4.4, 'd'}, {5.5, 'e'}});
  EXPECT_EQ(map_1.size(), 5);
  s21::map<double, char> map_2(map_1);

  EXPECT_EQ(map_1.size(), 5);
  EXPECT_EQ(map_2.size(), 5);

  auto it = map_1.begin();
  auto it_2 = map_2.begin();
  for (; it != map_1.end(); ++it) {
    EXPECT_EQ((*it).first, (*it_2).first);
    EXPECT_EQ((*it).second, (*it_2).second);
    ++it_2;
  }
}

TEST(map_test, copy_operator_01) {
  s21::map<double, char> map_1(
      {{1.1, 'a'}, {2.2, 'b'}, {3.3, 'c'}, {4.4, 'd'}, {5.5, 'e'}});
  EXPECT_EQ(map_1.size(), 5);
  s21::map<double, char> map_2(
      {{1.5, 's'}, {2.9, 'a'}, {3.5, 'c'}, {0.4, 'o'}, {0.5, 'e'}});
  EXPECT_EQ(map_2.size(), 5);

  map_1 = map_2;
  EXPECT_EQ(map_1.size(), 5);
  EXPECT_EQ(map_2.size(), 5);
  auto it = map_1.begin();
  auto it_2 = map_2.begin();
  for (; it != map_1.end(); ++it) {
    EXPECT_EQ((*it).first, (*it_2).first);
    EXPECT_EQ((*it).second, (*it_2).second);
    ++it_2;
  }
}

TEST(map_test, copy_operator_02) {
  s21::map<double, char> map_1;
  EXPECT_EQ(map_1.size(), 0);
  s21::map<double, char> map_2;
  EXPECT_EQ(map_2.size(), 0);

  map_1 = map_2;
  EXPECT_EQ(map_1.size(), 0);
  EXPECT_EQ(map_2.size(), 0);
  auto it = map_1.begin();
  auto it_2 = map_2.begin();
  for (; it != map_1.end(); ++it) {
    EXPECT_EQ((*it).first, (*it_2).first);
    EXPECT_EQ((*it).second, (*it_2).second);
    ++it_2;
  }
}

TEST(map_test, copy_operator_06) {
  s21::map<double, char> map_1(
      {{1.1, 'a'}, {2.2, 'b'}, {1.1, 'a'}, {2.2, 'b'}});
  s21::map<double, char> map_2;

  EXPECT_EQ(map_1.size(), 2);

  map_1 = map_2;
  EXPECT_EQ(map_1.size(), 0);
  EXPECT_EQ(map_2.size(), 0);
}

TEST(map_test, copy_operator_05) {
  s21::map<double, char> map_1;
  s21::map<double, char> map_2;

  EXPECT_EQ(map_1.size(), 0);

  map_1 = map_2;
  EXPECT_EQ(map_1.size(), 0);
  EXPECT_EQ(map_2.size(), 0);
}

TEST(map_test, copy_operator_03) {
  s21::map<double, char> map_1({{1.1, 'a'}, {2.2, 'b'}});
  s21::map<double, char> map_2({{11, 'a'}, {22, 'b'}, {33, 'b'}});

  EXPECT_EQ(map_1.size(), 2);
  EXPECT_EQ(map_2.size(), 3);

  map_1 = map_2;
  EXPECT_EQ(map_1.size(), 3);
  EXPECT_EQ(map_2.size(), 3);

  auto it = map_1.begin();
  EXPECT_EQ((*it).first, 11);
  EXPECT_EQ((*it).second, 'a');
  ++it;
  EXPECT_EQ((*it).first, 22);
  EXPECT_EQ((*it).second, 'b');
  ++it;
  EXPECT_EQ((*it).first, 33);
  EXPECT_EQ((*it).second, 'b');
  it = map_1.begin();
  auto it_2 = map_2.begin();
  for (; it != map_1.end(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(map_test, copy_operator_04) {
  s21::map<double, char> map_1({{1.1, 'a'}, {2.2, 'b'}});

  EXPECT_EQ(map_1.size(), 2);

  map_1 = map_1;
  EXPECT_EQ(map_1.size(), 2);
}

TEST(map_test, move_constr) {
  s21::map<double, char> map_1(
      {{1.5, 's'}, {2.9, 'a'}, {3.5, 'c'}, {0.4, 'o'}, {0.5, 'e'}});
  EXPECT_EQ(map_1.size(), 5);
  s21::map<double, char> map_2(std::move(map_1));

  EXPECT_EQ(map_1.size(), 0);
  EXPECT_EQ(map_2.size(), 5);

  std::map<double, char> orignal_list_1(
      {{1.5, 's'}, {2.9, 'a'}, {3.5, 'c'}, {0.4, 'o'}, {0.5, 'e'}});

  auto it = map_2.begin();
  EXPECT_DOUBLE_EQ((*it).first, 0.4);
  EXPECT_EQ((*it).second, 'o');
  ++it;
  EXPECT_DOUBLE_EQ((*it).first, 0.5);
  EXPECT_EQ((*it).second, 'e');
  ++it;
  EXPECT_DOUBLE_EQ((*it).first, 1.5);
  EXPECT_EQ((*it).second, 's');
  ++it;
  EXPECT_DOUBLE_EQ((*it).first, 2.9);
  EXPECT_EQ((*it).second, 'a');
  ++it;
  EXPECT_DOUBLE_EQ((*it).first, 3.5);
  EXPECT_EQ((*it).second, 'c');

  it = map_2.begin();
  auto it_2 = orignal_list_1.begin();
  for (; it != map_2.end(); ++it) {
    EXPECT_DOUBLE_EQ((*it).first, (*it_2).first);
    EXPECT_EQ((*it).second, (*it_2).second);
    ++it_2;
  }
}

TEST(map_test, move_constr_empty) {
  s21::map<double, char> map_1;
  EXPECT_EQ(map_1.size(), 0);
  s21::map<double, char> map_2(std::move(map_1));

  EXPECT_EQ(map_1.size(), 0);
  EXPECT_EQ(map_2.size(), 0);
}

TEST(map_test, constr_move_to_yourself) {
  s21::map<double, char> map_1(std::move(map_1));
  EXPECT_EQ(map_1.size(), 0);
}

TEST(map_test, move_operator) {
  s21::map<double, char> map_1({{1.1, 'a'}, {2.2, 'b'}});
  EXPECT_EQ(map_1.size(), 2);
  s21::map<double, char> map_2({{11, 'a'}, {22, 'b'}, {33, 'b'}});
  EXPECT_EQ(map_2.size(), 3);

  map_1 = std::move(map_2);

  EXPECT_EQ(map_1.size(), 3);
  EXPECT_EQ(map_2.size(), 0);

  auto it = map_1.begin();
  EXPECT_EQ((*it).first, 11);
  EXPECT_EQ((*it).second, 'a');
  ++it;
  EXPECT_EQ((*it).first, 22);
  EXPECT_EQ((*it).second, 'b');
  ++it;
  EXPECT_EQ((*it).first, 33);
  EXPECT_EQ((*it).second, 'b');
}

TEST(map_test, move_operator_02) {
  s21::map<double, char> map_1({{1.1, 'a'}, {2.2, 'b'}});
  EXPECT_EQ(map_1.size(), 2);
  s21::map<double, char> map_2({{11, 'a'}, {22, 'b'}, {33, 'b'}});
  EXPECT_EQ(map_2.size(), 3);

  map_2 = std::move(map_1);

  EXPECT_EQ(map_1.size(), 0);
  EXPECT_EQ(map_2.size(), 2);

  auto it = map_2.begin();
  EXPECT_EQ((*it).first, 1.1);
  EXPECT_EQ((*it).second, 'a');
  ++it;
  EXPECT_EQ((*it).first, 2.2);
  EXPECT_EQ((*it).second, 'b');
}

TEST(map_test, move_operator_05) {
  s21::map<double, char> map_1({{1.1, 'a'}, {2.2, 'b'}});
  EXPECT_EQ(map_1.size(), 2);
  s21::map<double, char> map_2({{11, 'a'}, {22, 'b'}, {33, 'b'}});
  EXPECT_EQ(map_2.size(), 3);

  std::map<double, char> original_map_1({{1.1, 'a'}, {2.2, 'b'}});
  EXPECT_EQ(map_1.size(), 2);
  std::map<double, char> original_map_2({{11, 'a'}, {22, 'b'}, {33, 'b'}});
  map_2 = std::move(map_1);
  original_map_2 = std::move(original_map_1);

  EXPECT_EQ(map_1.size(), 0);
  EXPECT_EQ(map_2.size(), 2);
  EXPECT_EQ(map_1.size(), original_map_1.size());
  EXPECT_EQ(map_2.size(), original_map_2.size());

  auto it = map_2.begin();
  EXPECT_EQ((*it).first, 1.1);
  EXPECT_EQ((*it).second, 'a');
  ++it;
  EXPECT_EQ((*it).first, 2.2);
  EXPECT_EQ((*it).second, 'b');
  it = map_2.begin();
  auto it_2 = original_map_2.begin();
  for (; it != map_2.end(); ++it) {
    EXPECT_DOUBLE_EQ((*it).first, (*it_2).first);
    EXPECT_EQ((*it).second, (*it_2).second);
    ++it_2;
  }
}

TEST(map_test, move_operator_to_yourself) {
  s21::map<double, char> map_1({{1.1, 'a'}, {2.2, 'b'}});
  EXPECT_EQ(map_1.size(), 2);
  map_1 = std::move(map_1);
  EXPECT_EQ(map_1.size(), 0);
}

TEST(map_test, move_operator_03) {
  s21::map<double, char> map_1;
  EXPECT_EQ(map_1.size(), 0);
  s21::map<double, char> map_2;
  EXPECT_EQ(map_2.size(), 0);

  map_2 = std::move(map_1);

  EXPECT_EQ(map_1.size(), 0);
  EXPECT_EQ(map_2.size(), 0);
}

TEST(map_test, move_operator_04) {
  s21::map<double, char> map_1({{1.1, 'a'}, {2.2, 'b'}});
  EXPECT_EQ(map_1.size(), 2);
  s21::map<double, char> map_2;
  EXPECT_EQ(map_2.size(), 0);

  map_1 = std::move(map_2);

  EXPECT_EQ(map_1.size(), 0);
  EXPECT_EQ(map_2.size(), 0);
}

TEST(map_test, test_size) {
  s21::map<double, char> map_1(
      {{1.5, 's'}, {2.9, 'a'}, {3.5, 'c'}, {0.4, 'o'}, {0.5, 'e'}});
  std::map<double, char> orignal_map_1(
      {{1.5, 's'}, {2.9, 'a'}, {3.5, 'c'}, {0.4, 'o'}, {0.5, 'e'}});
  EXPECT_EQ(map_1.size(), 5);
  EXPECT_EQ(map_1.size(), orignal_map_1.size());
}

TEST(map_test, test_merge) {
  s21::map<int, char> map_1({{1, 'a'}, {3, 'b'}, {5, 'b'}});
  s21::map<int, char> map_2({{2, 'l'}, {4, 'o'}, {6, 'b'}, {8, 's'}});

  EXPECT_EQ(map_1.size(), 3);
  EXPECT_EQ(map_2.size(), 4);

  std::map<int, char> orignal_map_1(
      {{1, 'a'}, {3, 'b'}, {5, 'b'}, {2, 'l'}, {4, 'o'}, {6, 'b'}, {8, 's'}});

  map_1.merge(map_2);

  EXPECT_EQ(map_1.size(), 7);
  EXPECT_EQ(map_2.size(), 0);
  EXPECT_EQ(map_1.size(), orignal_map_1.size());

  auto it = map_1.begin();
  auto it_2 = orignal_map_1.begin();
  for (; it != map_1.end(); ++it) {
    EXPECT_DOUBLE_EQ((*it).first, (*it_2).first);
    EXPECT_EQ((*it).second, (*it_2).second);
    ++it_2;
  }
}

TEST(map_test, test_merge_02) {
  s21::map<int, char> map_1({{2, 'l'}, {4, 'o'}, {6, 'b'}, {8, 's'}});
  s21::map<int, char> map_2({{1, 'a'}, {3, 'b'}, {5, 'b'}});

  EXPECT_EQ(map_1.size(), 4);
  EXPECT_EQ(map_2.size(), 3);

  std::map<int, char> orignal_map_1(
      {{1, 'a'}, {3, 'b'}, {5, 'b'}, {2, 'l'}, {4, 'o'}, {6, 'b'}, {8, 's'}});

  map_1.merge(map_2);

  EXPECT_EQ(map_1.size(), 7);
  EXPECT_EQ(map_2.size(), 0);
  EXPECT_EQ(map_1.size(), orignal_map_1.size());

  auto it = map_1.begin();
  auto it_2 = orignal_map_1.begin();
  for (; it != map_1.end(); ++it) {
    EXPECT_DOUBLE_EQ((*it).first, (*it_2).first);
    EXPECT_EQ((*it).second, (*it_2).second);
    ++it_2;
  }
}

TEST(map_test, test_merge_03) {
  s21::map<int, char> map_1;
  s21::map<int, char> map_2({{1, 'a'}, {3, 'b'}, {5, 'b'}});

  EXPECT_EQ(map_1.size(), 0);
  EXPECT_EQ(map_2.size(), 3);

  std::map<int, char> orignal_map_1({{1, 'a'}, {3, 'b'}, {5, 'b'}});

  //  EXPECT_EQ(orignal_map_1.size(), 3);
  //  EXPECT_EQ(orignal_set_2.size(), 4);

  map_1.merge(map_2);

  EXPECT_EQ(map_1.size(), 3);
  EXPECT_EQ(map_2.size(), 0);
  EXPECT_EQ(map_1.size(), orignal_map_1.size());

  auto it = map_1.begin();
  auto it_2 = orignal_map_1.begin();
  for (; it != map_1.end(); ++it) {
    EXPECT_DOUBLE_EQ((*it).first, (*it_2).first);
    EXPECT_EQ((*it).second, (*it_2).second);
    ++it_2;
  }
}

TEST(map_test, test_merge_04) {
  s21::map<int, char> map_1({{2, 'l'}, {4, 'o'}, {6, 'b'}, {8, 's'}});
  s21::map<int, char> map_2;

  EXPECT_EQ(map_1.size(), 4);
  EXPECT_EQ(map_2.size(), 0);

  std::map<int, char> orignal_map_1({{2, 'l'}, {4, 'o'}, {6, 'b'}, {8, 's'}});

  map_1.merge(map_2);

  EXPECT_EQ(map_1.size(), 4);
  EXPECT_EQ(map_2.size(), 0);
  EXPECT_EQ(map_1.size(), orignal_map_1.size());

  auto it = map_1.begin();
  auto it_2 = orignal_map_1.begin();
  for (; it != map_1.end(); ++it) {
    EXPECT_DOUBLE_EQ((*it).first, (*it_2).first);
    EXPECT_EQ((*it).second, (*it_2).second);
    ++it_2;
  }
}

TEST(map_test, test_empty) {
  s21::map<int, char> map_1({{2, 'l'}, {4, 'o'}, {6, 'b'}, {8, 's'}});
  s21::map<int, char> map_2;

  EXPECT_EQ(map_1.empty(), false);
  EXPECT_EQ(map_2.empty(), true);
}

TEST(map_test, test_insert) {
  s21::map<double, char> map_1(
      {{1.1, 'a'}, {2.2, 'b'}, {3.3, 'c'}, {4.4, 'd'}, {5.5, 'e'}});
  std::map<double, char> orignal_map_1(
      {{1.1, 'a'}, {2.2, 'b'}, {3.3, 'c'}, {4.4, 'd'}, {5.5, 'e'}});
  EXPECT_EQ(map_1.size(), 5);

  auto res_test_1 = map_1.insert({3.2, 'b'});
  EXPECT_EQ(res_test_1.second, true);
  EXPECT_DOUBLE_EQ(res_test_1.first.operator*().first, 3.2);
  EXPECT_DOUBLE_EQ(res_test_1.first.operator*().second, 'b');

  auto res_orignal_set_1 = orignal_map_1.insert({3.2, 'b'});
  EXPECT_EQ(res_test_1.second, res_orignal_set_1.second);
  EXPECT_DOUBLE_EQ(res_test_1.first.operator*().first,
                   res_orignal_set_1.first.operator*().first);
  EXPECT_EQ(res_test_1.first.operator*().second,
            res_orignal_set_1.first.operator*().second);

  auto it = map_1.begin();
  auto it_2 = orignal_map_1.begin();
  for (; it != map_1.end(); ++it) {
    EXPECT_DOUBLE_EQ((*it).first, (*it_2).first);
    EXPECT_EQ((*it).second, (*it_2).second);
    ++it_2;
  }
}

TEST(map_test, test_insert_02) {
  s21::map<double, char> map_1(
      {{1.1, 'a'}, {2.2, 'b'}, {3.3, 'c'}, {4.4, 'd'}, {5.5, 'e'}});
  std::map<double, char> orignal_map_1(
      {{1.1, 'a'}, {2.2, 'b'}, {3.3, 'c'}, {4.4, 'd'}, {5.5, 'e'}});
  EXPECT_EQ(map_1.size(), 5);

  auto res_test_1 = map_1.insert({3.3, 'b'});
  EXPECT_EQ(res_test_1.second, false);
  EXPECT_DOUBLE_EQ(res_test_1.first.operator*().first, 3.3);
  EXPECT_DOUBLE_EQ(res_test_1.first.operator*().second, 'c');

  auto res_orignal_set_1 = orignal_map_1.insert({3.3, 'b'});
  EXPECT_EQ(res_test_1.second, res_orignal_set_1.second);
  EXPECT_DOUBLE_EQ(res_test_1.first.operator*().first,
                   res_orignal_set_1.first.operator*().first);
  EXPECT_EQ(res_test_1.first.operator*().second,
            res_orignal_set_1.first.operator*().second);

  auto it = map_1.begin();
  auto it_2 = orignal_map_1.begin();
  for (; it != map_1.end(); ++it) {
    EXPECT_DOUBLE_EQ((*it).first, (*it_2).first);
    EXPECT_EQ((*it).second, (*it_2).second);
    ++it_2;
  }
}

TEST(map_test, test_insert_03) {
  s21::map<double, char> map_1;
  std::map<double, char> orignal_map_1;
  EXPECT_EQ(map_1.size(), 0);

  auto res_test_1 = map_1.insert({3.2, 'b'});
  EXPECT_EQ(res_test_1.second, true);
  EXPECT_DOUBLE_EQ(res_test_1.first.operator*().first, 3.2);
  EXPECT_DOUBLE_EQ(res_test_1.first.operator*().second, 'b');

  auto res_orignal_set_1 = orignal_map_1.insert({3.2, 'b'});
  EXPECT_EQ(res_test_1.second, res_orignal_set_1.second);
  EXPECT_DOUBLE_EQ(res_test_1.first.operator*().first,
                   res_orignal_set_1.first.operator*().first);
  EXPECT_EQ(res_test_1.first.operator*().second,
            res_orignal_set_1.first.operator*().second);

  auto it = map_1.begin();
  auto it_2 = orignal_map_1.begin();
  for (; it != map_1.end(); ++it) {
    EXPECT_DOUBLE_EQ((*it).first, (*it_2).first);
    EXPECT_EQ((*it).second, (*it_2).second);
    ++it_2;
  }
}

TEST(map_test, test_insert_04) {
  s21::map<double, char> map_1(
      {{1.1, 'a'}, {2.2, 'b'}, {3.3, 'c'}, {4.4, 'd'}, {5.5, 'e'}});
  std::map<double, char> orignal_map_1(
      {{1.1, 'a'}, {2.2, 'b'}, {3.3, 'c'}, {4.4, 'd'}, {5.5, 'e'}});
  EXPECT_EQ(map_1.size(), 5);

  auto res_test_1 = map_1.insert(3.2, 'b');
  EXPECT_EQ(res_test_1.second, true);
  EXPECT_DOUBLE_EQ(res_test_1.first.operator*().first, 3.2);
  EXPECT_DOUBLE_EQ(res_test_1.first.operator*().second, 'b');

  auto res_orignal_set_1 = orignal_map_1.insert({3.2, 'b'});
  EXPECT_EQ(res_test_1.second, res_orignal_set_1.second);
  EXPECT_DOUBLE_EQ(res_test_1.first.operator*().first,
                   res_orignal_set_1.first.operator*().first);
  EXPECT_EQ(res_test_1.first.operator*().second,
            res_orignal_set_1.first.operator*().second);

  auto it = map_1.begin();
  auto it_2 = orignal_map_1.begin();
  for (; it != map_1.end(); ++it) {
    EXPECT_DOUBLE_EQ((*it).first, (*it_2).first);
    EXPECT_EQ((*it).second, (*it_2).second);
    ++it_2;
  }
}

TEST(map_test, test_insert_05) {
  s21::map<double, char> map_1(
      {{1.1, 'a'}, {2.2, 'b'}, {3.3, 'c'}, {4.4, 'd'}, {5.5, 'e'}});
  std::map<double, char> orignal_map_1(
      {{1.1, 'a'}, {2.2, 'b'}, {3.3, 'c'}, {4.4, 'd'}, {5.5, 'e'}});
  EXPECT_EQ(map_1.size(), 5);

  auto res_test_1 = map_1.insert(3.3, 'b');
  EXPECT_EQ(res_test_1.second, false);
  EXPECT_DOUBLE_EQ(res_test_1.first.operator*().first, 3.3);
  EXPECT_DOUBLE_EQ(res_test_1.first.operator*().second, 'c');

  auto res_orignal_set_1 = orignal_map_1.insert({3.3, 'b'});
  EXPECT_EQ(res_test_1.second, res_orignal_set_1.second);
  EXPECT_DOUBLE_EQ(res_test_1.first.operator*().first,
                   res_orignal_set_1.first.operator*().first);
  EXPECT_EQ(res_test_1.first.operator*().second,
            res_orignal_set_1.first.operator*().second);

  auto it = map_1.begin();
  auto it_2 = orignal_map_1.begin();
  for (; it != map_1.end(); ++it) {
    EXPECT_DOUBLE_EQ((*it).first, (*it_2).first);
    EXPECT_EQ((*it).second, (*it_2).second);
    ++it_2;
  }
}

TEST(map_test, test_insert_06) {
  s21::map<double, char> map_1;
  std::map<double, char> orignal_map_1;
  EXPECT_EQ(map_1.size(), 0);

  auto res_test_1 = map_1.insert(3.2, 'b');
  EXPECT_EQ(res_test_1.second, true);
  EXPECT_DOUBLE_EQ(res_test_1.first.operator*().first, 3.2);
  EXPECT_DOUBLE_EQ(res_test_1.first.operator*().second, 'b');

  auto res_orignal_set_1 = orignal_map_1.insert({3.2, 'b'});
  EXPECT_EQ(res_test_1.second, res_orignal_set_1.second);
  EXPECT_DOUBLE_EQ(res_test_1.first.operator*().first,
                   res_orignal_set_1.first.operator*().first);
  EXPECT_EQ(res_test_1.first.operator*().second,
            res_orignal_set_1.first.operator*().second);

  auto it = map_1.begin();
  auto it_2 = orignal_map_1.begin();
  for (; it != map_1.end(); ++it) {
    EXPECT_DOUBLE_EQ((*it).first, (*it_2).first);
    EXPECT_EQ((*it).second, (*it_2).second);
    ++it_2;
  }
}

TEST(map_test, test_insert_or_assign) {
  s21::map<double, char> map_1(
      {{1.1, 'a'}, {2.2, 'b'}, {3.3, 'c'}, {4.4, 'd'}, {5.5, 'e'}});
  std::map<double, char> orignal_map_1(
      {{1.1, 'a'}, {2.2, 'b'}, {3.3, 'b'}, {4.4, 'd'}, {5.5, 'e'}});
  EXPECT_EQ(map_1.size(), 5);

  auto res_test_1 = map_1.insert_or_assign(3.3, 'b');
  EXPECT_EQ(res_test_1.second, false);
  EXPECT_DOUBLE_EQ(res_test_1.first.operator*().first, 3.3);
  EXPECT_DOUBLE_EQ(res_test_1.first.operator*().second, 'b');

  auto it = map_1.begin();
  auto it_2 = orignal_map_1.begin();
  for (; it != map_1.end(); ++it) {
    EXPECT_DOUBLE_EQ((*it).first, (*it_2).first);
    EXPECT_EQ((*it).second, (*it_2).second);
    ++it_2;
  }
}

TEST(map_test, test_insert_or_assign_02) {
  s21::map<double, char> map_1(
      {{1.1, 'a'}, {2.2, 'b'}, {3.3, 'c'}, {4.4, 'd'}, {5.5, 'e'}});
  std::map<double, char> orignal_map_1(
      {{1.1, 'a'}, {2.2, 'b'}, {3.3, 'c'}, {4.4, 'd'}, {5.5, 'e'}});
  EXPECT_EQ(map_1.size(), 5);

  auto res_test_1 = map_1.insert_or_assign(3.4, 'b');
  EXPECT_EQ(res_test_1.second, true);
  EXPECT_DOUBLE_EQ(res_test_1.first.operator*().first, 3.4);
  EXPECT_DOUBLE_EQ(res_test_1.first.operator*().second, 'b');

  auto res_orignal_set_1 = orignal_map_1.insert({3.4, 'b'});
  EXPECT_EQ(res_test_1.second, res_orignal_set_1.second);
  EXPECT_DOUBLE_EQ(res_test_1.first.operator*().first,
                   res_orignal_set_1.first.operator*().first);
  EXPECT_EQ(res_test_1.first.operator*().second,
            res_orignal_set_1.first.operator*().second);

  auto it = map_1.begin();
  auto it_2 = orignal_map_1.begin();
  for (; it != map_1.end(); ++it) {
    EXPECT_DOUBLE_EQ((*it).first, (*it_2).first);
    EXPECT_EQ((*it).second, (*it_2).second);
    ++it_2;
  }
}

TEST(map_test, test_insert_or_assign_03) {
  s21::map<double, char> map_1;
  std::map<double, char> orignal_map_1;
  EXPECT_EQ(map_1.size(), 0);

  auto res_test_1 = map_1.insert_or_assign(3.4, 'b');
  EXPECT_EQ(res_test_1.second, true);
  EXPECT_DOUBLE_EQ(res_test_1.first.operator*().first, 3.4);
  EXPECT_DOUBLE_EQ(res_test_1.first.operator*().second, 'b');

  auto res_orignal_set_1 = orignal_map_1.insert({3.4, 'b'});
  EXPECT_EQ(res_test_1.second, res_orignal_set_1.second);
  EXPECT_DOUBLE_EQ(res_test_1.first.operator*().first,
                   res_orignal_set_1.first.operator*().first);
  EXPECT_EQ(res_test_1.first.operator*().second,
            res_orignal_set_1.first.operator*().second);

  auto it = map_1.begin();
  auto it_2 = orignal_map_1.begin();
  for (; it != map_1.end(); ++it) {
    EXPECT_DOUBLE_EQ((*it).first, (*it_2).first);
    EXPECT_EQ((*it).second, (*it_2).second);
    ++it_2;
  }
}

// TEST(map_test, test_at) {
//     s21::map<double, char> map_1({{1.1, 'a'}, {2.2, 'b'}, {3.3, 'c'}, {4.4,
//     'd'}, {5.5, 'e'}}); s21::map<double, char> map_2; EXPECT_EQ(map_1.size(),
//     5);
//
//     auto res_test_1 = map_1.At(3.3);
//     EXPECT_EQ(res_test_1, 'c');
//     EXPECT_THROW(map_1.At(3.2), std::out_of_range);
//     EXPECT_THROW(map_2.At(3.3), std::out_of_range);
// }

TEST(map_test, test_operator_sq) {
  s21::map<double, char> map_1(
      {{1.1, 'a'}, {2.2, 'b'}, {3.3, 'c'}, {4.4, 'd'}, {5.5, 'e'}});
  std::map<double, char> orignal_map_1(
      {{1.1, 'a'}, {2.2, 'b'}, {3.3, 'c'}, {4.4, 'd'}, {5.5, 'e'}});
  EXPECT_EQ(map_1.size(), 5);

  EXPECT_EQ(map_1[4.4], 'd');
  EXPECT_EQ(orignal_map_1[4.4], map_1[4.4]);

  map_1[4.4] = 'a';
  orignal_map_1[4.4] = 'a';

  auto it = map_1.begin();
  auto it_2 = orignal_map_1.begin();
  for (; it != map_1.end(); ++it) {
    EXPECT_DOUBLE_EQ((*it).first, (*it_2).first);
    EXPECT_EQ((*it).second, (*it_2).second);
    ++it_2;
  }
}

TEST(map_test, test_operator_sq_02) {
  s21::map<double, char> map_1;
  std::map<double, char> orignal_map_1;
  EXPECT_EQ(map_1.size(), 0);

  EXPECT_EQ(orignal_map_1[4.4], map_1[4.4]);

  map_1[4.4] = 'a';
  orignal_map_1[4.4] = 'a';

  EXPECT_EQ(map_1[4.4], 'a');
  EXPECT_EQ(orignal_map_1[4.4], map_1[4.4]);

  auto it = map_1.begin();
  auto it_2 = orignal_map_1.begin();
  for (; it != map_1.end(); ++it) {
    EXPECT_DOUBLE_EQ((*it).first, (*it_2).first);
    EXPECT_EQ((*it).second, (*it_2).second);
    ++it_2;
  }
}

TEST(map_test, test_contains) {
  s21::map<double, char> map_1(
      {{1.1, 'a'}, {2.2, 'b'}, {3.3, 'c'}, {4.4, 'd'}, {5.5, 'e'}});
  s21::map<double, char> map_2;
  EXPECT_EQ(map_1.size(), 5);

  auto res_test_1 = map_1.contains(3.3);
  EXPECT_EQ(res_test_1, true);
  res_test_1 = map_1.contains(3.2);
  EXPECT_EQ(res_test_1, false);

  auto res_test_2 = map_2.contains(3.3);
  EXPECT_EQ(res_test_2, false);
}

TEST(map_test, test_clear_full) {
  s21::map<double, char> map_1(
      {{1.1, 'a'}, {2.2, 'b'}, {3.3, 'c'}, {4.4, 'd'}, {5.5, 'e'}});
  std::map<double, char> orignal_map_1(
      {{1.1, 'a'}, {2.2, 'b'}, {3.3, 'c'}, {4.4, 'd'}, {5.5, 'e'}});
  EXPECT_EQ(map_1.size(), 5);

  map_1.clear();
  orignal_map_1.clear();
  EXPECT_EQ(map_1.size(), 0);
  EXPECT_EQ(map_1.size(), orignal_map_1.size());

  auto it = map_1.begin();
  auto it_2 = orignal_map_1.begin();
  for (; it != map_1.end(); ++it) {
    EXPECT_DOUBLE_EQ((*it).first, (*it_2).first);
    EXPECT_EQ((*it).second, (*it_2).second);
    ++it_2;
  }
}

TEST(map_test, test_clear_empty) {
  s21::map<double, char> map_1;
  std::map<double, char> orignal_map_1;
  EXPECT_EQ(map_1.size(), 0);

  map_1.clear();
  orignal_map_1.clear();
  EXPECT_EQ(map_1.size(), 0);
  EXPECT_EQ(map_1.size(), orignal_map_1.size());

  auto it = map_1.begin();
  auto it_2 = orignal_map_1.begin();
  for (; it != map_1.end(); ++it) {
    EXPECT_DOUBLE_EQ((*it).first, (*it_2).first);
    EXPECT_EQ((*it).second, (*it_2).second);
    ++it_2;
  }
}

// TEST(map_test, test_emplace) {
//   s21::map<double, char> map_1(
//       {{1.1, 'a'}, {2.2, 'b'}, {3.3, 'c'}, {4.4, 'd'}, {5.5, 'e'}});
//   std::map<double, char> orignal_map_1(
//       {{1.1, 'a'}, {2.2, 'b'}, {3.3, 'c'}, {4.4, 'd'}, {5.5, 'e'}});
//   EXPECT_EQ(map_1.size(), 5);

//   auto res_test_1 = map_1.Emplace(
//       std::pair<double, char>(1.1, 's'), std::pair<double, char>(3.2, 'c'),
//       std::pair<double, char>(3.5, 'c'), std::pair<double, char>(5.5, 'c'));
//   auto it_vec = res_test_1.begin();
//   EXPECT_EQ(it_vec->second, false);
//   EXPECT_DOUBLE_EQ((*it_vec->first).first, 1.1);
//   EXPECT_EQ((*it_vec->first).second, 'a');
//   ++it_vec;
//   EXPECT_EQ(it_vec->second, true);
//   EXPECT_DOUBLE_EQ((*it_vec->first).first, 3.2);
//   EXPECT_EQ((*it_vec->first).second, 'c');
//   ++it_vec;
//   EXPECT_EQ(it_vec->second, true);
//   EXPECT_DOUBLE_EQ((*it_vec->first).first, 3.5);
//   EXPECT_EQ((*it_vec->first).second, 'c');
//   ++it_vec;
//   EXPECT_EQ(it_vec->second, false);
//   EXPECT_DOUBLE_EQ((*it_vec->first).first, 5.5);
//   EXPECT_EQ((*it_vec->first).second, 'e');

//   EXPECT_EQ(map_1.size(), 7);
// }

TEST(map_test, test_swap) {
  s21::map<int, char> map_1({{1, 'a'}, {3, 'b'}, {5, 'b'}});
  s21::map<int, char> map_2({{2, 'l'}, {4, 'o'}, {6, 'b'}, {8, 's'}});

  EXPECT_EQ(map_1.size(), 3);
  EXPECT_EQ(map_2.size(), 4);

  std::map<int, char> orignal_map_1({{1, 'a'}, {3, 'b'}, {5, 'b'}});
  std::map<int, char> orignal_map_2({{2, 'l'}, {4, 'o'}, {6, 'b'}, {8, 's'}});

  map_1.swap(map_2);
  orignal_map_1.swap(orignal_map_2);

  EXPECT_EQ(map_1.size(), 4);
  EXPECT_EQ(map_2.size(), 3);
  EXPECT_EQ(map_1.size(), orignal_map_1.size());
  EXPECT_EQ(map_2.size(), orignal_map_2.size());

  auto it = map_1.begin();
  auto it_2 = orignal_map_1.begin();
  for (; it != map_1.end(); ++it) {
    EXPECT_DOUBLE_EQ((*it).first, (*it_2).first);
    EXPECT_EQ((*it).second, (*it_2).second);
    ++it_2;
  }

  auto it_3 = map_2.begin();
  auto it_4 = orignal_map_2.begin();
  for (; it_3 != map_2.end(); ++it_3) {
    EXPECT_DOUBLE_EQ((*it_3).first, (*it_4).first);
    EXPECT_EQ((*it_3).second, (*it_4).second);
    ++it_4;
  }
}

TEST(map_test, test_erase) {
  s21::map<int, char> map_1;
  std::map<int, char> orignal_map_1;

  for (int i = 1; i < 21; i++) {
    map_1.insert({i, 'a'});
    orignal_map_1.insert({i, 'a'});
  }
  EXPECT_EQ(map_1.size(), 20);
  EXPECT_EQ(map_1.size(), orignal_map_1.size());

  auto it = map_1.insert({25, 'b'}).first;
  auto it_2 = orignal_map_1.insert({25, 'b'}).first;
  EXPECT_EQ(map_1.size(), 21);
  EXPECT_EQ(map_1.size(), orignal_map_1.size());

  map_1.erase(it);
  orignal_map_1.erase(it_2);
  EXPECT_EQ(map_1.size(), 20);
  EXPECT_EQ(map_1.size(), orignal_map_1.size());

  it = map_1.begin();
  it_2 = orignal_map_1.begin();
  for (; it != map_1.end(); ++it) {
    EXPECT_DOUBLE_EQ((*it).first, (*it_2).first);
    EXPECT_EQ((*it).second, (*it_2).second);
    ++it_2;
  }
}

// TEST(map_test, test_erase_01) {
//   s21::map<double, char> map_1(
//       {{1.1, 'a'}, {2.2, 'b'}, {3.3, 'c'}, {4.4, 'd'}, {5.5, 'e'}});
//   std::map<double, char> orignal_map_1(
//       {{1.1, 'a'}, {2.2, 'b'}, {3.3, 'c'}, {4.4, 'd'}, {5.5, 'e'}});

//   EXPECT_EQ(map_1.size(), 5);
//   EXPECT_EQ(map_1.size(), orignal_map_1.size());

//   auto it = map_1.begin();
//   map_1.Advance(it, 2);
//   auto it_2 = orignal_map_1.begin();
//   std::advance(it_2, 2);
//   EXPECT_DOUBLE_EQ((*it).first, (*it_2).first);
//   EXPECT_EQ((*it).second, (*it_2).second);

//   map_1.erase(it);
//   orignal_map_1.erase(it_2);
//   EXPECT_EQ(map_1.size(), 4);
//   EXPECT_EQ(map_1.size(), orignal_map_1.size());

//   it = map_1.begin();
//   it_2 = orignal_map_1.begin();
//   for (; it != map_1.end(); ++it) {
//     EXPECT_DOUBLE_EQ((*it).first, (*it_2).first);
//     EXPECT_EQ((*it).second, (*it_2).second);
//     ++it_2;
//   }
//   EXPECT_EQ(map_1.IsBalanced(), true);
// }

TEST(map_test, test_erase_03) {
  s21::map<int, char> map_1;
  std::map<int, char> orignal_map_1;

  EXPECT_EQ(map_1.size(), 0);
  EXPECT_EQ(map_1.size(), orignal_map_1.size());

  auto it = map_1.begin();

  map_1.erase(it);
  EXPECT_EQ(map_1.size(), 0);
}

TEST(map_test, test_iter_end) {
  s21::map<double, char> map_1({{1.1, 'a'},
                                {2.2, 'b'},
                                {3.3, 'c'},
                                {4.4, 'd'},
                                {5.5, 'e'},
                                {3.3, 'c'},
                                {4.4, 'd'},
                                {5.5, 'e'}});
  std::map<double, char> orignal_map_1({{1.1, 'a'},
                                        {2.2, 'b'},
                                        {3.3, 'c'},
                                        {4.4, 'd'},
                                        {5.5, 'e'},
                                        {3.3, 'c'},
                                        {4.4, 'd'},
                                        {5.5, 'e'}});

  s21::map<double, char>::iterator it = map_1.end();
  std::map<double, char>::iterator it_2 = orignal_map_1.end();
  --it;
  --it_2;
  EXPECT_DOUBLE_EQ((*it).first, (*it_2).first);
  EXPECT_EQ((*it).second, (*it_2).second);
}

TEST(map_test, test_iter_end_empty) {
  s21::map<double, char> map_1;

  s21::map<double, char>::iterator it = map_1.end();
  --it;
  it = map_1.begin();
  --it;
  it--;
  it = map_1.end();
  ++it;
  it++;
}

TEST(map_test, test_const_iter_end_empty) {
  s21::map<double, char> map_1;

  s21::map<double, char>::const_iterator it = map_1.cend();

  ++it;
  it = map_1.cbegin();
  --it;
  it--;
  it = map_1.cend();
  ++it;
  it++;
}

TEST(map_test, test_const_iter_end_pref) {
  s21::map<double, char> map_1({{1.1, 'a'},
                                {2.2, 'b'},
                                {3.3, 'c'},
                                {4.4, 'd'},
                                {5.5, 'e'},
                                {3.3, 'c'},
                                {4.4, 'd'},
                                {5.5, 'e'}});
  std::map<double, char> orignal_map_1({{1.1, 'a'},
                                        {2.2, 'b'},
                                        {3.3, 'c'},
                                        {4.4, 'd'},
                                        {5.5, 'e'},
                                        {3.3, 'c'},
                                        {4.4, 'd'},
                                        {5.5, 'e'}});

  s21::map<double, char>::const_iterator it = map_1.cend();
  std::map<double, char>::const_iterator it_2 = orignal_map_1.end();
  --it;
  --it_2;
  EXPECT_DOUBLE_EQ((*it).first, (*it_2).first);
  EXPECT_EQ((*it).second, (*it_2).second);
  --it;
  --it_2;
  EXPECT_DOUBLE_EQ((*it).first, (*it_2).first);
  EXPECT_EQ((*it).second, (*it_2).second);
}

TEST(map_test, test_const_iter_begin_pref) {
  s21::map<double, char> map_1({{1.1, 'a'},
                                {2.2, 'b'},
                                {3.3, 'c'},
                                {4.4, 'd'},
                                {5.5, 'e'},
                                {3.3, 'c'},
                                {4.4, 'd'},
                                {5.5, 'e'}});
  std::map<double, char> orignal_map_1({{1.1, 'a'},
                                        {2.2, 'b'},
                                        {3.3, 'c'},
                                        {4.4, 'd'},
                                        {5.5, 'e'},
                                        {3.3, 'c'},
                                        {4.4, 'd'},
                                        {5.5, 'e'}});

  s21::map<double, char>::const_iterator it = map_1.cbegin();
  std::map<double, char>::const_iterator it_2 = orignal_map_1.cbegin();
  ++it;
  ++it_2;
  EXPECT_DOUBLE_EQ((*it).first, (*it_2).first);
  EXPECT_EQ((*it).second, (*it_2).second);
  ++it;
  ++it_2;
  EXPECT_DOUBLE_EQ((*it).first, (*it_2).first);
  EXPECT_EQ((*it).second, (*it_2).second);
}

TEST(map_test, test_const_iter_end_post) {
  s21::map<double, char> map_1({{1.1, 'a'},
                                {2.2, 'b'},
                                {3.3, 'c'},
                                {4.4, 'd'},
                                {5.5, 'e'},
                                {3.3, 'c'},
                                {4.4, 'd'},
                                {5.5, 'e'}});
  std::map<double, char> orignal_map_1({{1.1, 'a'},
                                        {2.2, 'b'},
                                        {3.3, 'c'},
                                        {4.4, 'd'},
                                        {5.5, 'e'},
                                        {3.3, 'c'},
                                        {4.4, 'd'},
                                        {5.5, 'e'}});

  s21::map<double, char>::const_iterator it = map_1.cend();
  std::map<double, char>::const_iterator it_2 = orignal_map_1.end();
  it--;
  it_2--;
  EXPECT_DOUBLE_EQ((*it).first, (*it_2).first);
  EXPECT_EQ((*it).second, (*it_2).second);
  it--;
  it_2--;
  EXPECT_DOUBLE_EQ((*it).first, (*it_2).first);
  EXPECT_EQ((*it).second, (*it_2).second);
}

TEST(map_test, test_const_iter_begin_post) {
  s21::map<double, char> map_1({{1.1, 'a'},
                                {2.2, 'b'},
                                {3.3, 'c'},
                                {4.4, 'd'},
                                {5.5, 'e'},
                                {3.3, 'c'},
                                {4.4, 'd'},
                                {5.5, 'e'}});
  std::map<double, char> orignal_map_1({{1.1, 'a'},
                                        {2.2, 'b'},
                                        {3.3, 'c'},
                                        {4.4, 'd'},
                                        {5.5, 'e'},
                                        {3.3, 'c'},
                                        {4.4, 'd'},
                                        {5.5, 'e'}});

  s21::map<double, char>::const_iterator it = map_1.cbegin();
  std::map<double, char>::const_iterator it_2 = orignal_map_1.cbegin();
  it++;
  it_2++;
  EXPECT_DOUBLE_EQ((*it).first, (*it_2).first);
  EXPECT_EQ((*it).second, (*it_2).second);
  it++;
  it_2++;
  EXPECT_DOUBLE_EQ((*it).first, (*it_2).first);
  EXPECT_EQ((*it).second, (*it_2).second);
}

TEST(map_test, test_iter_plus) {
  s21::map<double, char> map_1({{1.1, 'a'},
                                {2.2, 'b'},
                                {3.3, 'c'},
                                {4.4, 'd'},
                                {5.5, 'e'},
                                {3.3, 'c'},
                                {4.4, 'd'},
                                {5.5, 'e'}});
  std::map<double, char> orignal_map_1({{1.1, 'a'},
                                        {2.2, 'b'},
                                        {3.3, 'c'},
                                        {4.4, 'd'},
                                        {5.5, 'e'},
                                        {3.3, 'c'},
                                        {4.4, 'd'},
                                        {5.5, 'e'}});

  s21::map<double, char>::iterator it = map_1.begin();
  std::map<double, char>::iterator it_2 = orignal_map_1.begin();
  for (; it != map_1.end() && it_2 != orignal_map_1.end();) {
    EXPECT_DOUBLE_EQ((*it).first, (*it_2).first);
    EXPECT_EQ((*it).second, (*it_2).second);
    ++it;
    ++it_2;
  }
  EXPECT_EQ(map_1.size(), orignal_map_1.size());

  it = map_1.begin();
  it_2 = orignal_map_1.begin();
  for (; it != map_1.end() && it_2 != orignal_map_1.end();) {
    EXPECT_DOUBLE_EQ((*it).first, (*it_2).first);
    EXPECT_EQ((*it).second, (*it_2).second);
    it++;
    it_2++;
  }
  EXPECT_EQ(map_1.size(), orignal_map_1.size());
}

TEST(map_test, test_iter_minus) {
  s21::map<double, char> map_1({{1.1, 'a'},
                                {2.2, 'b'},
                                {3.3, 'c'},
                                {4.4, 'd'},
                                {5.5, 'e'},
                                {3.3, 'c'},
                                {4.4, 'd'},
                                {5.5, 'e'}});
  std::map<double, char> orignal_map_1({{1.1, 'a'},
                                        {2.2, 'b'},
                                        {3.3, 'c'},
                                        {4.4, 'd'},
                                        {5.5, 'e'},
                                        {3.3, 'c'},
                                        {4.4, 'd'},
                                        {5.5, 'e'}});

  s21::map<double, char>::iterator it = map_1.end();
  std::map<double, char>::iterator it_2 = orignal_map_1.end();
  for (; it != map_1.begin() && it_2 != orignal_map_1.begin();) {
    --it;
    --it_2;
    EXPECT_DOUBLE_EQ((*it).first, (*it_2).first);
    EXPECT_EQ((*it).second, (*it_2).second);
  }
  EXPECT_EQ(map_1.size(), orignal_map_1.size());

  it = map_1.end();
  it_2 = orignal_map_1.end();
  for (; it != map_1.begin() && it_2 != orignal_map_1.begin();) {
    it--;
    it_2--;
    EXPECT_DOUBLE_EQ((*it).first, (*it_2).first);
    EXPECT_EQ((*it).second, (*it_2).second);
  }
  EXPECT_EQ(map_1.size(), orignal_map_1.size());

  it = map_1.begin();
  it_2 = orignal_map_1.begin();
  --it;
  --it_2;
  it--;
  it_2--;
  it = map_1.end();
  it_2 = orignal_map_1.end();
  ++it;
  ++it_2;
  it++;
  it_2++;
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}