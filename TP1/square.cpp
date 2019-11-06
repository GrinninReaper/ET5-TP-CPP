#include "rectangle.h"
#include "square.h"
#include <cmath>
#include <assert.h>

square::square() : rectangle(1, 1) 
{

}

square::~square()
{
    //dtor
}

square::square(const square &sq) : rectangle(sq.longueur, sq.longueur)
{
    assert(sq.longueur == sq.largeur);
}

square::square(int dim){
    this->longueur = dim;
    this->largeur = dim;
}

void square::setLng(int lng){
    this->longueur = lng;
    this->largeur = lng;
}

void square::setLrg(int lrg){
    this->longueur = lrg;
    this->largeur = lrg;
}

