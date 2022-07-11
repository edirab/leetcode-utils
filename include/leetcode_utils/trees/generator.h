#pragma once

#include <vector>
#include "leetcode_utils/trees/TreeNode_int.h"

using std::vector;

namespace leetcode_utils
{

class Generator
{
    public:
        TreeNode* build_example_tree();

        /*
            Creates unbalanced binary esearch tree.
            Root will be a first array element
        */
        TreeNode* create( vector<int>& values );    

    private:
        /*
            Inserts new value in a tree
        */
        void insert( TreeNode** root, int val );
};

} // namespace leetcode_utils
