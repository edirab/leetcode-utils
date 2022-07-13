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

class Generator
{
    public:
        /*!
        Копирует содержимое из исходной области памяти в целевую область память
        \param[out] dest Целевая область памяти
        \param[in] src Исходная область памяти
        \param[in] n Количество байтов, которые необходимо скопировать
        */
        TreeNode* build_example_tree();

        /*
            Creates unbalanced binary esearch tree.
            Root will be a first array element
        */
        TreeNode* create( vector<int>& values );    

        TreeNode* create_balanced( vector<int>& values );

    private:
        /*
            Inserts new value in a tree
        */
        void insert( TreeNode** root, int val );
};

} // namespace leetcode_utils
