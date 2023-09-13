#include "leetcode_utils/trees/generator.h"
#include "leetcode_utils/random_ints.h"
#include "leetcode_utils/trees/visualize.h"
#include "leetcode_utils/trees/traversals.h"
#include <memory>
#include <vector>
#include <gtest/gtest.h>

using std::vector;
using std::unique_ptr;
using leetcode_utils::RandomGenerator;
using leetcode_utils::Generator;
using leetcode_utils::print_vector;
using leetcode_utils::TreeNode;
using leetcode_utils::Visualizer;
using leetcode_utils::Getter;

TEST(BinaryTreeGenertorTest, CreateUnbalancedTree_WhenGivenData_ThenRootNotNull) {
    vector<int> vals = {1, 2, 3};
    Generator bin_tree_generator;
    unique_ptr<TreeNode> root(bin_tree_generator.create(vals));

    ASSERT_NE(root.get(), nullptr);
}

TEST(BinaryTreeGenertorTest, CreateUnbalancedTree_WhenGivenData_ThenLeftSubtreesEmpty) {
    vector<int> vals = {1, 2, 3};
    Generator bin_tree_generator;
    unique_ptr<TreeNode> root(bin_tree_generator.create(vals));

    /*
        1
            \
                2
                    \ 
                        3
    */
    ASSERT_NE(root.get(), nullptr);
    EXPECT_EQ(root.get()->left, nullptr);
    EXPECT_EQ(root.get()->right->left, nullptr);
    EXPECT_EQ(root.get()->right->right->left, nullptr);
}

TEST(BinaryTreeGenertorTest, CreateAndTraverseUnbalancedTree_WhenFromInts_ThenInorderTraversalIsIncreasing) {
    unique_ptr<RandomGenerator> rg = std::make_unique<RandomGenerator>(0, 20, 10);
    auto vals = rg->unique_ints(true);
    ASSERT_EQ(vals.size(), 10);

    cout << "# ";
    print_vector(vals);

    Generator g;
    unique_ptr<TreeNode> root(g.create(vals));
    ASSERT_NE(root.get(), nullptr);
    cout << "# Unbalanced tree created\n";

    Getter getter;
    auto vals_tree = getter.inorderTraversal(root.get());
    EXPECT_EQ(vals_tree.size(), 10);

    for (int i = 1; i < vals.size(); i++) {
        EXPECT_GE(vals_tree[i], vals_tree[i-1]);
    }
}

TEST(BinaryTreeGenertorTest, CreateBalancedTree_WhenFromInts_ThenHasLeftAndRightSubtree) {
    vector<int> vals = {1, 2, 3}; // sorted
    Generator bin_tree_generator;
    unique_ptr<TreeNode> root(bin_tree_generator.create_balanced(vals));
    cout << "# Balanced binary search tree created\n";

    ASSERT_NE(root.get(), nullptr);
    ASSERT_NE(root.get()->left, nullptr);
    ASSERT_NE(root.get()->left, nullptr);

    EXPECT_EQ(root.get()->val, 2);
    EXPECT_EQ(root.get()->left->val, 1);
    EXPECT_EQ(root.get()->right->val, 3);
}

TEST(BinaryTreeGenertorTest, CreateBalancedTree_WhenGivenData_ThenHasLeftAndRightSubtree)
{
    unique_ptr<RandomGenerator> rg = std::make_unique<RandomGenerator>(0, 20, 10);
    auto vals = rg->unique_sorted_ints(true);
    ASSERT_EQ(vals.size(), 10);
    cout << "# ";
    print_vector(vals);

    Generator bin_tree_generator;
    unique_ptr<TreeNode> root(bin_tree_generator.create_balanced(vals));
    ASSERT_NE(root.get(), nullptr);
    cout << "# Balanced binary search tree created\n";
    
    Getter getter;
    auto vals_tree = getter.inorderTraversal(root.get());
    ASSERT_EQ(vals.size(), 10);

    for (int i = 1; i < vals.size(); i++) {
        EXPECT_GE(vals_tree[i], vals_tree[i-1]);
    }

    Visualizer v;
    cout << v.to_dot(root.get()) << "\n";
}
