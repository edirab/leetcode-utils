#include "random_ints.h"

vector<int> RandomGeneraor::generate_ints()
{
    vector<int> result;

    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(25, 63); // define the range

    for(int n=0; n<40; ++n)
        result.push_back( distr(gen) );

    return result;
}
