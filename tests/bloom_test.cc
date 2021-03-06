// <gcbloom is a Bloom filter implementation>
// Copyright (C) <2020>  <GC>
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#include "gcbloom/bloom_filter.h"
#include "gtest/gtest.h"

TEST(BloomFilterTest, UIntGetTest) {
  gc::BloomFilter filter(100000, 2);
  uint8_t key = 255;
  EXPECT_EQ(0, filter.Get(key, 3));
}

TEST(BloomFilterTest, UintSetTest) {
  gc::BloomFilter filter(100000, 2);
  uint8_t key = 255;
  filter.Set(key, 3);
  EXPECT_EQ(1, filter.Get(key, 3));
}

TEST(BloomFilterTest, StrGetTest) {
  gc::BloomFilter filter(100000, 3);
  const char *key = "string";
  EXPECT_EQ(0, filter.Get(key, 6));
}

TEST(BloomFilterTest, StrSetTest) {
  gc::BloomFilter filter(100000, 3);
  const char *key = "string";
  filter.Set(key, 6);
  EXPECT_EQ(1, filter.Get(key, 6));
}

int main() {
  ::testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}
