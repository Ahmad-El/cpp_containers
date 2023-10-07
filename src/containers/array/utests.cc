#include <gtest/gtest.h>

#include "s21_array.h"

TEST(S21ArrayTest, DefaultConstructor) {
  s21::array<int, 7> A{111, 2, 3, 21, 5, 6, 7};
  s21::array<int, 7> A12{1, 2, 3, 4, 21, 6, 7};
  s21::array<int, 7> A13{1, 2, 3, 4, 21, 6, 7};
  s21::array<int, 1> A1{7};
  s21::array<int, 7> A2(A12);
  s21::array<int, 7> A3;
  s21::array<int, 0> A4;
  s21::array<int, 7> A5(std::move(A13));

  std::array<int, 7> B{111, 2, 3, 21, 5, 6, 7};
  std::array<int, 7> B12{1, 2, 3, 4, 21, 6, 7};
  std::array<int, 7> B13{1, 2, 3, 4, 21, 6, 7};
  std::array<int, 1> B1{7};
  std::array<int, 7> B2(B12);
  std::array<int, 7> B3;
  std::array<int, 0> B4;
  std::array<int, 7> B5(std::move(B13));

  ASSERT_EQ(A.size(), B.size());
  ASSERT_EQ(A12.size(), B12.size());
  ASSERT_EQ(A1.size(), B1.size());
  ASSERT_EQ(A2.size(), B2.size());
  ASSERT_EQ(A3.size(), B3.size());
  ASSERT_EQ(A4.size(), B4.size());
  ASSERT_EQ(A5.size(), B5.size());
}

TEST(S21ArrayTest, Empty) {
  s21::array<int, 7> A{111, 2, 3, 21, 5, 6, 7};
  std::array<int, 7> B{111, 2, 3, 21, 5, 6, 7};
  s21::array<int, 0> A1;
  std::array<int, 0> B1;
  ASSERT_EQ(A.empty(), B.empty());
  ASSERT_EQ(A1.empty(), B1.empty());
}

TEST(S21ArrayTest, Size) {
  s21::array<int, 7> A{111, 2, 3, 21, 5, 6, 7};
  std::array<int, 7> B{111, 2, 3, 21, 5, 6, 7};
  s21::array<int, 0> A1;
  std::array<int, 0> B1;
  ASSERT_EQ(A.size(), B.size());
  ASSERT_EQ(A1.size(), B1.size());
}

TEST(S21ArrayTest, MaxSize) {
  s21::array<int, 7> A{111, 2, 3, 21, 5, 6, 7};
  std::array<int, 7> B{111, 2, 3, 21, 5, 6, 7};
  s21::array<int, 0> A1;
  std::array<int, 0> B1;
  ASSERT_EQ(A.max_size(), B.max_size());
  ASSERT_EQ(A1.max_size(), B1.max_size());
}

TEST(S21ArrayTest, At) {
  s21::array<int, 7> A{111, 2, 3, 21, 5, 6, 7};
  std::array<int, 7> B{111, 2, 3, 21, 5, 6, 7};
  ASSERT_EQ(A.at(0), B.at(0));
  ASSERT_EQ(A.at(1), B.at(1));
  ASSERT_EQ(A.at(2), B.at(2));
  ASSERT_EQ(A.at(3), B.at(3));
  ASSERT_EQ(A.at(4), B.at(4));
  ASSERT_EQ(A.at(5), B.at(5));
  ASSERT_EQ(A.at(6), B.at(6));
}

TEST(S21ArrayTest, Square) {
  s21::array<int, 7> A{111, 2, 3, 21, 5, 6, 7};
  std::array<int, 7> B{111, 2, 3, 21, 5, 6, 7};
  ASSERT_EQ(A[0], B[0]);
  ASSERT_EQ(A[1], B[1]);
  ASSERT_EQ(A[2], B[2]);
  ASSERT_EQ(A[3], B[3]);
  ASSERT_EQ(A[4], B[4]);
  ASSERT_EQ(A[5], B[5]);
  ASSERT_EQ(A[6], B[6]);
}

TEST(S21ArrayTest, FrontBack) {
  s21::array<int, 7> A{111, 2, 3, 21, 5, 6, 7};
  std::array<int, 7> B{111, 2, 3, 21, 5, 6, 7};
  ASSERT_EQ(A.front(), B.front());
  ASSERT_EQ(A.front(), B.front());
}

TEST(S21ArrayTest, Data) {
  s21::array<int, 7> A{111, 2, 3, 21, 5, 6, 7};
  std::array<int, 7> B{111, 2, 3, 21, 5, 6, 7};
  ASSERT_EQ(A.data()[5], B.data()[5]);
  ASSERT_EQ(*A.data(), *B.data());
}

TEST(S21ArrayTest, Fill) {
  s21::array<int, 7> A{111, 2, 3, 21, 5, 6, 7};
  s21::array<int, 7> A1{111, 2, 3, 21, 5, 6, 7};
  std::array<int, 7> B{111, 2, 3, 21, 5, 6, 7};
  A.fill(7);
  A1.fill(7);
  EXPECT_TRUE(A == A1);
  ASSERT_EQ(A.size(), B.size());
  ASSERT_EQ(A1.size(), B.size());
}

