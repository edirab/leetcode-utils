#include "leetcode_utils/trees/visualize.h"

//using leetcode_utils::Visualizer;

namespace leetcode_utils 
{

string Visualizer::to_dot(TreeNode* root, bool draw_nulls)
{
    string res = "digraph G {\n";
    
    if (root == nullptr)
    {
        res += "\tnull";
    }
    else
    {
        stack<TreeNode*> st;
        st.push(root);

        // implement iterative preorder traversal
        while(st.size())
        {
            TreeNode* curr = st.top();
            st.pop();

            if (curr->left != nullptr || curr->right != nullptr)
            {
                if (curr->left)
                {
                    res += "\t" + std::to_string(curr->val) + " -> " + std::to_string(curr->left->val) + " [color=blue]" + "\n";
                    st.push(curr->left);
                }
                else if (draw_nulls)
                {
                    res += "\t" + std::to_string(curr->val) + " -> n_" + std::to_string(curr->val) + " [color=blue]" + "\n";
                }
                // ----
                if (curr->right)
                {
                    res += "\t" + std::to_string(curr->val) + " -> " + std::to_string(curr->right->val) + "\n";
                    st.push(curr->right);
                }            
                else if (draw_nulls)
                {
                    res += "\t" + std::to_string(curr->val) + " -> n_" + std::to_string(curr->val) + "\n";
                }                
            }
        }
    }

    res += "}\n";
    return res;
}

} // namespace leetcode_utils