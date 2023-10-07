#include <gtest/gtest.h>

#include "s21_vector.h"

TEST(S21VectorTest, DefaultConstructor) {
  s21::vector<int> A;
  std::vector<int> B;
  ASSERT_EQ(A.size(), B.size());
  ASSERT_EQ(A.capacity(), B.capacity());
}

TEST(S21VectorTest, SizeConstructor) {
  s21::vector<int> A(21);
  std::vector<int> B(21);
  ASSERT_EQ(A.size(), B.size());
  ASSERT_EQ(A.capacity(), B.capacity());
}

TEST(S21VectorTest, LightArrayConstructor) {
  s21::vector<int> A{1, 2, 3, 4, 5, 6, 7};
  std::vector<int> B{1, 2, 3, 4, 5, 6, 7};
  ASSERT_EQ(A.at(0), B.at(0));
  ASSERT_EQ(A.at(1), B.at(1));
  ASSERT_EQ(A.at(2), B.at(2));
  ASSERT_EQ(A.at(3), B.at(3));
  ASSERT_EQ(A.at(4), B.at(4));
  ASSERT_EQ(A.at(5), B.at(5));
  ASSERT_EQ(A.at(6), B.at(6));
  ASSERT_EQ(A.size(), B.size());
  ASSERT_EQ(A.capacity(), B.capacity());
}

TEST(S21VectorTest, CopyConstructor) {
  s21::vector<int> A{1, 2, 3, 4, 5, 6, 7};
  s21::vector<int> A_test(A);
  std::vector<int> B{1, 2, 3, 4, 5, 6, 7};
  std::vector<int> B_test(B);
  ASSERT_EQ(A.size(), A_test.size());
  ASSERT_EQ(B.size(), B_test.size());
  ASSERT_EQ(A.capacity(), A_test.capacity());
  ASSERT_EQ(B.capacity(), B_test.capacity());
  EXPECT_TRUE(A == A_test);
  EXPECT_TRUE(B == B_test);
}

TEST(S21VectorTest, MoveConstructor) {
  s21::vector<int> A{1, 2, 3, 4, 5, 6, 7};
  s21::vector<int> A_test(std::move(A));

  std::vector<int> B{1, 2, 3, 4, 5, 6, 7};
  std::vector<int> B_test(std::move(B));

  ASSERT_EQ(A.size(), B.size());
  ASSERT_EQ(A.capacity(), B.capacity());
  ASSERT_EQ(A_test.size(), B_test.size());
  ASSERT_EQ(A_test.capacity(), B_test.capacity());
}

TEST(S21VectorTest, Empty) {
  s21::vector<int> A;
  std::vector<int> B;
  EXPECT_TRUE(A.empty() == B.empty());

  s21::vector<int> A1{1, 2, 3, 4, 5, 6, 7};
  std::vector<int> B1{1, 2, 3, 4, 5, 6, 7};
  EXPECT_TRUE(A1.empty() == B1.empty());
}

TEST(S21VectorTest, Size) {
  s21::vector<int> A;
  std::vector<int> B;
  s21::vector<int> A1{1, 2, 3, 4, 5, 6, 7};
  std::vector<int> B1{1, 2, 3, 4, 5, 6, 7};
  EXPECT_TRUE(A.size() == B.size());
  EXPECT_TRUE(A1.size() == B1.size());
}

TEST(S21VectorTest, MaxSize) {
  s21::vector<int> A;
  std::vector<int> B;
  s21::vector<int> A1{1, 2, 3, 4, 5, 6, 7};
  std::vector<int> B1{1, 2, 3, 4, 5, 6, 7};
  EXPECT_TRUE(A.max_size() == B.max_size());
  EXPECT_TRUE(A1.max_size() == B1.max_size());
}

TEST(S21VectorTest, AssignOperator) {
  s21::vector<int> A;
  s21::vector<int> A1{1, 2, 3, 4, 5, 6, 7};
  s21::vector<int> A2;
  std::vector<int> B;
  std::vector<int> B1{1, 2, 3, 4, 5, 6, 7};
  std::vector<int> B2;

  EXPECT_TRUE(A.size() == B.size());
  EXPECT_TRUE(A1.size() == B1.size());

  A = A1;
  B = B1;
  EXPECT_TRUE(A.size() == B.size());
  EXPECT_TRUE(A1.size() == B1.size());

  A = A2;
  A1 = A2;
  B = B2;
  B1 = B2;
  EXPECT_TRUE(A.size() == B.size());
  EXPECT_TRUE(A1.size() == B1.size());
}

