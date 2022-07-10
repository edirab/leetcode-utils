#include "leetcode_utils/generator.h"
#include "leetcode_utils/random_ints.h"


int main()
{
    RandomGenerator* rg = new RandomGenerator(0, 20, 10);
    auto vals = rg->unique_ints(true);

    print_vector(vals);
    TreeNode* root = create(vals);
    cout << "Tree created\n";

    return 0;
}
