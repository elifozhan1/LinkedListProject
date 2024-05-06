#ifndef sayi_hpp
#define sayi_hpp
#include "basamak.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

// Sayi sinifi bir sayiyi belirten bagli listedir ve basamaklardan olusur
class Sayi
{
public:
    Basamak *ilk;

    Sayi(int);
    int SayiOlustur();
    void BasamakEkle(int);
    ~Sayi();
};

#endif