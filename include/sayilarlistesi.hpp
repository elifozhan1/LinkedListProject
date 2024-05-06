#ifndef sayilarlistesi_hpp
#define sayilarlistesi_hpp
#include "dugum.hpp"

// SayilarListesi sinifi birden fazla sayiyi bulunduran bagli listedir ve sayilari tutan dugumlerden olusur
class SayilarListesi
{
public:
    Dugum *ilk;

    SayilarListesi();
    void SayiOlusturucu(int);
    void DugumEkle(Sayi *);
    void Yazdir();
    ~SayilarListesi();
};

#endif