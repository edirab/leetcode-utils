/*!
\file
\brief Заголовочный файл с описанием классов

Данный файл содержит в себе определения основных 
классов, используемых в демонстрационной программе
*/

#pragma once

#include <memory>
#include <vector>
#include <random>
#include <set>
#include <unordered_set>
#include <iostream>

using std::cout;
using std::vector;
using std::set;
using std::unordered_set;

namespace leetcode_utils
{
namespace arrays
{

/*!
    \brief Class for generation random integers in a specified range
    \details Those numbers are truely random from run to run
             unless you will pass debug=true parameter
*/
class RandomGenerator
{
    public:
        RandomGenerator();
        RandomGenerator(bool debug);

    /*!
        \brief Generates sequence of n in [from, to) range
               Can contain repetitions
        \return vector of random integers
    */
    vector<int> ints(int from, int to, int n);

    /*!
        \brief Generates sequence of n in [from, to) range without repetitions.
        \details NB: n cannot be greater then |from - to| value
        \return vector of random integers
    */
    vector<int> unique_ints(int from, int to, int n);

    /*!
        \brief Generates sorted sequence of n in [from, to) range without repetitions
        Suitable for bulding height-balanced trees with Generator class, testing binary search etc.
        \return vector of random integers
    */
    vector<int> unique_sorted_ints(int from, int to, int n);

    private:
        bool debug{false};
        std::unique_ptr<std::mt19937> gen;
};


void print_vector(vector<int> &v);

} // arrays
} // namespace leetcode_utils
