/*!
\file
\brief 
*/

#pragma once

#include "TreeNode_int.h"
#include <iostream>
#include <string>
#include <stack>
//#include <format> // C++ 20

using std::cout;
using std::string;
using std::stack;

namespace leetcode_utils
{
namespace trees
{

/*!
    \brief Class for getting visaul representation of a binary tree
*/
class Visualizer
{
    public:
        /*!
            \brief Converts tree to dot language representation.
            \details Output can be redirected to file and rendered with graphviz.
            TODO: add example command

            \param[in] root pointer to TreeNode strunc
            \param[in] draw_nulls If set to true, leaves will be rendered as "n_<parent_num>".
            Only applicable for nodes with ome null and one non-null leaf
            \return string with text representation
        */
        string to_dot(TreeNode* root, bool draw_nulls=true);

    private:

};

} // trees
} // namespace leetcode_utils
