#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>
#include <map>
#include <vector>
#include <memory>

//typedef std::unique_ptr<number> number_ptr;
class number{

    public:
        virtual std::unique_ptr<number> build(int) = 0;
        virtual void display () = 0;
        virtual ~number() = default;

};

using number_ptr = std::unique_ptr<number>;


class integer : public number{
    int value;
    
    public:
        virtual std::unique_ptr<number> build(int) override;
        virtual void display() override;
};

class real : public number{
    
    double value;

    public:
        virtual std::unique_ptr<number> build(int) override;
        virtual void display() override;
};


class number_factory {
    protected:
        std::map<std::string,number_ptr> dict;

    public :
        number_factory();
        number_ptr build (const std::string &t, int x);
};


#endif //CLASSES_H
