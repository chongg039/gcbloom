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

#ifndef GCBITMAP_BITMAP_H_
#define GCBITMAP_BITMAP_H_

#include <cstring>
#include <iostream>
#include <memory>

#include "gcbitmap/common.h"

GC_NS_BEGIN

/**
 * BitMap轮子实现
 * 成员变量:
 *  1. nums_:       支持的最大存放容量
 *  2. size_:       需要的存储单元的个数, 这里使用的是char[]
 *  3. map_ptr_:    指向存储位置的智能指针
 * 对外接口:
 *  1. Get: 查看一个值是否在BitMap中, 存在返回1, 不存在返回0
 *  2. Set: 向BitMap中设置一个值, 成功返回1, 不成功返回0
 *  3. Del: 从BitMap中删除一个值, 成功返回1, 不成功返回0; 若原本就没有, 返回1
 * 注意事项:
 *  1. 最大存放容量类型是int64_t, 且受到BITMAP_CAPACITY限制
 *  2. 实现了拷贝语义和移动语义
 */
class BitMap {
 public:
  BitMap();

  explicit BitMap(int64_t nums);

  ~BitMap();

  BitMap(const BitMap &rhs);

  BitMap(BitMap &&rhs) noexcept;

  BitMap &operator=(const BitMap &rhs);

  BitMap &operator=(BitMap &&rhs) noexcept;

 public:
  int Get(int64_t n) const;

  int Set(int64_t n);

  int Del(int64_t n);

 private:
  static u_int64_t LocateByte(int64_t n);

  static u_int64_t LocateBit(int64_t n);

 private:
  int64_t nums_;
  int64_t size_;
  std::shared_ptr<char> map_ptr_;
};

GC_NS_END

#endif  // GCBITMAP_BITMAP_H_
