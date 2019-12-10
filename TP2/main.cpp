#include <iostream>
#include <cstdio>
#include <vector>
#include "classes.hpp"

using namespace std;

void f1 ( T const&) {}
void f2 ( T ) {}
T f3 () { return T (); }

T f4 () { T t ; return t ; }
void f5 ( T & t ) { t = T (); }

void g2(file) {}

struct U {
    T v1 , v2 ;
    U ( T const & t ): v2 ( t ) { v1 = t ; }
};

int main()
{
/*
        //EX1
    T a;
    f1 ( a );
    f2 ( a );
    T b = a;
    T c = f3 ();
    T d = f4 ();
    f5 ( d );
    U e ( a );
*/

/*
        //EX2
    file f ( " test1 . txt " );
    f . write ( " first string for test1 \n " );
    file g ( " test2 . txt " );
    g . write ( " first string for test2 \n " );
    f . write ( " second string for test1 \n " );
*/
/*
        //EX3
    file f ( " test3 . txt " );
    f . write( " first string for test3 \ n " );
    file g(std::move(f));
    g . write ( " second string for test3 \ n " );
*/


        //EX4
    node_ptr a (new node("a"));
    node_ptr b (new node("b"));
    node_ptr c (new node("c"));
    node_ptr d (new node("d"));
    a->add_child(b);
    a->add_child(c);
    d->add_child(b);
    //delete a; //EX4
    a.reset(); //EX5
    b->get_parents();
    return 0;


    
    
}