TEST(S21VectorTest, ReserveCapacityShrink) {
  s21::vector<int> A;
  std::vector<int> B;
  A.reserve(21);
  B.reserve(21);
  EXPECT_EQ(A.size(), B.size());
  EXPECT_EQ(A.capacity(), B.capacity());
  EXPECT_EQ(A.max_size(), B.max_size());
  A.shrink_to_fit();
  B.shrink_to_fit();
  EXPECT_TRUE(A.size() == B.size());
  EXPECT_TRUE(A.capacity() == B.capacity());
  EXPECT_TRUE(A.max_size() == B.max_size());

  s21::vector<int> A1{1, 2, 3, 4, 5, 6, 7};
  std::vector<int> B1{1, 2, 3, 4, 5, 6, 7};
  A1.reserve(21);
  B1.reserve(21);
  EXPECT_TRUE(A1.size() == B1.size());
  EXPECT_TRUE(A1.capacity() == B1.capacity());
  EXPECT_TRUE(A1.max_size() == B1.max_size());
  A1.shrink_to_fit();
  B1.shrink_to_fit();
  EXPECT_TRUE(A1.size() == B1.size());
  EXPECT_TRUE(A1.capacity() == B1.capacity());
  EXPECT_TRUE(A1.max_size() == B1.max_size());
}

TEST(S21VectorTest, FrontBackData) {
  s21::vector<int> A{1, 2, 3, 4, 5, 6, 7};
  std::vector<int> B{1, 2, 3, 4, 5, 6, 7};
  ASSERT_EQ(A.front(), B.front());
  ASSERT_EQ(A.back(), B.back());
  ASSERT_EQ(*A.data(), *B.data());
}

TEST(S21VectorTest, PushPopBack) {
  s21::vector<int> A{1, 2, 3, 4, 5, 6, 7};
  std::vector<int> B{1, 2, 3, 4, 5, 6, 7};
  s21::vector<int> A1{1};
  std::vector<int> B1{1};

  ASSERT_EQ(A.back(), B.back());
  A.pop_back();
  B.pop_back();
  ASSERT_EQ(A.back(), B.back());
  A.push_back(21);
  B.push_back(21);
  ASSERT_EQ(A.back(), B.back());
}

TEST(S21VectorTest, ClearContents) {
  s21::vector<int> A{1, 2, 3, 4, 5, 6, 7};
  std::vector<int> B{1, 2, 3, 4, 5, 6, 7};
  s21::vector<int> A1{1};
  std::vector<int> B1{1};

  A.clear();
  A1.clear();
  B.clear();
  B1.clear();
  ASSERT_EQ(A.size(), B.size());
  ASSERT_EQ(A1.size(), B1.size());
}

TEST(S21VectorTest, EraseContent) {
  s21::vector<int> A{1, 2, 3, 4, 5, 6, 7};
  std::vector<int> B{1, 2, 3, 4, 5, 6, 7};
  s21::vector<int> A1{1};
  std::vector<int> B1{1};

  A.erase(A.begin());
  A1.erase(A1.begin());
  B.erase(B.begin());
  B1.erase(B1.begin());

  ASSERT_EQ(A.size(), B.size());
  ASSERT_EQ(A.capacity(), B.capacity());
  ASSERT_EQ(A1.size(), B1.size());
  ASSERT_EQ(A1.capacity(), B1.capacity());

  A.push_back(21);
  A1.push_back(21);
  B.push_back(21);
  B1.push_back(21);

  A.erase(--A.end());
  A1.erase(--A1.end());
  B.erase(--B.end());
  B1.erase(--B1.end());

  ASSERT_EQ(A.size(), B.size());
  ASSERT_EQ(A.capacity(), B.capacity());
  ASSERT_EQ(A1.size(), B1.size());
  ASSERT_EQ(A1.capacity(), B1.capacity());
}

