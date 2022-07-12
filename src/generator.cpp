#include "leetcode_utils/trees/generator.h"

// using leetcode_utils::Generator;
// using leetcode_utils::TreeNode;

namespace leetcode_utils 
{

TreeNode* Generator::build_example_tree() 
{
    TreeNode *A_node = new TreeNode( 5 );
    TreeNode *B_node = new TreeNode( 4 );
    TreeNode *C_node = new TreeNode( 8 );
    TreeNode *D_node = new TreeNode( 11 );
    TreeNode *E_node = new TreeNode( 13 );
    TreeNode *F_node = new TreeNode( 14 );
    TreeNode *G_node = new TreeNode( 7 );
    TreeNode *H_node = new TreeNode( 2 );
    TreeNode *I_node = new TreeNode( 1 );

    A_node->left = B_node;
    A_node->right = C_node;

    B_node->left = D_node;

    C_node->left = E_node;
    C_node->right = F_node;

    D_node->left = G_node;
    D_node->right = H_node;

    F_node->right = I_node;
    return A_node;
}


void Generator::insert( TreeNode** root, int val )
{
    if (*root == nullptr)
    {
        *root = new TreeNode(val);
        return;
    }

    if ((*root)->left == nullptr && (*root)->right == nullptr)
    {
        if (val < (*root)->val)
            (*root)->left = new TreeNode(val);
        else
            (*root)->right= new TreeNode(val);
    }
    else
    {
        if (val < (*root)->val)
        {
            insert( &((*root)->left), val);
        }
        else
        {
            insert( &((*root)->right), val);
        }        
    }
    return;
}


TreeNode* Generator::create( vector<int> & values )
{
    TreeNode* root = nullptr;

    int i = 0;
    while( i < values.size())
    {
        this->insert(&root, values[i]);
        i++;
    }
    return root;
}

// TODO
void create_balanced_tree(TreeNode** root, vector<int> &nums, int start, int stop)
{
    if (*root == nullptr && start <= stop)
    {
        int middle = (start + stop) / 2;
        *root = new TreeNode(nums[middle]);

        // for left subtree
        if (start != stop) create_balanced_tree(&((*root)->left), nums, start, middle-1 );
        //for right subtree
        if (start != stop) create_balanced_tree(&((*root)->right), nums, middle + 1, stop );
    }
    return;
}


TreeNode* Generator::create_balanced( vector<int>& values )
{
    TreeNode* root = nullptr;
    create_balanced_tree(&root, values, 0, values.size() - 1);
    return root;
}

} // namespace leetcode_utils


