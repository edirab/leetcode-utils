#include "leetcode_utils/trees/codec.h"
#include <gtest/gtest.h>
#include <string>
#include <memory>

using namespace leetcode_utils;
using std::string;
using std::unique_ptr;

class DeserializeFixture : public ::testing::Test {
    public:

    protected:
        Codec c;
        unique_ptr<TreeNode> root_1;
};

TEST_F(DeserializeFixture, Deserialize_WhenEmptyListGiven_ThenExpectEmptyTree) {
    string data = "[]";
    c.parse_string(data);
    root_1.reset(c.deserialize(data));

    EXPECT_EQ(root_1.get(), nullptr);
}

/*
            1
        /
    2
*/
TEST_F(DeserializeFixture, Deserialize_WhenSpecificListGiven_ThenExpectSpecificTree) {
    string data = "[1,2]";
    root_1.reset(c.deserialize(data));

    ASSERT_NE(root_1.get(), nullptr);
    EXPECT_EQ(root_1.get()->val, 1);

    ASSERT_NE(root_1.get()->left, nullptr);
    EXPECT_EQ(root_1.get()->left->val, 2);

    EXPECT_EQ(root_1.get()->right, nullptr);
}

TEST_F(DeserializeFixture, Deserialize_WhenNullGivenGiven_ThenExpectCorrectTree) {
    string data = "[1,2,3,null,null,4,5]";
    root_1.reset(c.deserialize(data));

    ASSERT_NE(root_1.get(), nullptr);
    EXPECT_EQ(root_1.get()->val, 1);

    ASSERT_NE(root_1.get()->left, nullptr);
    EXPECT_EQ(root_1.get()->left->val, 2);

    ASSERT_NE(root_1.get()->right, nullptr);
    EXPECT_EQ(root_1.get()->right->val, 3);

    ASSERT_EQ(root_1.get()->left->left, nullptr);
    ASSERT_EQ(root_1.get()->left->right, nullptr);

    ASSERT_NE(root_1.get()->right->left, nullptr);
    ASSERT_NE(root_1.get()->right->right, nullptr);

    EXPECT_EQ(root_1.get()->right->left->val, 4);
    EXPECT_EQ(root_1.get()->right->right->val, 5);
}
