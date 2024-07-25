add_executable(
    deserialize_test
    deserialize_test.cpp
)

target_link_libraries(
    deserialize_test
    GTest::gtest_main
    leetcode_utils
)

add_test(
    NAME deserialize_test
    COMMAND deserialize_test
)
