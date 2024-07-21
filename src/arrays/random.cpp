#include "leetcode_utils/arrays/random_ints.h"

//using leetcode_utils::RandomGenerator;
//using leetcode_utils::print_vector;

namespace leetcode_utils
{
namespace arrays
{

RandomGenerator::RandomGenerator() : RandomGenerator(false) {}

RandomGenerator::RandomGenerator(bool debug)
{
    if (!debug)
    {
        std::random_device rd; // obtain a random number from hardware
        gen = std::make_unique<std::mt19937>(rd());// seed the generator
    }
    else
    {
        gen = std::make_unique<std::mt19937>();
    }
}

vector<int> RandomGenerator::ints(int from, int to, int n)
{
    vector<int> result;
    std::uniform_int_distribution<> distr(from, to - 1); // define the range

    for(int i = 0; i < n; ++i)
        result.push_back( distr(*gen) );

    return result;
}

vector<int> RandomGenerator::unique_ints(int from, int to, int n)
{
    vector<int> result;
    if ( n <=  (to - from)  )
    {
        std::uniform_int_distribution<> distr(from, to - 1); // define the range
        unordered_set<int> unique;

        while( unique.size() < n )
        {
            int val =  distr(*gen);
            if ( unique.count(val) == 0 )
            {
                result.push_back( val );
                unique.insert(val);
            }
        }
    }
    else
    {
        cout << "Wrong range specified. Not enough uniqe nums in a range\n";
        throw "Wrong range specified. Not enough uniqe nums in a range";
    }
    return result;
}


vector<int> RandomGenerator::unique_sorted_ints(int from, int to, int n)
{
    vector<int> result;
    if ( n <=  (to - from)  )
    {
        std::uniform_int_distribution<> distr(from, to - 1);
        set<int> unique_elems_set;

        while( unique_elems_set.size() < n )
        {
            int val =  distr(*gen);
            if ( unique_elems_set.count(val) == 0 )
            {
                unique_elems_set.insert(val);
            }
        }

        for (auto elem : unique_elems_set)
        {
            result.push_back(elem);
        }
    }
    else
    {
        cout << "Wrong range specified. Not enough uniqe nums in a range\n";
    }
    return result;
}


void print_vector(vector<int> &v)
{
    for (auto& elem : v)
        cout << elem << " ";
    cout << "\n";
    return;
}

} // arrays
} // namespace leetcode_utils
