#include <iostream>

#include <cstdio>
#include <vector>
#include "classes.hpp"

using namespace std;

int main()
{
/*
        //2.1
        small_array <int,4> t ;
        t.at(2) = 42;
        small_array <int,4> const u = t ;
        for (std::size_t i = 0; i < 4; i++) {
            std :: cout << "[ " << i << " ] = " << u.at(i) << endl;
        }
        t.at(4) = 0; // assertion failed !
*/

    large_array<int, 1000 * 1000 * 10> t ;
    t [2] = 42;
    t.at(2) = 42;
    large_array <int,1000 * 1000 * 10> u;
    u = t;


    for (std::size_t i = 0; i < 4; i++) {
        std :: cout << "[ " << i << " ] = " << u.at(i) << endl;
    }

    t[2] = 32;
    t.swap(u);
    for (std::size_t i = 0; i < 4; i++) {
        std :: cout << "[ " << i << " ] = " << u.at(i) << endl;
    }


    return 0;
}
