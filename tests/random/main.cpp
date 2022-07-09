#include <iostream>
#include <random_ints.h>

using std::cout;

void print_vector(vector<int> v)
{
    for (auto& elem : v)
        cout << elem << " ";
    cout << "\n";
    return;
}

void test_ints()
{
    cout << "-- test_ints \n";
    RandomGenerator* r = new RandomGenerator(0, 100, 30);
    auto v1 = r->ints();
    print_vector(v1);

    auto v2 = r->ints();
    print_vector(v2);

    auto v3 = r->ints(true);
    print_vector(v3);
    return;
}


void test_uniquenss()
{
    cout << "-- test_uniquenss \n";
    RandomGenerator* r = new RandomGenerator(0, 100, 30);
    auto v1 = r->ints();
    cout << "Seq 1: \n";
    print_vector(v1);

    vector<int> res;
    set<int> unique;
    for (auto elem: v1)
        unique.insert(elem);

    for (auto elem : unique)
        res.push_back(elem);

    print_vector(res);
    return;
}


int main()
{
    //test_ints();
    test_uniquenss();

    return 0;
}
