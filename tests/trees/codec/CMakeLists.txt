add_executable(
    codec_test
    codec_test.cpp
)

target_link_libraries(
    codec_test
    GTest::gtest_main
    leetcode_utils
)

add_test(
    NAME codec_test
    COMMAND codec_test
)
