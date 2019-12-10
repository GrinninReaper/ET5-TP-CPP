#include <iostream>

#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <fstream>
#include <unordered_map>
#include "classes.hpp"

using namespace std;


template<std::size_t dim> struct point { double coords[dim]; };
template<std::size_t dim> using points = std::vector<point<dim>>;

typedef std::unordered_multimap<std::string, std::string> dictionary;

template<std::size_t dim> point<dim> createRandom(){
    point<dim> rslt;
    for(size_t i=0; i<dim;i++){
        double temp(rand());
        rslt.coords[i] = temp/RAND_MAX;
    }
    return rslt;
}

template<std::size_t dim>
std::ostream& operator<<(std::ostream& out, const point<dim>& p){

    out<<"[";
    for(size_t i=0; i<dim; i++){
        out<<p.coords[i]<<",";
    }
    out<<"]";
    return out;
}

template<std::size_t dim>
double dist(const point<dim>& p1, const point<dim>& p2){
    double rslt = 0.0;
    for(size_t i = 0; i < dim; i++){
        double temp(p1.coords[i]-p2.coords[i]);
        rslt += temp*temp;
    }
    return std::sqrt(rslt);
}

template<std::size_t dim>
const point<dim>& closest(const points<dim>& pts, const point<dim>& p){
    auto comp = [p](const point<dim>& a, const point<dim>& b){ return dist(a, p) < dist(b, p);};
    return *std::min_element(pts.begin(), pts.end(), comp);
}

template<std::size_t dim>
point<dim> operator+(const point<dim>& p1, const point<dim>& p2){
    point<dim> rslt;
    std::transform(p1.coords, p1.coords+dim, p2.coords, rslt.coords, [](double a, double b){return a+b;});
    return rslt;
}

template<std::size_t dim>
point<dim> operator/(const point<dim>& p1, const double& d){
    point<dim> rslt;
    for(size_t i= 0;i<dim; i++){
        rslt.coords[i] = p1.coords[i] / d;
    }
    return rslt;
}

std::string normalize(std::string const & str){

    std::string rslt = str;
    sort(rslt.begin(), rslt.end());
    return rslt;
}

bool isAna(std::string const & str1, std::string const & str2){
    return normalize(str1) == normalize(str2);
}

std::vector<std::string> load(){
    std::ifstream file("wordsEn.txt");
    std::vector<std::string> rslt;
    std::string temp;
    while(std::getline(file, temp)){
        rslt.push_back(temp);
    }
    return rslt;
}

dictionary convert(std::vector<std::string> const & mot){
     dictionary oxford;

    for(size_t i = 0; i< mot.size(); i++){
        std::string temp = normalize(mot.at(i));
        oxford.insert({temp, mot.at(i)});
    }

    return oxford;
}

std::vector<std::string> anagrams(dictionary const & dict, std::string const & str){
    std::vector<std::string> rslt;
    
    std::pair <dictionary::const_iterator,dictionary::const_iterator> p = dict.equal_range(normalize(str));
    for(dictionary::const_iterator i = p.first; i != p.second; ++i){
        if(i->second != str){
            std::cout<<i->second<<std::endl;
            rslt.push_back(i->second);
        }
    }
    return rslt;
}



int main()
{   
    //Question 1
        //Question 1.1
    cout<<"Result 1.1"<<std::endl;
    std::cout << createRandom<3>() << endl;    

        //Question 1.2
    cout<<"Result 1.2"<<std::endl;
    std::vector<point<2>> randomVect{};
    std::generate_n(std::back_inserter(randomVect), 5, createRandom<2>);
    std::for_each(randomVect.begin(), randomVect.end(),[](const point<2>& p){std::cout<<p<<endl;});
    
        //Question 1.3
    cout<<"Result 1.3"<<std::endl;
    point<2> comp;
    cout<<closest(randomVect, comp)<<endl;

        //Question 1.4
	cout<<"Result 1.4"<<std::endl;
    point<2> rslt4;
    cout<<std::accumulate(randomVect.begin(), randomVect.end(),rslt4) / 5<<std::endl;

    //Question 2
        //Question 2.1
	cout<<"Result 2.1"<<std::endl;
    std::cout<<normalize("azertyuop")<<std::endl;
    std::cout<<isAna("azertyuiop", "poiuytreza")<<std::endl;

        //Question 2.2
    cout<<"Result 2.2"<<std::endl;
    std::vector<std::string> mot = load();
    std::cout<<mot.size()<<" " <<mot.at(mot.size() - 1)<<std::endl;

        //Question 2.3
	cout<<"Result 2.3"<<std::endl;
    dictionary oxford;

    for(size_t i = 0; i< mot.size(); i++){
        std::string temp = normalize(mot.at(i));
        oxford.insert({temp, mot.at(i)});
    }

        //Question 2.4
	cout<<"Result 2.4"<<std::endl;
    std::vector<std::string> test_words = { "anagram", "parrot", "abba", "insert", "silent" };
    for(auto w:test_words){
        std::vector<std::string> anagrames = anagrams(oxford, w);
        for(auto a:anagrames){
            std::cout<<a;
        }
        std::cout<<std::endl;
    }

    return 0;
}
