#include "leetcode_utils/trees/generator.h"
#include "leetcode_utils/trees/traversals.h"
#include "leetcode_utils/arrays/random_ints.h"
#include <gtest/gtest.h>
#include <memory>

using leetcode_utils::arrays::RandomGenerator;
using leetcode_utils::arrays::print_vector;
using leetcode_utils::trees::Generator;
using leetcode_utils::trees::Printer;
using leetcode_utils::trees::TreeNode;
using std::unique_ptr;

TEST(TraversalsTest, Printers_WhenGivenExampleTree_ThenPrintPreOrder)
{
    Generator g;
    unique_ptr<TreeNode> root(g.build_example_tree());
    Printer p;

    p.pre_order(root.get()); cout << "\n";
    p.in_order(root.get()); cout << "\n";
    p.post_order(root.get()); cout << "\n";
}

TEST(TraversalsTest, Printers_WhenGivenExampleTree_ThenPrintInOrder)
{
    Generator g;
    unique_ptr<TreeNode> root(g.build_example_tree());
    Printer p;

    p.in_order(root.get()); cout << "\n";
}


TEST(TraversalsTest, Printers_WhenGivenExampleTree_ThenPrintPostOrder)
{
    Generator g;
    unique_ptr<TreeNode> root(g.build_example_tree());
    Printer p;

    p.post_order(root.get()); cout << "\n";
}

TEST(TraversalsTest, Printers_WhenFromInts_ThenPrintBreadthFirst)
{
    unique_ptr<RandomGenerator> rg = std::make_unique<RandomGenerator>(0, 20, 10);
    auto vals = rg->unique_ints(true);

    print_vector(vals);
    Generator g;
    TreeNode* root_2 = g.create(vals);
    cout << "Tree created\n";
    Printer p;
    p.breadt_first(root_2); 
}
