#pragma once

#include "leetcode_utils/TreeNode_int.h"
#include "leetcode_utils/random_ints.h"

class Generator
{
    public:
        TreeNode* build_example_tree();
        TreeNode* create( vector<int>& values );    

    private:
        void insert( TreeNode** root, int val );
};
