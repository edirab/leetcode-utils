#pragma once

#include "TreeNode_int.h"
#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using std::cout;
using std::vector;
using std::queue;
using std::pair;

class Printer
{
public:
    void in_order(TreeNode *root);
    void pre_order(TreeNode *root);
    void post_order(TreeNode *root);
    void breadt_first(TreeNode* root);
};

class Getter
{
    public:
        vector<int> inorderTraversal(TreeNode* root);

    private:
        void do_inorder(TreeNode *root, vector<int> &result) ;
};