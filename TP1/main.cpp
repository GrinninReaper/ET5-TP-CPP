#include <iostream>
#include "rectangle.h"
#include "square.h"
#include <boost/swap.hpp>

using namespace std;

int main()
{
    square carre(2);;
    square carre2(3);
/*
    carre.setLng(3);
    cout<< carre.getLng() << " "<<carre.getLrg()<<endl;
    cout<< carre2.getLng() << " "<<carre2.getLrg()<<endl;
*/

    rectangle rect = rectangle();
    cout << rect << endl;
    cout << carre2 << endl;
    boost::swap(rect, static_cast<rectangle&>(carre2));
    cout << rect << endl;
    cout << carre2 << endl;

    test_area(&carre);
    cout<<"All done kiddo!"<<endl;
    return 0;
}
