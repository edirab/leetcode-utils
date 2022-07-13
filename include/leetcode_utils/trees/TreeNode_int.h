/*!
\file
\brief Заголовочный файл с описанием классов

Данный файл содержит в себе определения основных 
классов, используемых в демонстрационной программе
*/

#pragma once

namespace leetcode_utils
{

/*!
    \brief Struct for binary tree node.
    \details Data is an integer value. 
    Default values are zeros and nulls
*/
struct TreeNode 
{
    int val;
    TreeNode *left; ///< pointer to left subtree
    TreeNode *right; ///< pointer to right subtree

    /*!
        \brief Default constructor
    */
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

} // namespace leetcode_utils
