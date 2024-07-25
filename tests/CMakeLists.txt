
message(STATUS "Building tests: ")

enable_testing()

add_subdirectory(arrays)
add_subdirectory(lists)
add_subdirectory(trees)

# add_executable(
#   leetcode_utils_tests
#   printing_traversals.cpp
#   bintree_generator_test.cpp
# )
# target_link_libraries(
#   leetcode_utils_tests
#   GTest::gtest_main
#   leetcode_utils
# )

# include(GoogleTest)
# gtest_discover_tests(leetcode_utils_tests)


# add_executable( visualize_test.out
#     visualize/main.cpp
# )

# target_link_libraries(
#     visualize_test.out PRIVATE leetcode_utils
# )
