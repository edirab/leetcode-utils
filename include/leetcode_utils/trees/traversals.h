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

namespace leetcode_utils
{

class Printer
{
public:
    // Prints nodes in order (left, root, right)
    void in_order(TreeNode *root);

    // Prints nodes in preorder (root, left, right)
    void pre_order(TreeNode *root);

    // Prints nodes in postorder (left, right, root)
    void post_order(TreeNode *root);

    // Print nodes in level order
    void breadt_first(TreeNode* root);
};

class Getter
{
    public:
        vector<int> inorderTraversal(TreeNode* root);

    private:
        void do_inorder(TreeNode *root, vector<int> &result) ;
};

} // namespace leetcode_utils