TEST(S21ArrayTest, IteratorOperators) {
  s21::array<int, 7> A{111, 2, 3, 21, 5, 6, 7};
  std::array<int, 7> B{111, 2, 3, 21, 5, 6, 7};

  auto A_b = A.begin();
  auto B_b = B.begin();

  EXPECT_TRUE(*A_b == *B_b);
  ++A_b;
  ++B_b;
  EXPECT_TRUE(*A_b == *B_b);
  --A_b;
  --B_b;
  EXPECT_TRUE(*A_b == *B_b);

  auto A_e = A.end();
  auto B_e = B.end();

  --A_e;
  --B_e;
  EXPECT_TRUE(*A_e == *B_e);
  --A_e;
  --B_e;
  EXPECT_TRUE(*A_e == *B_e);
  --A_e;
  --B_e;
  EXPECT_TRUE(*A_e == *B_e);

  ASSERT_EQ(&A_e, &A_e);

  A_e = A_e + 1;
  B_e = B_e + 1;
  EXPECT_TRUE(*A_e == *B_e);

  EXPECT_TRUE(*A_e != *A_b);
}

TEST(S21ArrayTest, constIteratorOperators) {
  s21::array<int, 7> A{111, 2, 3, 21, 5, 6, 7};
  std::array<int, 7> B{111, 2, 3, 21, 5, 6, 7};

  auto A_b = A.cbegin();
  auto B_b = B.cbegin();

  EXPECT_TRUE(*A_b == *B_b);
  ++A_b;
  ++B_b;
  EXPECT_TRUE(*A_b == *B_b);
  --A_b;
  --B_b;
  EXPECT_TRUE(*A_b == *B_b);

  auto A_e = A.cend();
  auto B_e = B.cend();

  --A_e;
  --B_e;
  EXPECT_TRUE(*A_e == *B_e);
  --A_e;
  --B_e;
  EXPECT_TRUE(*A_e == *B_e);
  --A_e;
  --B_e;
  EXPECT_TRUE(*A_e == *B_e);

  ASSERT_EQ(&A_e, &A_e);

  A_e = A_e + 1;
  B_e = B_e + 1;
  EXPECT_TRUE(*A_e == *B_e);

  EXPECT_TRUE(*A_e != *A_b);
}

TEST(S21ArrayTest, overloadOperators) {
  s21::array<int, 7> A{111, 2, 3, 21, 5, 6, 7};
  s21::array<int, 7> A1{111, 2, 3, 21, 5, 6, 7};
  s21::array<int, 7> A2{111, 2, 3, 21, 5, 7, 7};

  EXPECT_TRUE(A == A1);
  EXPECT_FALSE(A == A2);
}

TEST(S21ArrayTest, arrayModifiers) {
  s21::array<int, 7> A{111, 2, 3, 21, 5, 6, 7};
  s21::array<int, 7> A1{111, 2, 3, 21, 5, 6, 7};
  s21::array<int, 7> A2{111, 2, 3, 21, 5, 7, 7};
  s21::array<int, 7> A3{111, 2, 3, 21, 5, 7, 7};

  EXPECT_TRUE(A == A1);
  A1.swap(A2);
  EXPECT_FALSE(A == A1);
  EXPECT_TRUE(A1 == A3);
}

TEST(ArrayTest, DefaultConstructor) {
  s21::array<int, 5> arr;
  EXPECT_EQ(arr.size(), 5);
  for (size_t i = 0; i < arr.size(); ++i) {
    EXPECT_EQ(arr[i], 0);
  }
}

TEST(ArrayTest, InitListConstructor) {
  s21::array<int, 5> arr = {1, 2, 3, 4, 5};
  EXPECT_EQ(arr.size(), 5);
  for (size_t i = 0; i < arr.size(); ++i) {
    EXPECT_EQ(arr[i], static_cast<int>(i) + 1);
  }
}

TEST(ArrayTest, CopyConstructor) {
  s21::array<int, 5> arr = {1, 2, 3, 4, 5};
  s21::array<int, 5> arrCopy(arr);
  EXPECT_EQ(arrCopy.size(), 5);
  for (size_t i = 0; i < arr.size(); ++i) {
    EXPECT_EQ(arrCopy[i], arr[i]);
  }
}

TEST(ArrayTest, MoveConstructor) {
  s21::array<int, 5> arr = {1, 2, 3, 4, 5};
  s21::array<int, 5> arrMoved(std::move(arr));
  EXPECT_EQ(arrMoved.size(), 5);
  for (size_t i = 0; i < arrMoved.size(); ++i) {
    EXPECT_EQ(arrMoved[i], static_cast<int>(i) + 1);
  }
}

TEST(ArrayTest, Begin) {
  s21::array<int, 5> arr = {1, 2, 3, 4, 5};
  auto it = arr.begin();
  EXPECT_EQ(*it, 1);
  *it = 10;
  EXPECT_EQ(arr[0], 10);
}

