#include <iostream>
#include "leetcode_utils/arrays/random_ints.h"
#include <gtest/gtest.h>
#include <memory>

using std::cout;
using leetcode_utils::arrays::RandomGenerator;
using leetcode_utils::arrays::print_vector;
using std::unique_ptr;

TEST(RandomGeneratorTest, RandomGeneratorIntegers_WhenNoDebugGivenRange_ThenAllValuesGELowerAndLUpper)
{
    cout << "-- test_ints \n";
    unique_ptr<RandomGenerator> r = std::make_unique<RandomGenerator>();
    auto v1 = r->ints(0, 100, 30);

    ASSERT_EQ(v1.size(), 30);
    for (const auto val : v1) {
        EXPECT_TRUE(val >= 0 && val < 100);
    }
}

TEST(RandomGeneratorTest, RandomGeneratorIntegers_WhenDebugIsEnabled_ThenAllValuesEqual) {
    unique_ptr<RandomGenerator> r = std::make_unique<RandomGenerator>(true);
    auto v1 = r->ints(0, 100, 30);
    auto v2 = r->ints(0, 100, 30);

    ASSERT_EQ(v1.size(), 30);
    ASSERT_EQ(v1.size(), v2.size());

    for (int i = 0; i < v1.size(); i++) {
        EXPECT_EQ(v1[i], v2[i]);
    }
}

// TODO: rethink
TEST(RandomGeneratorTest, DISABLED_UniqueInts_WhenGivenRangIsLess_ThenExpectEmptyResult)
{
    cout << "-- test unique ints \n";
    unique_ptr<RandomGenerator> r = std::make_unique<RandomGenerator>(); // infinate loop, the are only 10 unique nums in a range
    
    auto v1 = r->unique_ints(0, 10, 20);
    EXPECT_EQ(v1.size(), 0);
    return;
}

TEST(RandomGenerator, UniqueSortedInts_WhenGivenRangeIsEnough_ThenValuesToBeSorted)
{
    cout << "-- test unique sorted ints \n";
    unique_ptr<RandomGenerator> r = std::make_unique<RandomGenerator>();
    auto v1 = r->unique_sorted_ints(0, 100, 10);
    
    ASSERT_EQ(v1.size(), 10);

    return;
}
