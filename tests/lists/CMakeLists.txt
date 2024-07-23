add_executable(
    list_generator_test
    list_generator_test.cpp
)

target_link_libraries(
    list_generator_test
    GTest::gtest_main
    leetcode_utils
)

add_test(
    NAME list_generator_test
    COMMAND list_generator_test
)
