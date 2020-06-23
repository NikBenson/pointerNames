cmake_minimum_required(VERSION 3.16)
project(PointerNames C)

set(CMAKE_C_STANDARD 99)

ADD_SUBDIRECTORY(src tests)

ENABLE_TESTING()

ADD_TEST(NAME check_convert COMMAND check_convert)