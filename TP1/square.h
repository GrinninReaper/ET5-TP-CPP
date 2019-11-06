#ifndef SQUARE_H
#define SQUARE_H

#include "rectangle.h"


class square : public rectangle
{
    public:
        square();
        square(int dim);
        square(const square&);
        ~square();
        square &operator=(const square&);
           
        void setLng(int lng);
        void setLrg(int lrg);
        
        

    protected:

    private:
};

#endif // SQUARE_H
