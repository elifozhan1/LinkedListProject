#ifndef basamak_hpp
#define basamak_hpp

// Basamak sinifi Sayi baglı listesinin dugumu
class Basamak
{
public:
    Basamak(int);
    ~Basamak();

    int veri;
    Basamak *sonraki;
};

#endif