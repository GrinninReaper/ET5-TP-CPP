#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>
#include <map>
#include <vector>
#include <memory>
#include <assert.h>
#include <stdexcept>

using namespace std;

template < typename T, std::size_t N >
    class small_array{
    private:
        T values[N];
        
    public:
        //on ne définit aucun des consructeurs ou des destructeurs pour garder ceux par défaut
        T& operator [](std::size_t i) noexcept{
            assert(i < N);
            return values[i];
        }

        const T& operator[](std::size_t i) const noexcept{
            assert(i < N);
            return values[i];
        }

        T& at(std::size_t i){
            if(i >= N)
                throw std::runtime_error("Small array out of index\n");
            else
                return values[i];
        }
        
        const T& at(std::size_t i) const{
            if(i >= N)
                throw std::runtime_error("Small array out of index\n");
            else
                return values[i];
        }
    };

template < typename T, std::size_t N >
 class large_array{
    private:
        std::unique_ptr<small_array<T,N>> values;
        
    public:

        large_array(){
            //cout<<"Constructeur par défaut"<<endl;
            values = make_unique<small_array<T, N>>();
        } //constructeur par défaut
        large_array(const large_array &first) : values(make_unique<small_array<T, N>>(*first.values)) {
            //cout<<"Constructeur par copie"<<endl;
        } //constructeur par copie
        ~large_array() = default; //destructeur
        large_array &operator=(const large_array &first){
            *values = *first.values;
            return *this;
        }; //affectaion

        
        T& operator [](std::size_t i) noexcept{
            assert(i < N);
            return values.get()->operator[](i);
        }

        const T& operator[](std::size_t i) const noexcept{
            assert(i < N);
            return values.get()->operator[](i);
        }

        T& at(std::size_t i){
            if(i >= N)
                throw std::runtime_error("Small array out of index\n");
            else
                return values.get()->operator[](i);
        }
        
        const T& at(std::size_t i) const{
            if(i >= N)
                throw std::runtime_error("Small array out of index\n");
            else
                return values.get()->operator[](i);
        }

        void swap(large_array &first){
            cout<<"Called swap"<<endl;
            std::unique_ptr<small_array<T,N>> temp(make_unique<small_array<T, N>>(*first.values));
            *first.values = *values;
            *values = *temp;
        }

    };


#endif //CLASSES_H
