add_executable(
  array_test
  array_test.cpp
)

target_link_libraries(
  array_test
  GTest::gtest_main
  leetcode_utils
)

add_test(
    NAME array_test
    COMMAND array_test
)

add_executable(
  random_test
  random_test.cpp
)

target_link_libraries(
    random_test
  GTest::gtest_main
  leetcode_utils
)

add_test(
    NAME random_test
    COMMAND random_test
)