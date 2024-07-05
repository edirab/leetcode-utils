/*!
\file
\brief Заголовочный файл с описанием классов

Данный файл содержит в себе определения основных 
классов, используемых в демонстрационной программе
*/

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
namespace trees
{

/*!
    Class for printing tree to standart output
*/
class Printer
{
public:
    /*! 
        \brief Prints nodes in order (left, root, right)
        \details Method traverses tree recursively and prints nodes
        \param in root Pointer to struct TreeNode
    */
    void in_order(TreeNode *root);

    /*! 
        \brief Prints nodes in preorder (root, left, right)
        \details Method traverses tree recursively and prints nodes
        \param in root Pointer to struct TreeNode
    */
    void pre_order(TreeNode *root);

    /*! 
        \brief Prints nodes in postorder (left, right, root)
        \details Method traverses tree recursively and prints nodes
        \param in root Pointer to struct TreeNode
    */
    void post_order(TreeNode *root);

    /*! 
        \brief Print nodes in level order
        \details Method traverses tree in level-order and printes nodes.
                 Level numbers are also printed
        \param in root Pointer to struct TreeNode
    */
    void breadt_first(TreeNode* root);
};

/*!
    Class for obtainingt tree nodes in certain order
*/
class Getter
{
    public:
        vector<int> inorderTraversal(TreeNode* root);

    private:
        void do_inorder(TreeNode *root, vector<int> &result) ;
};

} // trees
} // namespace leetcode_utils
