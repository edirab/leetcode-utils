#include "random_ints.h"

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

}

vector<int> RandomGenerator::unique_sorted_ints(bool debug)
{
    const auto v = this->ints(debug);
    vector<int> res;
    set<int> unique;

    for (auto elem: v)
    {
        unique.insert(elem);
    }

    for (auto elem : unique)
    {
        res.push_back(elem);
    }
    return res;
}