TEST(S21VectorTest, InsertContent) {
  s21::vector<int> A{1, 2, 3, 4, 5, 6, 7};
  std::vector<int> B{1, 2, 3, 4, 5, 6, 7};
  s21::vector<int> A1{1};
  std::vector<int> B1{1};

  A.insert(A.begin(), 21);
  A1.insert(A1.begin(), 21);
  B.insert(B.begin(), 21);
  B1.insert(B1.begin(), 21);

  ASSERT_EQ(A.size(), B.size());
  ASSERT_EQ(A1.size(), B1.size());

  A.push_back(21);
  A1.push_back(21);
  B.push_back(21);
  B1.push_back(21);

  A.insert(A.end(), 21);
  A1.insert(A1.end(), 21);
  B.insert(B.end(), 21);
  B1.insert(B1.end(), 21);

  ASSERT_EQ(A.size(), B.size());
  ASSERT_EQ(A1.size(), B1.size());
}

TEST(S21VectorTest, SwapContent) {
  s21::vector<int> A{1, 2, 3, 4, 5, 6, 7};
  std::vector<int> B{1, 2, 3, 4, 5, 6, 7};
  s21::vector<int> A1{1};
  std::vector<int> B1{1};

  ASSERT_EQ(A.size(), B.size());
  ASSERT_EQ(A1.size(), B1.size());

  A.swap(A1);
  std::swap(B, B1);

  ASSERT_EQ(A.size(), B.size());
  ASSERT_EQ(A1.size(), B1.size());

  A.swap(A1);
  std::swap(B, B1);

  ASSERT_EQ(A.size(), B.size());
  ASSERT_EQ(A1.size(), B1.size());
}

TEST(S21VectorTest, VectorIterator) {
  s21::vector<int> A{1, 2, 3, 4, 5, 6, 7};
  std::vector<int> B{1, 2, 3, 4, 5, 6, 7};

  auto A_iterator = A.begin();
  auto A1_iterator = A.begin();
  auto B_iterator = B.begin();
  A_iterator = A_iterator + 2;
  B_iterator = B_iterator + 2;

  ASSERT_EQ(*A_iterator, *B_iterator);
  ASSERT_EQ(&A_iterator, &A_iterator);
  ASSERT_TRUE(A_iterator == A_iterator);
  ASSERT_TRUE(A_iterator != A1_iterator);
}

TEST(S21VectorTest, VectorConstIterator) {
  s21::vector<int> A{1, 2, 3, 4, 5, 6, 7};
  std::vector<int> B{1, 2, 3, 4, 5, 6, 7};

  auto A_iterator = A.cbegin();
  auto A1_iterator = A.cbegin();
  auto B_iterator = B.cbegin();

  A_iterator = A_iterator + 2;
  B_iterator = B_iterator + 2;

  ASSERT_EQ(*A_iterator, *B_iterator);
  ASSERT_EQ(&A_iterator, &A_iterator);
  ASSERT_TRUE(A_iterator == A_iterator);
  ASSERT_TRUE(A_iterator != A1_iterator);
}

TEST(VectorTest, DefaultConstructor_EmptyVector) {
  s21::vector<int> v;
  EXPECT_TRUE(v.empty());
  EXPECT_EQ(v.size(), 0);
}

TEST(VectorTest, SizeConstructor_PositiveSize) {
  const size_t size = 5;
  s21::vector<int> v(size);
  EXPECT_FALSE(v.empty());
  EXPECT_EQ(v.size(), size);
  for (size_t i = 0; i < size; ++i) {
    EXPECT_EQ(v[i], 0);
  }
}

TEST(VectorTest, SizeConstructor_ZeroSize) {
  const size_t size = 0;
  s21::vector<int> v(size);
  EXPECT_TRUE(v.empty());
  EXPECT_EQ(v.size(), size);
}

TEST(VectorTest, InitializerListConstructor_EmptyList) {
  s21::vector<int> v = {};
  EXPECT_TRUE(v.empty());
  EXPECT_EQ(v.size(), 0);
}

TEST(VectorTest, InitializerListConstructor_NonEmptyList) {
  s21::vector<int> v = {1, 2, 3, 4, 5};
  EXPECT_FALSE(v.empty());
  EXPECT_EQ(v.size(), 5);
  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(v[4], 5);
}

TEST(VectorTest, CopyConstructor_EmptyVector) {
  s21::vector<int> v1;
  s21::vector<int> v2(v1);
  EXPECT_TRUE(v2.empty());
  EXPECT_EQ(v2.size(), 0);
}

