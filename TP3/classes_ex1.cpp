#include "classes.hpp"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>

using namespace std;


//class integer
number_ptr integer::build(int init){
    value = init;
    number_ptr rslt = make_unique<integer>(*this);
    return rslt;
}

void integer::display(){
    cout<< "(integer) " << this->value << endl;
}


//class real
number_ptr real::build(int init){
    value = init;
    number_ptr rslt = make_unique<real>(*this);
    return rslt;
}

void real::display(){
    cout<< "(real) " << this->value << endl;
}


//classe number_factory
number_factory::number_factory(){
    this->dict.insert({"integer", make_unique<integer>()}); 
    this->dict.insert({"real", make_unique<real>()});
}

number_ptr number_factory::build(const std::string &t, int x){
    if(this->dict.count(t) <= 0)
        return nullptr;
    else
        return this->dict[t]->build(x);
}

