/*!
\file
\brief Заголовочный файл с описанием классов

Данный файл содержит в себе определения основных 
классов, используемых в демонстрационной программе
*/

#pragma once

#include <vector>
#include "leetcode_utils/trees/TreeNode_int.h"

using std::vector;

namespace leetcode_utils
{

/*!
    \brief Class for generating binary trees
*/
class Generator
{
    public:
        /*!
        \brief generates a pre-defined small binary tree. For debugging purposes
        \return pointer to a root of newly created tree
        */
        TreeNode* build_example_tree();

        /*!
            \brief Creates unbalanced binary search tree
            \details Root will be a first array element
            \param[in] values vector of ints
            \return pointer to a root of newly created tree
        */
        TreeNode* create( vector<int>& values );    

        /*!

            \brief Creates hight-balanced binary search tree
            \details Root will be a midst array element
            \param[in] values a sorted vector of ints
            \return pointer to a root of newly created tree
        */
        TreeNode* create_balanced( vector<int>& values );

    private:
        /*!
            \brief Inserts new value in a tree
            \param[in,out] root If *root is null then tree is empty and initial root node will be created
            \param[in] val Value to insert
        */
        void insert( TreeNode** root, int val );
};

} // namespace leetcode_utils
