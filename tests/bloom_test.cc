//
// Created by GaoChong on 2020/5/25.
//
#include <iostream>

#include "gcbloom/bloom_filter.h"
#include "gtest/gtest.h"

TEST(BloomFilterTest, GetTest) {
  gc::BloomFilter mm(100000, 2);
  int key = 9999;
  EXPECT_EQ(0, mm.Get(key, 4));
}

int main() {
  ::testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}
