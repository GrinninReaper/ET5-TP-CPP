#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>

class rectangle
{
    public:
        rectangle();
        rectangle(int lng, int lrg);
        rectangle(const rectangle&);
        ~rectangle();
        rectangle &operator=(const rectangle&);

        virtual void setLng(int lng);
        virtual void setLrg(int lrg);

        int getLng() const;
        int getLrg() const;

        int calculAire();        

    protected:
        int longueur;
        int largeur;

    private:

};

namespace std{
   ostream& operator<<(ostream& os, const rectangle &rect);
}

void swap(rectangle &left,rectangle &right);

void test_area(rectangle* subject);

#endif // RECTANGLE_H
