#pragma once

#include "TreeNode_int.h"
#include <iostream>
#include <vector>

using std::cout;
using std::vector;

class Printer
{
public:
    void in_order(TreeNode *root);
    void pre_order(TreeNode *root);
    void post_order(TreeNode *root);
};

class Getter
{
    public:
        vector<int> inorderTraversal(TreeNode* root);

    private:
        void do_inorder(TreeNode *root, vector<int> &result) ;
};