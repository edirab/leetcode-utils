#include "leetcode_utils/arrays/random_ints.h"

//using leetcode_utils::RandomGenerator;
//using leetcode_utils::print_vector;
using leetcode_utils::arrays::IncorrectRangeException;

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

void RandomGenerator::checkRange(int from, int to) {
    if (from >= to) {
        throw IncorrectRangeException(from, to);
    }
    return;
}

void RandomGenerator::checkCapacity(int from, int to, int nums) {
    if (nums >  (to - from))
    {
        throw NotEnoughCapaciryException(from, to, nums);
    }
}

vector<int> RandomGenerator::ints(int from, int to, int n)
{
    checkRange(from, to);

    vector<int> result;
    std::uniform_int_distribution<> distr(from, to - 1); // define the range

    for(int i = 0; i < n; ++i)
        result.push_back( distr(*gen) );

    return result;
}

vector<int> RandomGenerator::unique_ints(int from, int to, int n)
{
    checkRange(from, to);
    checkCapacity(from, to, n);

    vector<int> result;

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
    return result;
}


vector<int> RandomGenerator::unique_sorted_ints(int from, int to, int n)
{
    checkRange(from, to);
    checkCapacity(from, to, n);

    vector<int> result;

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

    return result;
}

// TODO: finish
void RandomGenerator::reset() {
    gen->seed();
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
