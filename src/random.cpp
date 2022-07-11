#include "leetcode_utils/random_ints.h"

//using leetcode_utils::RandomGenerator;
//using leetcode_utils::print_vector;

namespace leetcode_utils
{

vector<int> RandomGenerator::ints(bool debug)
{
    vector<int> result;
    std::mt19937* gen = nullptr;

    
    if (!debug)
    {
        std::random_device rd; // obtain a random number from hardware
        gen = new std::mt19937(rd());// seed the generator
    }
    else
    {
        gen = new std::mt19937();
    }
    std::uniform_int_distribution<> distr(this->from, this->to - 1); // define the range

    for(int n = 0; n < this->n; ++n)
        result.push_back( distr(*gen) );

    return result;
}

vector<int> RandomGenerator::unique_ints(bool debug)
{
    vector<int> result;
    if ( n <=  (this->to - this->from)  )
    {
        std::mt19937* gen = nullptr;

        if (!debug)
        {
            std::random_device rd; // obtain a random number from hardware
            gen = new std::mt19937(rd());// seed the generator
        }
        else
        {
            gen = new std::mt19937();
        }

        std::uniform_int_distribution<> distr(this->from, this->to - 1); // define the range
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
    }
    return result;
}


vector<int> RandomGenerator::unique_sorted_ints(bool debug)
{
    vector<int> result;
    if ( n <=  (this->to - this->from)  )
    {
        std::mt19937* gen = nullptr;

        if (!debug)
        {
            std::random_device rd; // obtain a random number from hardware
            gen = new std::mt19937(rd());// seed the generator
        }
        else
        {
            gen = new std::mt19937();
        }

        std::uniform_int_distribution<> distr(this->from, this->to - 1);
        set<int> unique;

        while( unique.size() < n )
        {
            int val =  distr(*gen);
            if ( unique.count(val) == 0 )
            {
                unique.insert(val);
            }
        }

        for (auto elem : unique)
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

} // namespace leetcode_utils
