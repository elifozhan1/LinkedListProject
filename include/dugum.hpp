#ifndef dugum_hpp
#define dugum_hpp
#include "sayi.hpp"

// Dugum sinifi SayilarListesi baglı listesinin dugumu
class Dugum
{
public:
    Dugum(Sayi *);
    ~Dugum();

    Sayi *sayi;
    Dugum *sonraki_dugum_adresi;
};

#endif