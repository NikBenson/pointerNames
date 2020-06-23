# CMake generated Testfile for 
# Source directory: /home/nikb/CLionProjects/pointerNames
# Build directory: /home/nikb/CLionProjects/pointerNames
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(check_convert "/home/nikb/CLionProjects/pointerNames/tests/check_convert")
set_tests_properties(check_convert PROPERTIES  _BACKTRACE_TRIPLES "/home/nikb/CLionProjects/pointerNames/CMakeLists.txt;77;ADD_TEST;/home/nikb/CLionProjects/pointerNames/CMakeLists.txt;0;")
subdirs("src")
subdirs("tests")
