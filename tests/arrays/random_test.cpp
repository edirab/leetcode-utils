#include <iostream>
#include "leetcode_utils/arrays/random_ints.h"
#include <gtest/gtest.h>
#include <memory>

using std::cout;
using leetcode_utils::arrays::RandomGenerator;
using leetcode_utils::arrays::print_vector;
using std::unique_ptr;

TEST(RandomGeneratorTest, Ints_WhenGivenCorrectRange_ThenAllValuesWithinRange)
{
    cout << "-- test_ints \n";
    unique_ptr<RandomGenerator> r = std::make_unique<RandomGenerator>();
    auto v1 = r->ints(0, 100, 30);

    ASSERT_EQ(v1.size(), 30);
    for (const auto val : v1) {
        EXPECT_TRUE(val >= 0 && val < 100);
    }
}

TEST(RandomGeneratorTest, Ints_WhenPositiveRangeIsZero_ThenExpectIncorrectRangeException)
{
    unique_ptr<RandomGenerator> r = std::make_unique<RandomGenerator>();

    EXPECT_THROW({
        auto v1 = r->ints(10, 10, 100);
    }, leetcode_utils::arrays::IncorrectRangeException);
}

TEST(RandomGeneratorTest, Ints_WhenNegativeRangeIsZero_ThenExpectIncorrectRangeException)
{
    unique_ptr<RandomGenerator> r = std::make_unique<RandomGenerator>();

    EXPECT_THROW({
        auto v1 = r->ints(-10, -10, 100);
    }, leetcode_utils::arrays::IncorrectRangeException);
}

TEST(RandomGeneratorTest, Ints_WhenRangeIsNegative_ThenExpectIncorrectRangeException)
{
    unique_ptr<RandomGenerator> r = std::make_unique<RandomGenerator>();

    EXPECT_THROW({
        auto v1 = r->ints(10, 9, 100);
    }, leetcode_utils::arrays::IncorrectRangeException);
}

TEST(RandomGeneratorTest, Ints_WhenNegRangeIsNegative_ThenExpectIncorrectRangeException)
{
    unique_ptr<RandomGenerator> r = std::make_unique<RandomGenerator>();

    EXPECT_THROW({
        auto v1 = r->ints(-10, -11, 100);
    }, leetcode_utils::arrays::IncorrectRangeException);
}

TEST(RandomGeneratorTest, Ints_WhenRangeIsOnePositiveElemOnly_ThenExpectCertainElem)
{
    unique_ptr<RandomGenerator> r = std::make_unique<RandomGenerator>();

    auto v1 = r->ints(10, 11, 1);
    EXPECT_EQ(v1.size(), 1);
    EXPECT_EQ(v1.at(0), 10);
}

TEST(RandomGeneratorTest, Ints_WhenRangeIsOneNegativeElemOnly_ThenExpectCertainElem)
{
    unique_ptr<RandomGenerator> r = std::make_unique<RandomGenerator>();

    auto v1 = r->ints(-5, -4, 1);
    EXPECT_EQ(v1.size(), 1);
    EXPECT_EQ(v1.at(0), -5);
}

TEST(RandomGeneratorTest, Ints_WhenDebugIsEnabled_ThenAllValuesEqual) 
{
    unique_ptr<RandomGenerator> r1 = std::make_unique<RandomGenerator>(true);
    unique_ptr<RandomGenerator> r2 = std::make_unique<RandomGenerator>(true);

    auto v1 = r1->ints(0, 100, 30);
    auto v2 = r2->ints(0, 100, 30);

    ASSERT_EQ(v1.size(), 30);
    ASSERT_EQ(v1.size(), v2.size());

    for (int i = 0; i < v1.size(); i++) {
        EXPECT_EQ(v1[i], v2[i]);
    }
}

TEST(RandomGeneratorTest, UniqueInts_WhenGivenRangIsLess_ThenExpectIncorrectRangeException)
{
    cout << "-- test unique ints \n";
    unique_ptr<RandomGenerator> r = std::make_unique<RandomGenerator>();
    
    EXPECT_THROW({
        auto v1 = r->unique_ints(0, 10, 20);  
    }, leetcode_utils::arrays::NotEnoughCapaciryException);
}

TEST(RandomGeneratorTest, UniqueInts_WhenGivenCorrectRange_ThenAllVauesUnique)
{
    cout << "-- test unique ints \n";
    unique_ptr<RandomGenerator> r = std::make_unique<RandomGenerator>();
    
    auto v1 = r->unique_ints(0, 20, 10);
    set<int> uniq_vals;

    for (auto elem : v1) {
        EXPECT_TRUE(uniq_vals.count(elem) == 0);
        uniq_vals.insert(elem);
    }
}

// TODO: rework test
TEST(RandomGenerator, UniqueSortedInts_WhenGivenRangeIsEnough_ThenValuesToBeSorted)
{
    cout << "-- test unique sorted ints \n";
    unique_ptr<RandomGenerator> r = std::make_unique<RandomGenerator>();
    auto v1 = r->unique_sorted_ints(0, 100, 10);
    
    ASSERT_EQ(v1.size(), 10);
}
