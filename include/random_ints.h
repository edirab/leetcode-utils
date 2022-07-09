#include <vector>
#include <random>

using std::vector;

class RandomGeneraor
{

    public:
        RandomGeneraor();
        RandomGeneraor(int from, int to, int n) :
            from(from), to(to), n(n)
        {};

    vector<int> generate_ints();

    private:
        int from{0};
        int to{100};
        int n{10};
};
