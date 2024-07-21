#include <leetcode_utils/leetcode_utils.h>
#include <gtest/gtest.h>
#include <unordered_set>

using leetcode_utils::arrays::RandomGenerator;
using std::unordered_set;

TEST(ArrayTestSuite, ArrayRandomInts_WhenRange) {
    RandomGenerator rg{};

    auto res = rg.ints(0, 10, 10);
    EXPECT_EQ(res.size(), 10);
}
