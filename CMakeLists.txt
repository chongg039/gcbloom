cmake_minimum_required(VERSION 3.15)
project(gcbloom)

set(CMAKE_CXX_STANDARD 11)

message("-- Project gcbloom root path: " ${gcbloom_SOURCE_DIR})
message("-- Project gcbloom binary path: " ${gcbloom_BINARY_DIR})

set(GCBLOOM_INCLUDE_DIR
        "${gcbloom_SOURCE_DIR}/include")
set(GCBLOOM_SRC_DIR
        "${gcbloom_SOURCE_DIR}/src")

message("-- Project gcbloom include path: " ${gcbloom_build_include_dirs})
message("-- Project gcbloom src path: " ${gcbloom_build_src_dirs})

include_directories(${GCBLOOM_INCLUDE_DIR})

set(SMHASHER_SRC_DIR "thirdparty/smhasher/src")
set(GTEST_INCLUDE_DIR "thirdparty/googletest/include")

message("-- ThirdParty smhasher src path: " ${SMHASHER_SRC_DIR})
message("-- ThirdParty gtest include path: " ${GTEST_INCLUDE_DIR})

include_directories(${SMHASHER_SRC_DIR})
include_directories(${GTEST_INCLUDE_DIR})

add_library(murmurhash3 ${SMHASHER_SRC_DIR}/MurmurHash3.cpp)
add_library(gcbitmap ${GCBLOOM_SRC_DIR}/bitmap.cc)
add_library(gcbloom ${GCBLOOM_SRC_DIR}/bloom_filter.cc)

add_subdirectory(tests)