TEST(VectorTest, CopyConstructor_NonEmptyVector) {
  s21::vector<int> v1 = {1, 2, 3};
  s21::vector<int> v2(v1);
  EXPECT_EQ(v2.size(), v1.size());
  for (size_t i = 0; i < v1.size(); ++i) {
    EXPECT_EQ(v2[i], v1[i]);
  }
}

TEST(VectorTest, MoveConstructor_EmptyVector) {
  s21::vector<int> v1;
  s21::vector<int> v2(std::move(v1));
  EXPECT_TRUE(v2.empty());
  EXPECT_EQ(v2.size(), 0);
}

TEST(VectorTest, MoveConstructor_NonEmptyVector) {
  s21::vector<int> v1 = {1, 2, 3};
  s21::vector<int> v2(std::move(v1));
  EXPECT_EQ(v2.size(), 3);
  EXPECT_TRUE(v1.empty());
}

TEST(VectorTest, Destructor_EmptyVector) {
  s21::vector<int>* v = new s21::vector<int>();
  delete v;
}

TEST(VectorTest, Destructor_NonEmptyVector) {
  s21::vector<int>* v = new s21::vector<int>{1, 2, 3};
  delete v;
}

TEST(VectorTest, MoveAssignmentOperator_EmptyToEmpty) {
  s21::vector<int> v1;
  s21::vector<int> v2;
  v2 = std::move(v1);
  EXPECT_TRUE(v2.empty());
  EXPECT_EQ(v2.size(), 0);
}

TEST(VectorTest, MoveAssignmentOperator_NonEmptyToEmpty) {
  s21::vector<int> v1 = {1, 2, 3};
  s21::vector<int> v2;
  v2 = std::move(v1);
  EXPECT_EQ(v2.size(), 3);
  EXPECT_TRUE(v1.empty());
}

TEST(VectorTest, MoveAssignmentOperator_EmptyToNonEmpty) {
  s21::vector<int> v1;
  s21::vector<int> v2 = {4, 5, 6};
  v2 = std::move(v1);
  EXPECT_TRUE(v2.empty());
  EXPECT_EQ(v2.size(), 0);
}

TEST(VectorTest, MoveAssignmentOperator_NonEmptyToNonEmpty) {
  s21::vector<int> v1 = {1, 2, 3};
  s21::vector<int> v2 = {4, 5, 6};
  v2 = std::move(v1);
  EXPECT_EQ(v2.size(), 3);
  EXPECT_TRUE(v1.empty());
}

TEST(VectorTest, At_ValidIndex) {
  s21::vector<int> v = {1, 2, 3, 4, 5};
  EXPECT_EQ(v.at(0), 1);
  EXPECT_EQ(v.at(2), 3);
  EXPECT_EQ(v.at(4), 5);
}

TEST(VectorTest, At_InvalidIndex) {
  s21::vector<int> v = {1, 2, 3, 4, 5};
  EXPECT_THROW(v.at(5), std::out_of_range);
  EXPECT_THROW(v.at(10), std::out_of_range);
}

TEST(VectorTest, IndexOperator_ValidIndex) {
  s21::vector<int> v = {1, 2, 3, 4, 5};
  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(v[2], 3);
  EXPECT_EQ(v[4], 5);
}

TEST(VectorTest, IndexOperator_InvalidIndex) {
  s21::vector<int> v = {1, 2, 3, 4, 5};
  EXPECT_ANY_THROW(v[5]);
  EXPECT_ANY_THROW(v[10]);
}

TEST(VectorTest, ConstIndexOperator_ValidIndex) {
  const s21::vector<int> v = {1, 2, 3, 4, 5};
  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(v[2], 3);
  EXPECT_EQ(v[4], 5);
}

TEST(VectorTest, ConstIndexOperator_InvalidIndex) {
  const s21::vector<int> v = {1, 2, 3, 4, 5};
  EXPECT_ANY_THROW(v[5]);
  EXPECT_ANY_THROW(v[10]);
}

TEST(VectorTest, FrontConst_ValidVector) {
  const s21::vector<int> v = {1, 2, 3, 4, 5};
  EXPECT_EQ(v.front(), 1);
}

TEST(VectorTest, FrontConst_EmptyVector) {
  const s21::vector<int> v;
  EXPECT_THROW(v.front(), std::out_of_range);
}

