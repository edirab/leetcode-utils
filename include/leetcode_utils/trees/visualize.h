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

class Visualizer
{
    public:
        /*
            Converts tree to dot language representation.
            Suitable for graphviz
        */
        string to_dot(TreeNode* root, bool draw_nulls=true);

    private:

};

} // namespace leetcode_utils