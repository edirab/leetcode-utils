#include "leetcode_utils/generator.h"
#include "leetcode_utils/traversals.h"
#include "leetcode_utils/random_ints.h"



int main()
{

    TreeNode* root = build_example_tree();
    Printer p;

    p.pre_order(root); cout << "\n";
    p.in_order(root); cout << "\n";
    p.post_order(root); cout << "\n";
    
    RandomGenerator* rg = new RandomGenerator(0, 20, 10);
    auto vals = rg->unique_ints(true);

    print_vector(vals);
    TreeNode* root_2 = create(vals);
    cout << "Tree created\n";
    p.breadt_first(root_2);

    return 0;
}