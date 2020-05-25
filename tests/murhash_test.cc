//
// Created by GaoChong on 2020/5/25.
//
#include <cstring>
#include <iostream>

#include "MurmurHash3.h"

int main() {
  uint64_t seed = 1;
  uint64_t *hash_otpt = new uint64_t;
  const char *key = "hi";
  MurmurHash3_x64_128(key, (uint64_t)strlen(key), seed, hash_otpt);
  std::cout << "hashed " << hash_otpt << std::endl;
  return 0;
}
