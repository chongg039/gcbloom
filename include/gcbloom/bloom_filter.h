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

#ifndef UTILS_BLOOM_FILTER_H_
#define UTILS_BLOOM_FILTER_H_

#include <array>

#include "../thirdparty/gcbitmap/include/gcbitmap/bitmap.h"
#include "../thirdparty/smhasher/src/MurmurHash3.h"
#include "../utils/common.h"

GC_NS_BEGIN

class BloomFilter {
 public:
  BloomFilter();

  BloomFilter(int32_t capacity, uint8_t num_hash);

  ~BloomFilter();

  BloomFilter(const BloomFilter &rhs) = delete;

  BloomFilter(BloomFilter &&rhs) noexcept = delete;

  BloomFilter &operator=(const BloomFilter &rhs) = delete;

  BloomFilter &operator=(BloomFilter &&rhs) noexcept = delete;

 public:
  int Get(const uint8_t &n, std::size_t len) const;

  void Set(const uint8_t &n, std::size_t len);

 private:
  std::array<uint32_t, 2> MurHash(const uint8_t &data, std::size_t len) const;
  uint32_t NthDoubleHash(uint8_t n, uint32_t hash_a, uint32_t hash_b,
                         uint32_t filter_size) const;

 private:
  int32_t capacity_;
  BitMap bit_map_;
  uint8_t num_hash_;
};

GC_NS_END

#endif  // UTILS_BLOOM_FILTER_H_
