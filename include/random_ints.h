#include <vector>
#include <random>
#include <set>
#include <unordered_set>

using std::vector;
using std::set;
using std::unordered_set;

/*
    Those numbers are truely random from run to run
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

    vector<int> unique_ints(bool debug = false);

    /*
        TODO: reqork this shit
        Generates sorted sequence of <whatever> in [from, to) range
    */
    vector<int> unique_sorted_ints(bool debug = false);

    private:
        int from{0};
        int to{100};
        int n{10};
};
