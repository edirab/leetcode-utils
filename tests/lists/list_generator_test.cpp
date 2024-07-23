#include <vector>
#include <unordered_set>
#include <algorithm>
#include <gtest/gtest.h>
#include "leetcode_utils/leetcode_utils.h"

using std::vector;
using leetcode_utils::lists::ListGenerator;

bool is_sorted(vector<int>& vals) {
    return std::is_sorted(vals.begin(), vals.end());
}

bool is_unique(vector<int>& vals) {
    unordered_set<int> unique_vals;
    for (auto elem : vals) {
        if (unique_vals.count(elem) != 0) {
            return false;
        }
        unique_vals.insert(elem);
    }
    return true;
}

TEST(ListGeneratorTest, GivenEmptyVector_ListCreation_ExpectCorrectValues) {
    vector<int> values = {};
    ListGenerator g;
    auto l1 = g.from_vector(values);

    EXPECT_EQ(l1, nullptr);
}

TEST(ListGeneratorTest, GivenSigleElementVector_ListCreation_ExpectCorrectValues) {
    vector<int> values = {42};
    ListGenerator g;
    auto l1 = g.from_vector(values);

    EXPECT_NE(l1, nullptr);
    EXPECT_EQ(l1->val, 42);
    EXPECT_EQ(l1->next, nullptr);
}

TEST(ListGeneratorTest, GivenVector_ListCreation_ExpectCorrectValues) {
    vector<int> values = {2, 4, 6, 8};
    ListGenerator g;
    auto l1 = g.from_vector(values);

    EXPECT_NE(l1, nullptr);
    EXPECT_EQ(l1->val, values.at(0));
    EXPECT_EQ(l1->next->val, values.at(1));
    EXPECT_EQ(l1->next->next->val, values.at(2));
    EXPECT_EQ(l1->next->next->next->val, values.at(3));
    EXPECT_EQ(l1->next->next->next->next, nullptr);
}

TEST(ListGeneratorTest, ToVector_WhenCreatedFromOtherEmptyVector_ExpectCorrectValues) {
    vector<int> values = {};
    ListGenerator g;
    auto l1 = g.from_vector(values);

    EXPECT_TRUE(l1 == nullptr);
    auto res = g.to_vector(l1);

    EXPECT_TRUE(res.empty());
    EXPECT_EQ(values, res);
}

TEST(ListGeneratorTest, ToVector_WhenCreatedFromOtherNonEmptyVector_ExpectCorrectValues) {
    vector<int> values = {2, 4, 6, 8};
    ListGenerator g;
    auto l1 = g.from_vector(values);

    EXPECT_NE(l1, nullptr);
    auto res = g.to_vector(l1);

    EXPECT_EQ(values, res);
}

TEST(ListGeneratorTest, FromUniqueInts_WhenGivenCorrectRange_ExpectUniqueValues) {
    ListGenerator g;
    auto l1 = g.from_unique_ints(0, 100, 20);
    auto res = g.to_vector(l1);

    EXPECT_FALSE(res.empty());
    EXPECT_TRUE(is_unique(res));
}

TEST(ListGeneratorTest, FromUniqueSortedInts_WhenGivenCorrectRange_ExpectUniqueValues) {
    ListGenerator g;
    auto l1 = g.from_unique_sorted_ints(0, 100, 20);
    auto res = g.to_vector(l1);

    EXPECT_FALSE(res.empty());
    EXPECT_TRUE(is_sorted(res));
    EXPECT_TRUE(is_unique(res));
}
