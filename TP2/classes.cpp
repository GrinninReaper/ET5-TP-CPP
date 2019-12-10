#include "classes.hpp"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>


    //methode de T
T::T(){
    std::cout << "Constructeur par défaut"<<std::endl;
}

T::T(T const &t){
    std::cout << "Constructeur par copie"<<std::endl;
    std::cout << this << ": constructed from "<< &t <<std::endl;
}

T& T::operator=(T const &t){
    std::cout << "Assignation par copie"<<std::endl;
    std::cout << this << ": constructed from "<< &t <<std::endl;
}

T::~T(){
    std::cout << "Destructeur"<<std::endl;
}

    //methode de file
file::file(std::string filePath){
    this->dcmt = fopen(filePath.c_str(), "w");
}

void file::write(std::string update){  
    fwrite(update.c_str(), sizeof(char), update.size(), this->dcmt);
}

file::~file(){
    fclose(this->dcmt);
}
/*
file::file(file const&){
    std::cout<<"Constructeur par copie" << std::endl;
    exit(EXIT_FAILURE);
}
*/

node::node(std::string text){
    this->label = text;
}

node::~node(){
    std::cout<< "Destroying " << this->label << std::endl;
}

void node::add_child(node_ptr update){
    this->children.push_back(update);
    
    update->parents.push_back(shared_from_this());
}

std::vector<node_ptr> node::get_parents () const{
    std::cout<<this->label<< " has "<< parents.size()<<std::endl;
    std::vector<node_ptr> parents;
    for(const auto &i : this->parents){
       parents.push_back(i.lock());
    }
    return parents;
}
