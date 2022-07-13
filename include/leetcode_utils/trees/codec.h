/*!
\file
\brief Заголовочный файл с описанием классов

Данный файл содержит в себе определения основных 
классов, используемых в демонстрационной программе
*/

#pragma once

#include <string>
#include <queue>
#include <vector>
#include <iostream>
#include <stack>
#include "TreeNode_int.h"

using std::cout;
using std::string;
using std::vector;
using std::pair;
using std::queue;
using std::stack;

namespace leetcode_utils
{

// struct TreeNode 
// {
//       int val;
//       TreeNode *left;
//       TreeNode *right;
//       TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

/*!
    \brief Class for serializing and deserializing trees
    \details This class can serialize/deserialize binary trees in LeetCode format: `[1,2,3,null,null,4,5]`
    Useful for debugging specific test cases. See example in tests/codec/main.cpp.
    A deserialized tree can be visualized with a help of Visualizer class

*/
class Codec 
{
public:

    const int null_number = -1111; ///< magic number for proper conversion of "null". Suitable for most cases
    
    /*!
        \brief 
        Преобразовать строку [1,2,3,null,null,4,5] в вектор строк
        Преобразовать вектор строк в вектор чисел, null заменить на число, выходящее за диапазон
    */
    vector<int> parse_string(const string &data);

    /*! 
        \brief Encodes a tree to a single string.
        \param in root pointer to tree's root TreeNode struct
        \return data string with decoded tree
    */
    string serialize(TreeNode* root);

    /*! 
        \brief Decodes your encoded string data to tree.
        \param in data string with encoded tree
        \return pointer to TreeNode struct
    */
    TreeNode* deserialize(string data);
};

} // namespace leetcode_utils