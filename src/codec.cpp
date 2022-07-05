/*
    Tags:

    #trees
    #construct tree
    #build tree
    #serialize
    #desereialize
*/

#include "codec.h"

vector<int> Codec::parse_string(const string &data)
{
    vector<int> nodes;
    if (data == "[]")
        return nodes;

    string data_(data.begin()+1, data.end()-1);
    vector<string> nodes_str;
    
    string token;

    size_t i = 0;   // отбрасываем открывающиеся квадратные скобки
    int curr_comma_pos = 0;

    /*
        Разбиваем строку на подстроки
    */
    while( curr_comma_pos != string::npos )
    {
        curr_comma_pos = data_.find(',', i);
        token = data_.substr(i, curr_comma_pos - i);
        i = curr_comma_pos + 1;
        //cout << token << " ";
        nodes_str.push_back(token);
    }

    for (auto elem: nodes_str)
    {
        if (elem == "null")
            nodes.push_back(null_number);
        else
            nodes.push_back(std::stoi(elem));
    }
    return nodes;
}

string Codec::serialize(TreeNode* root)
{
    string result;
    vector<string> values;

    if (root == nullptr)  
        return string("[]");
    
    queue<TreeNode*> nodes_queue;
    nodes_queue.push(root);

    result = "[";
    while( !nodes_queue.empty() )
    {
        TreeNode* curr_node = nodes_queue.front();
        nodes_queue.pop();

        if (curr_node == nullptr)
            values.push_back("null");
            //result +=  "null,";
        else
            //result += string (std::to_string(curr_node->val) + ",");
            values.push_back(std::to_string(curr_node->val));

        if (curr_node)
        {
            nodes_queue.push(curr_node->left);
            nodes_queue.push(curr_node->right);
        }
    }

    // Необходимо удалить все конечные "null"
    for( auto it = values.end() - 1; it != values.begin(); --it)
    {
        if (*it == "null")
            values.erase(it);
        else
            break;
    }

    for (auto elem: values)
        result += string(elem + ",");

    result[result.length() - 1 ] = ']';
    return result;
}


TreeNode* Codec::deserialize(string data) 
{
    vector<int> nodes = this->parse_string(data);

    if (nodes.empty())
        return nullptr;

    
    TreeNode *root = new TreeNode( *nodes.begin() );
    queue<TreeNode*> nodes_queue;
    nodes_queue.push(root);

    size_t i = 1;
    while( i < nodes.size() )
    {
        TreeNode* curr_root = nodes_queue.front();
        nodes_queue.pop();

        if (nodes[i] != null_number)
        {
            TreeNode* new_left = new TreeNode(nodes[i]);
            curr_root->left = new_left;
            nodes_queue.push(new_left);
            
        }
        i++;

        if (i < nodes.size() && nodes[i] != null_number)
        {
            TreeNode* new_right = new TreeNode(nodes[i]);
            curr_root->right = new_right;
            nodes_queue.push(new_right);
            
        }
        i++;   
    }
    return root;
}




