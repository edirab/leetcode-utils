
#include "leetcode_utils/traversals.h"

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

void Printer::breadt_first(TreeNode* root)
{
    int prev_level = 0;
    int level = 0;
    if (root == nullptr)
        return;

    queue <pair<TreeNode*, int>> q;
    q.push( std::make_pair(root, 1));
    level = 1;

    while(q.size())
    {
        auto curr = q.front();
        q.pop();

        if (curr.first != nullptr)
        {
            level = curr.second;

            if (level != prev_level)
            {
                prev_level = level;
                cout << "\nL" << level << ": ";
            }
            cout << curr.first->val << " ";
            q.push( std::make_pair( curr.first->left, curr.second + 1 ) );
            q.push( std::make_pair( curr.first->right, curr.second + 1 ) );
        }
    }
    cout << "\n";
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