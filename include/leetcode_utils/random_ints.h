#pragma once

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

/*
    Those numbers are truely random from run to run
    unless you will pass debug=true parameter
*/
class RandomGenerator
{
    public:
        RandomGenerator();
        RandomGenerator(int from, int to, int n) :
            from(from), to(to), n(n)
        {};

    /*
        Generates sequence of n in [from, to) range
        Can contain repetitions
    */
    vector<int> ints(bool debug = false);

    /*
        Generates sequence of n in [from, to) range without repetitions
    */
    vector<int> unique_ints(bool debug = false);

    /*
        Generates sorted sequence of n in [from, to) range without repetitions
        Suitable for bulding height-balanced trees, testing binary search etc.
    */
    vector<int> unique_sorted_ints(bool debug = false);

    private:
        int from{0};
        int to{100};
        int n{10};
};


void print_vector(vector<int> &v);

} // namespace leetcode_utils