#include "generator.h"
#include "traversals.h"




int main()
{

    TreeNode* root = build_example_tree();
    Printer p;

    p.pre_order(root); cout << "\n";
    p.in_order(root); cout << "\n";
    p.post_order(root); cout << "\n";
    
    return 0;
}