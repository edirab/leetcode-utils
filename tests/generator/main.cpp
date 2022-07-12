#include "leetcode_utils/trees/generator.h"
#include "leetcode_utils/random_ints.h"
#include "leetcode_utils/trees/visualize.h"

using leetcode_utils::RandomGenerator;
using leetcode_utils::Generator;
using leetcode_utils::print_vector;
using leetcode_utils::TreeNode;
using leetcode_utils::Visualizer;

void test_unbalanced_bst()
{
    RandomGenerator* rg = new RandomGenerator(0, 20, 10);
    auto vals = rg->unique_ints(true);
    cout << "# ";
    print_vector(vals);

    Generator g;
    TreeNode* root = g.create(vals);
    cout << "# Unbalanced tree created\n";
    return;
}

TreeNode* test_balanced_bst()
{
    RandomGenerator* rg = new RandomGenerator(0, 20, 10);
    auto vals = rg->unique_sorted_ints(true);
    cout << "# ";
    print_vector(vals);

    Generator g;
    TreeNode* root = g.create_balanced(vals);
    cout << "# Balanced binary search tree created\n";
    return root;
}


int main()
{
    // test_unbalanced_bst();
    TreeNode* root_2 =  test_balanced_bst();

    Visualizer v;
    cout << v.to_dot(root_2) << "\n";

    return 0;
}
