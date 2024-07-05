
message(STATUS "Building tests: ")

enable_testing()

add_executable(
  leetcode_utils_tests
  printing_traversals.cpp
  random_test.cpp
  bintree_generator_test.cpp
)
target_link_libraries(
  leetcode_utils_tests
  GTest::gtest_main
  leetcode_utils
)

include(GoogleTest)
gtest_discover_tests(leetcode_utils_tests)


add_executable( test_codec.out
    codec/main.cpp    
)

add_executable( visualize_test.out
    visualize/main.cpp
)

target_link_libraries(
    test_codec.out PRIVATE leetcode_utils
)

target_link_libraries(
    visualize_test.out PRIVATE leetcode_utils
)