TEST(VectorTest, BackConst_ValidVector) {
  const s21::vector<int> v = {1, 2, 3, 4, 5};
  EXPECT_EQ(v.back(), 5);
}

TEST(VectorTest, BackConst_EmptyVector) {
  const s21::vector<int> v;
  EXPECT_THROW(v.back(), std::out_of_range);
}

TEST(VectorTest, Data_ValidVector) {
  s21::vector<int> v = {1, 2, 3, 4, 5};
  int* dataPtr = v.data();
  EXPECT_EQ(*dataPtr, 1);
  *dataPtr = 10;
  EXPECT_EQ(v[0], 10);
}

TEST(VectorTest, Data_EmptyVector) {
  s21::vector<int> v;
  int* dataPtr = v.data();
  EXPECT_EQ(dataPtr, nullptr);
}

TEST(VectorTest, Begin_ValidVector) {
  s21::vector<int> v = {1, 2, 3, 4, 5};
  auto it = v.begin();
  EXPECT_EQ(*it, 1);
  *it = 10;
  EXPECT_EQ(v[0], 10);
}

TEST(VectorTest, CBegin_ValidVector) {
  const s21::vector<int> v = {1, 2, 3, 4, 5};
  auto it = v.cbegin();
  EXPECT_EQ(*it, 1);
}

TEST(VectorTest, Empty_EmptyVector) {
  const s21::vector<int> v;
  EXPECT_TRUE(v.empty());
}

TEST(VectorTest, Empty_NonEmptyVector) {
  const s21::vector<int> v = {1, 2, 3};
  EXPECT_FALSE(v.empty());
}

TEST(VectorTest, Size_EmptyVector) {
  const s21::vector<int> v;
  EXPECT_EQ(v.size(), 0);
}

TEST(VectorTest, Size_NonEmptyVector) {
  const s21::vector<int> v = {1, 2, 3};
  EXPECT_EQ(v.size(), 3);
}

TEST(VectorTest, MaxSize) {
  const s21::vector<int> v;
  EXPECT_GT(v.max_size(), 0);
}

TEST(VectorTest, Reserve_IncreaseCapacity) {
  s21::vector<int> v;
  size_t initialCapacity = v.capacity();
  size_t newCapacity = initialCapacity + 10;
  v.reserve(newCapacity);
  EXPECT_GE(v.capacity(), newCapacity);
}

TEST(VectorTest, Reserve_DecreaseCapacity) {
  s21::vector<int> v = {1, 2, 3, 4, 5};
  size_t initialCapacity = v.capacity();
  size_t newCapacity = initialCapacity - 2;
  v.reserve(newCapacity);
  EXPECT_LE(v.capacity(), initialCapacity);
  EXPECT_GE(v.capacity(), newCapacity);
}

TEST(VectorTest, Capacity_EmptyVector) {
  const s21::vector<int> v;
  EXPECT_GE(v.capacity(), 0);
}

TEST(VectorTest, Capacity_NonEmptyVector) {
  const s21::vector<int> v = {1, 2, 3};
  EXPECT_GE(v.capacity(), v.size());
}

TEST(VectorTest, ShrinkToFit_EmptyVector) {
  s21::vector<int> v;
  v.shrink_to_fit();
  EXPECT_GE(v.capacity(), 0);
}

TEST(VectorTest, ShrinkToFit_NonEmptyVector) {
  s21::vector<int> v = {1, 2, 3, 4, 5};
  size_t initialCapacity = v.capacity();
  v.pop_back();
  v.shrink_to_fit();
  EXPECT_LE(v.capacity(), v.size());
  EXPECT_LE(v.capacity(), initialCapacity);
}

TEST(VectorTest, Clear_EmptyVector) {
  s21::vector<int> v;
  v.clear();
  EXPECT_TRUE(v.empty());
  EXPECT_EQ(v.size(), 0);
  EXPECT_GE(v.capacity(), 0);
}

TEST(VectorTest, Clear_NonEmptyVector) {
  s21::vector<int> v = {1, 2, 3, 4, 5};
  v.clear();
  EXPECT_TRUE(v.empty());
  EXPECT_EQ(v.size(), 0);
  EXPECT_GE(v.capacity(), 0);
}

TEST(VectorTest, Insert_Beginning) {
  s21::vector<int> v = {2, 3, 4};
  auto it = v.insert(v.begin(), 1);
  EXPECT_EQ(v.size(), 4);
  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(*it, 1);
}

