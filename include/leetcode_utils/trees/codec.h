/*!
\file
\brief Class for serialization and deserialization of a tree
*/

#pragma once
#include <string>
#include <vector>
#include "TreeNode_int.h"

using std::string;
using std::vector;

namespace leetcode_utils
{
namespace trees
{

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
        \brief Conversion of string to array of integers
        \details Method converts a string with serialized tree (e.i. `[1,2,3,null,null,4,5]`) to vector of integers.
        All `null`'s are substituted with magic number null_number
        \param[in] data reference to string representation
        \return vector of integers
    */
    vector<int> parse_string(const string &data);

    /*! 
        \brief Encodes a tree to a single string.
        \param[in] root pointer to tree's root TreeNode struct
        \return data string with decoded tree
    */
    string serialize(TreeNode* root);

    /*! 
        \brief Decodes your encoded string data to tree.
        \param[in] data string with encoded tree
        \return pointer to TreeNode struct
    */
    TreeNode* deserialize(string data);
};

} // trees
} // namespace leetcode_utils
