#include "leetcode_utils/trees/generator.h"
#include "leetcode_utils/random_ints.h"

using leetcode_utils::RandomGenerator;
using leetcode_utils::Generator;
using leetcode_utils::print_vector;
using leetcode_utils::TreeNode;

int main()
{
    RandomGenerator* rg = new RandomGenerator(0, 20, 10);
    auto vals = rg->unique_ints(true);
    print_vector(vals);

    Generator g;
    TreeNode* root = g.create(vals);
    cout << "Tree created\n";

    return 0;
}
