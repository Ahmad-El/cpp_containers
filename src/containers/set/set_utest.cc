#include <gtest/gtest.h>

//#include "s21_tree.h"
#include "s21_set.h"

TEST(set_, constructor) {
  std::set<int> origin = {1, 2, 3, 4, 5};
  s21::set<int> my_set = {1, 2, 3, 4, 5};
  my_set = my_set;
  std::set<int> copy_origin(origin);
  s21::set<int> copy_my(my_set);
  EXPECT_EQ(copy_my.size(), copy_origin.size());
  std::set<int>::iterator origin_it = copy_origin.begin();
  s21::set<int>::iterator my_it = copy_my.begin();
  for (; origin_it != copy_origin.end() && my_it != copy_my.end();
       my_it++, origin_it++)
    EXPECT_EQ(*my_it, *origin_it);
  origin.clear();
  my_set.clear();
  origin = std::move(copy_origin);
  my_set = std::move(copy_my);
  EXPECT_EQ(copy_my.size(), copy_origin.size());
  EXPECT_EQ(origin.size(), my_set.size());
}

TEST(set_, erase) {
  std::set<int> origin = {23, 3, 5, 6, 32, 2, 5, 66};
  s21::set<int> my_set = {23, 3, 5, 6, 32, 2, 5, 66};
  origin.erase(32);
  my_set.erase(32);
  std::set<int>::iterator origin_it = origin.begin();
  s21::set<int>::iterator my_it = my_set.begin();
  auto del = origin.begin();
  del++;
  auto del_my = my_set.begin();
  del_my++;
  origin.erase(del);
  my_set.erase(del_my);

  for (; origin_it != origin.end() && my_it != my_set.end();
       my_it++, origin_it++) {
    ASSERT_EQ(*my_it, *origin_it);
  }
}

TEST(set_, insert) {
  std::set<int> origin = {23, 3, 5, 6, 32, 2, 5, 66};
  s21::set<int> my_set = {23, 3, 5, 6, 32, 2, 5, 66};
  for (int i = 0; i < 10; i++) {
    origin.insert(i);
    my_set.insert(i);
  }
  std::set<int>::iterator origin_it = origin.begin();
  s21::set<int>::iterator my_it = my_set.begin();
  for (; origin_it != origin.end() && my_it != my_set.end();
       my_it++, origin_it++) {
    EXPECT_EQ(*my_it, *origin_it);
  }
  std::pair<std::set<int>::iterator, bool> result = origin.insert(100);
  s21::pair<s21::set<int>::iterator, bool> my_result = my_set.insert(100);
  EXPECT_EQ(result.second, my_result.second);
  EXPECT_EQ(*result.first, *my_result.first);
}

TEST(set_, find) {
  std::set<int> origin = {23, 3, 5, 6, 32, 2, 5, 66};
  s21::set<int> my_set = {23, 3, 5, 6, 32, 2, 5, 66};
  std::set<int>::iterator origin_it = origin.find(3);
  s21::set<int>::iterator my_it = my_set.find(3);
  EXPECT_EQ(*my_it, *origin_it);
}

TEST(set_, constains) {
  s21::set<int> my_set = {23, 3, 5, 6, 32, 2, 5, 66};
  EXPECT_TRUE(my_set.contains(66));
  EXPECT_FALSE(my_set.contains(0));
}

TEST(set_, merge) {
  s21::set<int> my_set = {23, 3, 5, 6, 32, 2, 5, 66};
  s21::set<int> my_set2;
  s21::set<int> datas;
  for (auto x : my_set) {
    my_set2.insert(x * 7);
  }
  for (auto x : my_set2) {
    datas.insert(x);
  }
  datas.insert_many(23, 3, 5, 6, 32, 2, 5, 66);
  my_set.merge(my_set2);
  s21::set<int>::iterator data_it = datas.begin();
  s21::set<int>::iterator my_it = my_set.begin();
  for (; data_it != datas.end() && my_it != my_set.end(); my_it++, data_it++) {
    EXPECT_EQ(*my_it, *data_it);
  }
  EXPECT_EQ(my_set.size(), datas.size());
}

TEST(set_, empty) {
  s21::set<int> my_set;
  EXPECT_TRUE(my_set.empty());
  my_set.insert(1);
  EXPECT_FALSE(my_set.empty());
  my_set.erase(1);
  EXPECT_TRUE(my_set.empty());
  my_set.insert_many(1, 2, 3, 4);
  EXPECT_FALSE(my_set.empty());
  my_set.clear();
  EXPECT_TRUE(my_set.empty());
}

TEST(set_, swap) {
  s21::set<char> my_set = {'1', 'b', 'c', 'd'};
  s21::set<char> other_set = {'z', 'q', 'u', 'i', 'n', 'f', 'i'};
  my_set.swap(other_set);
  std::set<char> _set = {'1', 'b', 'c', 'd'};
  std::set<char> _other_set = {'z', 'q', 'u', 'i', 'n', 'f', 'i'};
  _set.swap(_other_set);
  s21::set<char>::iterator my_it = my_set.begin();
  std::set<char>::iterator _it = _set.begin();
  for (; _it != _set.end() && my_it != my_set.end(); _it++, my_it++)
    EXPECT_EQ(*_it, *my_it);
  _it = _other_set.begin();
  my_it = other_set.begin();
  for (; _it != _other_set.end() && my_it != other_set.end(); _it++, my_it++)
    EXPECT_EQ(*_it, *my_it);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
