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

#ifndef GCBLOOM_COMMON_H_
#define GCBLOOM_COMMON_H_

#include <cstdint>

#include "gcbitmap/common.h"

#define GC_NS_BEGIN namespace gc {
#define GC_NS_END }

GC_NS_BEGIN

// should less than BITMAP_CAPACITY in bitmap
constexpr int64_t BLOOM_FILTER_CAPACITY = BITMAP_CAPACITY;
// default num of hash
constexpr uint8_t DEFAULT_N_HASH = 2;

GC_NS_END

#endif  // GCBLOOM_COMMON_H_
