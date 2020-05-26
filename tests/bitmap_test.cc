// <gcbitmap is a bit-map implementation>
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

#include "gcbitmap/bitmap.h"

#include "gtest/gtest.h"

TEST(BitMapTest, GetTest) {
  gc::BitMap bitmap(100000);
  EXPECT_EQ(0, bitmap.Get(10));
}

TEST(BitMapTest, SetTest) {
  gc::BitMap bitmap(100000);
  bitmap.Set(10);
  EXPECT_EQ(1, bitmap.Get(10));
}

TEST(BitMapTest, DelTest) {
  gc::BitMap bitmap(100000);
  bitmap.Set(10);
  EXPECT_EQ(1, bitmap.Get(10));
  bitmap.Del(10);
  EXPECT_EQ(0, bitmap.Get(10));
}

TEST(BitMapTest, OutOfRange) {
  gc::BitMap bitmap(100);
  bitmap.Set(1000);
  EXPECT_EQ(0, bitmap.Get(1000));
}

TEST(BitMapTest, OutOfRangeDel) {
  gc::BitMap bitmap(100);
  bitmap.Del(1000);
  EXPECT_EQ(0, bitmap.Get(10));
}

int main() {
  ::testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}