TEST(ArrayTest, End) {
  s21::array<int, 5> arr = {1, 2, 3, 4, 5};
  auto it = arr.end();
  auto beginIt = arr.begin();
  EXPECT_EQ(&it, &(beginIt + 5));
}

TEST(ArrayTest, CEnd) {
  const s21::array<int, 5> arr = {1, 2, 3, 4, 5};
  auto it = arr.cend();
  auto beginIt = arr.cbegin();
  EXPECT_EQ(it, beginIt + 5);
}

TEST(ArrayTest, At_ValidIndex) {
  s21::array<int, 5> arr = {1, 2, 3, 4, 5};
  int value = arr.at(2);
  EXPECT_EQ(value, 3);
}

TEST(ArrayTest, At_OutOfBounds) {
  s21::array<int, 5> arr = {1, 2, 3, 4, 5};
  EXPECT_THROW(arr.at(10), std::out_of_range);
}

TEST(ArrayTest, ConstAt_ValidIndex) {
  const s21::array<int, 5> arr = {1, 2, 3, 4, 5};
  int value = arr.at(2);
  EXPECT_EQ(value, 3);
}

TEST(ArrayTest, ConstAt_OutOfBounds) {
  const s21::array<int, 5> arr = {1, 2, 3, 4, 5};
  EXPECT_THROW(arr.at(10), std::out_of_range);
}

TEST(ArrayTest, Front) {
  s21::array<int, 5> arr = {1, 2, 3, 4, 5};
  int value = arr.front();
  EXPECT_EQ(value, 1);
}

TEST(ArrayTest, Back) {
  s21::array<int, 5> arr = {1, 2, 3, 4, 5};
  int value = arr.back();
  EXPECT_EQ(value, 5);
}

TEST(ArrayTest, ConstFront) {
  const s21::array<int, 5> arr = {1, 2, 3, 4, 5};
  int value = arr.front();
  EXPECT_EQ(value, 1);
}

TEST(ArrayTest, ConstBack) {
  const s21::array<int, 5> arr = {1, 2, 3, 4, 5};
  int value = arr.back();
  EXPECT_EQ(value, 5);
}

TEST(ArrayTest, Empty_NonEmptyArray) {
  s21::array<int, 5> arr = {1, 2, 3, 4, 5};
  EXPECT_FALSE(arr.empty());
}

TEST(ArrayTest, Empty_EmptyArray) {
  s21::array<int, 0> arr;
  EXPECT_TRUE(arr.empty());
}

TEST(ArrayTest, Size_NonEmptyArray) {
  s21::array<int, 5> arr = {1, 2, 3, 4, 5};
  EXPECT_EQ(arr.size(), 5);
}

TEST(ArrayTest, Size_EmptyArray) {
  s21::array<int, 0> arr;
  EXPECT_EQ(arr.size(), 0);
}

TEST(ArrayTest, MaxSize) {
  s21::array<int, 5> arr;
  EXPECT_EQ(arr.max_size(), 5);
}

TEST(ArrayTest, Swap) {
  s21::array<int, 5> arr1 = {1, 2, 3, 4, 5};
  s21::array<int, 5> arr2 = {6, 7, 8, 9, 10};
  arr1.swap(arr2);
  for (size_t i = 0; i < arr1.size(); ++i) {
    EXPECT_EQ(arr1[i], static_cast<int>(i) + 6);
  }
  for (size_t i = 0; i < arr2.size(); ++i) {
    EXPECT_EQ(arr2[i], static_cast<int>(i) + 1);
  }
}

TEST(ArrayTest, Fill) {
  s21::array<int, 5> arr;
  arr.fill(10);
  for (size_t i = 0; i < arr.size(); ++i) {
    EXPECT_EQ(arr[i], 10);
  }
}

TEST(ArrayTest, CopyAssignmentOperator) {
  s21::array<int, 5> arr1 = {1, 2, 3, 4, 5};
  s21::array<int, 5> arr2 = {6, 7, 8, 9, 10};
  arr1 = arr2;
  for (size_t i = 0; i < arr1.size(); ++i) {
    EXPECT_EQ(arr1[i], arr2[i]);
  }
}

TEST(ArrayTest, MoveAssignmentOperator) {
  s21::array<int, 5> arr1 = {1, 2, 3, 4, 5};
  s21::array<int, 5> arr2 = {6, 7, 8, 9, 10};
  arr1 = std::move(arr2);
  for (size_t i = 0; i < arr1.size(); ++i) {
    EXPECT_EQ(arr1[i], static_cast<int>(i) + 6);
  }
}

TEST(ArrayTest, OperatorBracket) {
  s21::array<int, 5> arr = {1, 2, 3, 4, 5};
  for (size_t i = 0; i < arr.size(); ++i) {
    EXPECT_EQ(arr[i], static_cast<int>(i) + 1);
  }
  arr[2] = 10;
  EXPECT_EQ(arr[2], 10);
}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
