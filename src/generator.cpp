#include "generator.h"

TreeNode *build_example_tree() 
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

