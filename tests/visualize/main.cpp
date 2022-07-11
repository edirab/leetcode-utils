#include "leetcode_utils/trees/visualize.h"
#include "leetcode_utils/trees/generator.h"
#include "leetcode_utils/random_ints.h"

int main()
{
    RandomGenerator* rg = new RandomGenerator(0, 20, 10);
    auto vals = rg->unique_ints(true);

    Generator g;
    //print_vector(vals);
    TreeNode* root = g.create(vals);
    //cout << "Tree created\n";

    Visualizer vs;

    //string res = vs.get(root, false);
    string res = vs.to_dot(root, true);
    cout << res;

    return 0;
}
