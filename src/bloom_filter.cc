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

GC_NS_BEGIN

BloomFilter::BloomFilter()
    : capacity_(BLOOM_FILTER_CAPACITY), bit_map_(), num_hash_(DEFAULT_N_HASH) {}

BloomFilter::BloomFilter(int64_t capacity, uint8_t num_hash)
    : capacity_(capacity), bit_map_(capacity_), num_hash_(num_hash) {}

BloomFilter::~BloomFilter() = default;

int BloomFilter::Get(const uint8_t data, std::size_t len) const {
  auto value = MurHash(&data, len);
  for (int i = 0; i < num_hash_; ++i) {
    uint64_t mapped = NthDoubleHash(i, value[0], value[1], capacity_);
    if (1 != bit_map_.Get(mapped)) {
      return 0;
    }
  }
  return 1;
}

int BloomFilter::Get(const char *data, std::size_t len) const {
  auto value = MurHash(data, len);
  for (int i = 0; i < num_hash_; ++i) {
    uint64_t mapped = NthDoubleHash(i, value[0], value[1], capacity_);
    if (1 != bit_map_.Get(mapped)) {
      return 0;
    }
  }
  return 1;
}

void BloomFilter::Set(const uint8_t data, std::size_t len) {
  auto value = MurHash(&data, len);
  for (int i = 0; i < num_hash_; ++i) {
    uint64_t mapped = NthDoubleHash(i, value[0], value[1], capacity_);
    bit_map_.Set(mapped);
  }
}

void BloomFilter::Set(const char *data, std::size_t len) {
  auto value = MurHash(data, len);
  for (int i = 0; i < num_hash_; ++i) {
    uint64_t mapped = NthDoubleHash(i, value[0], value[1], capacity_);
    bit_map_.Set(mapped);
  }
}

uint64_t BloomFilter::NthDoubleHash(int ordinal, uint64_t hash_a,
                                    uint64_t hash_b,
                                    uint64_t filter_size) const {
  return (hash_a + ordinal * hash_b) % filter_size;
}

std::array<uint64_t, 2> BloomFilter::MurHash(const void *data,
                                             std::size_t len) const {
  std::array<uint64_t, 2> value{};
  MurmurHash3_x64_128(&data, len, 0, value.data());
  return value;
}

GC_NS_END