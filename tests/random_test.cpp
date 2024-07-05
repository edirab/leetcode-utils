#include <iostream>
#include "leetcode_utils/random_ints.h"
#include <gtest/gtest.h>
#include <memory>

using std::cout;
using leetcode_utils::RandomGenerator;
using leetcode_utils::print_vector;
using std::unique_ptr;


TEST(RandomGeneratorTest, RandomGeneratorIntegers_WhenNoDebugGivenRange_ThenAllValuesGELowerAndLUpper)
{
    cout << "-- test_ints \n";
    unique_ptr<RandomGenerator> r = std::make_unique<RandomGenerator>(0, 100, 30);
    auto v1 = r->ints();

    ASSERT_EQ(v1.size(), 30);
    for (const auto val : v1) {
        EXPECT_TRUE(val >= 0 && val < 100);
    }
}

TEST(RandomGeneratorTest, RandomGeneratorIntegers_WhenDebugIsEnabled_ThenAllValuesEqual) {
    unique_ptr<RandomGenerator> r = std::make_unique<RandomGenerator>(0, 100, 30);
    auto v1 = r->ints(true);
    auto v2 = r->ints(true);

    ASSERT_EQ(v1.size(), 30);
    ASSERT_EQ(v1.size(), v2.size());

    for (int i = 0; i < v1.size(); i++) {
        EXPECT_EQ(v1[i], v2[i]);
    }
}

TEST(RandomGeneratorTest, UniqueInts_WhenGivenRangIsLess_ThenExpectEmptyResult)
{
    cout << "-- test unique ints \n";
    unique_ptr<RandomGenerator> r = std::make_unique<RandomGenerator>(0, 10, 20); // infinate loop, the are only 10 unique nums in a range
    auto v1 = r->unique_ints();
    EXPECT_EQ(v1.size(), 0);
    return;
}

TEST(RandomGenerator, UniqueSortedInts_WhenGivenRangeIsEnough_ThenValuesToBeSorted)
{
    cout << "-- test unique sorted ints \n";
    unique_ptr<RandomGenerator> r = std::make_unique<RandomGenerator>(0, 100, 10);
    auto v1 = r->unique_sorted_ints();
    
    ASSERT_EQ(v1.size(), 10);

    return;
}
