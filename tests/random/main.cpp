#include <iostream>
#include "leetcode_utils/random_ints.h"

using std::cout;

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
    cout << "-- test unique ints \n";
    RandomGenerator* r = new RandomGenerator(0, 100, 10);
    auto v1 = r->unique_ints();
    print_vector(v1);

    return;
}


void test_uniquenss_sorted()
{
    cout << "-- test unique sorted ints \n";
    RandomGenerator* r = new RandomGenerator(0, 100, 10);
    auto v1 = r->unique_sorted_ints();
    print_vector(v1);

    return;
}

int main()
{
    //test_ints();
    //test_uniquenss();
    test_uniquenss_sorted();

    return 0;
}
