# CMake generated Testfile for 
# Source directory: /testcode/HelloWorld/tests
# Build directory: /testcode/HelloWorld/build/tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(test_hello "/testcode/HelloWorld/build/tests/test_hello")
set_tests_properties(test_hello PROPERTIES  _BACKTRACE_TRIPLES "/testcode/HelloWorld/tests/CMakeLists.txt;13;add_test;/testcode/HelloWorld/tests/CMakeLists.txt;0;")
add_test(test_world "/testcode/HelloWorld/build/tests/test_world")
set_tests_properties(test_world PROPERTIES  _BACKTRACE_TRIPLES "/testcode/HelloWorld/tests/CMakeLists.txt;21;add_test;/testcode/HelloWorld/tests/CMakeLists.txt;0;")
subdirs("googletest")
