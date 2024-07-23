#include <vector>
#include <gtest/gtest.h>
#include "leetcode_utils/leetcode_utils.h"

using std::vector;
using leetcode_utils::lists::Generator;

TEST(ListGeneratorTest, GivenEmptyVector_ListCreation_ExpectCorrectValues) {
    vector<int> values = {};
    Generator g;
    auto l1 = g.from_vector(values);

    EXPECT_EQ(l1, nullptr);
}

TEST(ListGeneratorTest, GivenSigleElementVector_ListCreation_ExpectCorrectValues) {
    vector<int> values = {42};
    Generator g;
    auto l1 = g.from_vector(values);

    EXPECT_NE(l1, nullptr);
    EXPECT_EQ(l1->val, 42);
    EXPECT_EQ(l1->next, nullptr);
}

TEST(ListGeneratorTest, GivenVector_ListCreation_ExpectCorrectValues) {
    vector<int> values = {2, 4, 6, 8};
    Generator g;
    auto l1 = g.from_vector(values);

    EXPECT_NE(l1, nullptr);
    EXPECT_EQ(l1->val, values.at(0));
    EXPECT_EQ(l1->next->val, values.at(1));
    EXPECT_EQ(l1->next->next->val, values.at(2));
    EXPECT_EQ(l1->next->next->next->val, values.at(3));
    EXPECT_EQ(l1->next->next->next->next, nullptr);
}

TEST(ListGeneratorTest, ToVector_WhenCreatedFromOtherVector_ExpectCorrectValues) {
    vector<int> values = {2, 4, 6, 8};
    Generator g;
    auto l1 = g.from_vector(values);

    EXPECT_NE(l1, nullptr);
    auto res = g.to_vector(l1);

    EXPECT_EQ(values, res);
}
