#include <iostream>
#include <cstdio>
#include <vector>
#include "classes.hpp"

using namespace std;


int main()
{
/*
    number_ptr p = integer().build(1);
    cout<<"Integer creation"<<endl;
    p->display();

    number_ptr r = real().build(3);
    cout<<"Real creation"<<endl;
    r->display();
*/

    number_factory fact ;
    number_ptr q = fact.build( "integer" , 5);
    q->display ();
    q = fact.build( "real" , 42);

    q->display ();  
    return 0;   
}
