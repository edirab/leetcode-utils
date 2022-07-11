#pragma once

#include <string>
#include <queue>
#include <vector>
#include <iostream>
#include <stack>

using std::cout;
using std::string;
using std::vector;
using std::pair;
using std::queue;
using std::stack;

struct TreeNode 
{
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Codec 
{
public:

    const int null_number = -1111;
    
    /*
        Преобразовать строку [1,2,3,null,null,4,5] в вектор строк
        Преобразовать вектор строк в вектор чисел, null заменить на число, выходящее за диапазон
    */
    vector<int> parse_string(const string &data);

    // Encodes a tree to a single string.
    string serialize(TreeNode* root);

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data);
};
