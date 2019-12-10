#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>
#include <vector>
#include <memory>

class T{
    public:
        T(); //constructeur par défaut
        T(const T&); //constructeur par copie
        ~T(); //destructeur
        T &operator=(const T&); //assignation par copie
};

class file{
    public:
        FILE* dcmt;

        file(std::string);
        void write(std::string update); 
        file(const file&) = delete; //faire la meme chose pour operator=
        file &operator=(const file&) = delete;
        file(file &&) = default; 
        ~file();
        
};

class node;
//typedef node * node_ptr ; //EX4
typedef std::shared_ptr<node> node_ptr ; //EX5
class node: public std::enable_shared_from_this <node> {
    public:
        std::string label;
        std::vector <node_ptr> children;
        std::vector </*node_ptr*/std::weak_ptr<node>> parents;

        node(std::string);
        ~node();

        void add_child(node_ptr);
        std::vector<node_ptr> get_parents () const;
};

#endif //CLASSES_H