TEST(VectorTest, Insert_Middle) {
  s21::vector<int> v = {1, 3, 4};
  auto it = v.insert(v.begin() + 1, 2);
  EXPECT_EQ(v.size(), 4);
  EXPECT_EQ(v[1], 2);
  EXPECT_EQ(*it, 2);
}

TEST(VectorTest, Insert_End) {
  s21::vector<int> v = {1, 2, 3};
  auto it = v.insert(v.end(), 4);
  EXPECT_EQ(v.size(), 4);
  EXPECT_EQ(v[3], 4);
  EXPECT_EQ(*it, 4);
}

TEST(VectorTest, Erase_Beginning) {
  s21::vector<int> v = {1, 2, 3, 4};
  v.erase(v.begin());  // Erase the first element
  EXPECT_EQ(v.size(), 3);
  EXPECT_EQ(v[0], 2);
}

TEST(VectorTest, Erase_Middle) {
  s21::vector<int> v = {1, 2, 3, 4};
  v.erase(v.begin() + 1);
  EXPECT_EQ(v.size(), 3);
  EXPECT_EQ(v[1], 3);
}

TEST(VectorTest, Erase_End) {
  s21::vector<int> v = {1, 2, 3, 4};
  v.erase(--v.end());
  EXPECT_EQ(v.size(), 3);
  EXPECT_EQ(v[2], 3);
}

TEST(VectorTest, PushBack_EmptyVector) {
  s21::vector<int> v;
  v.push_back(1);
  EXPECT_EQ(v.size(), 1);
  EXPECT_EQ(v[0], 1);
}

TEST(VectorTest, PushBack_NonEmptyVector) {
  s21::vector<int> v = {1, 2, 3};
  v.push_back(4);
  EXPECT_EQ(v.size(), 4);
  EXPECT_EQ(v[3], 4);
}

TEST(VectorTest, PopBack_NonEmptyVector) {
  s21::vector<int> v = {1, 2, 3};
  v.pop_back();
  EXPECT_EQ(v.size(), 2);
  EXPECT_EQ(v.back(), 2);
}

TEST(VectorTest, Swap_NonEmptyVectors) {
  s21::vector<int> v1 = {1, 2, 3};
  s21::vector<int> v2 = {4, 5, 6};

  v1.swap(v2);

  EXPECT_EQ(v1.size(), 3);
  EXPECT_EQ(v2.size(), 3);

  EXPECT_EQ(v1[0], 4);
  EXPECT_EQ(v1[2], 6);

  EXPECT_EQ(v2[0], 1);
  EXPECT_EQ(v2[2], 3);
}

TEST(VectorTest, Swap_EmptyAndNonEmptyVectors) {
  s21::vector<int> v1;
  s21::vector<int> v2 = {1, 2, 3};

  v1.swap(v2);

  EXPECT_EQ(v1.size(), 3);
  EXPECT_FALSE(v1.empty());
  EXPECT_EQ(v2.size(), 0);
  EXPECT_TRUE(v2.empty());
}

TEST(VectorTest, InsertMany) {
  s21::vector<int> vec = {1, 2, 3, 7, 8};
  s21::vector<int>::const_iterator pos = vec.cbegin() + 3;

  vec.insert_many(pos, 4, 5, 6);
  EXPECT_EQ(vec.size(), 8);
  EXPECT_EQ(vec[0], 1);
  EXPECT_EQ(vec[1], 2);
  EXPECT_EQ(vec[2], 3);
  EXPECT_EQ(vec[3], 4);
  EXPECT_EQ(vec[4], 5);
  EXPECT_EQ(vec[5], 6);
  EXPECT_EQ(vec[6], 7);
  EXPECT_EQ(vec[7], 8);
}

TEST(VectorTest, InsertManyBack) {
  s21::vector<int> vec = {1, 2, 3};

  vec.insert_many_back(4, 5, 6);
  EXPECT_EQ(vec.size(), 6);
  EXPECT_EQ(vec[0], 1);
  EXPECT_EQ(vec[1], 2);
  EXPECT_EQ(vec[2], 3);
  EXPECT_EQ(vec[3], 4);
  EXPECT_EQ(vec[4], 5);
  EXPECT_EQ(vec[5], 6);
}

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
