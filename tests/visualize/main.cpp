#include "leetcode_utils/trees/visualize.h"
#include "leetcode_utils/trees/generator.h"
#include "leetcode_utils/arrays/random_ints.h"

using leetcode_utils::arrays::RandomGenerator;
using leetcode_utils::arrays::print_vector;
using leetcode_utils::trees::Generator;
using leetcode_utils::trees::Visualizer;
using leetcode_utils::trees::TreeNode;

int main()
{
    RandomGenerator* rg = new RandomGenerator(0, 20, 10);
    auto vals = rg->unique_ints(true);

    Generator g;
    cout << "# ";
    print_vector(vals);
    TreeNode* root = g.create(vals);
    cout << "# Tree created\n";

    Visualizer vs;

    //string res = vs.get(root, false);
    string res = vs.to_dot(root, true);
    cout << res;

    return 0;
}
