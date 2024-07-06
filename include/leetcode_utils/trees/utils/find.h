#pragma once

#include <iostream>
#include "../TreeNode_int.h"

using std::cout;

namespace leetcode_utils
{
namespace trees
{
namespace utils 
{

TreeNode* found = nullptr;

void dfs(TreeNode* root, int val)
{
    if (found != nullptr)
        return;

    if (root == nullptr) 
        return;

    if (root->val == val) {
        found = root;
        return;
    }
    dfs(root->left, val);
    dfs(root->right, val);
}


TreeNode* find(TreeNode* root, int val) {

    found = nullptr;
    dfs(root, val);
    return found;
}

} // utils
} // trees
} // leetcode_utils
