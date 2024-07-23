#include <unordered_set>
#include <gtest/gtest.h>
#include "leetcode_utils/leetcode_utils.h"

using leetcode_utils::arrays::RandomGenerator;
using std::unordered_set;

TEST(ArrayTestSuite, ArrayRandomInts_WhenRange) {
    RandomGenerator rg{};

    auto res = rg.ints(0, 10, 10);
    EXPECT_EQ(res.size(), 10);
}
