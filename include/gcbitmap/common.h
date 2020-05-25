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

#ifndef GCBITMAP_COMMON_H_
#define GCBITMAP_COMMON_H_

#define GC_NS_BEGIN namespace gc {
#define GC_NS_END }

GC_NS_BEGIN

constexpr int32_t BIT_OF_BYTE = 8;

constexpr int32_t BITMAP_CAPACITY = 100000000;

GC_NS_END

#endif  // GCBITMAP_COMMON_H_
