
#include "traversals.h"

void Printer::in_order(TreeNode *root) 
{
    if (root == nullptr)
        return;

    this->in_order(root->left);
    cout << root->val << " ";
    this->in_order(root->right);

    return;
}

void Printer::pre_order(TreeNode *root)
{
    if (root == nullptr)
        return;
    
    cout << root->val << " ";
    this->pre_order(root->left);
    this->pre_order(root->right);
    return;
}

void Printer::post_order(TreeNode *root)
{
    if (root == nullptr)
        return;

    this->pre_order(root->left);
    this->pre_order(root->right);
    cout << root->val << " ";
    return;
}

void Getter::do_inorder(TreeNode *root, vector<int> &result) 
{
    if (root == nullptr)
        return;

    if (root->left){
        //result.push_back(root->left->val);
        do_inorder(root->left, result);
    }
    result.push_back(root->val);

    if (root->right){
        //result.push_back(root->right->val);
        do_inorder(root->right, result);
    }
}

vector<int> Getter::inorderTraversal(TreeNode* root) 
{        
    vector<int> result;
    this->do_inorder(root, result);
    return result;
}