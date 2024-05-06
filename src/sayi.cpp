/**
 * @file VeriYapilariOdevi
 * @description bagli listelerde islemler
 * @course 1.ogretim C grubu
 * @assignment 1.odev
 * @date 02.11.2023
 * @author Elif Ozhan / elif.ozhan1@ogr.sakarya.edu.tr
 */

#include "sayi.hpp"
#include <iostream>
#include <math.h>

using namespace std;

// Sayi sinifi integer degeri constructorda alir ve basamaklari okur
Sayi ::Sayi(int okunacak_sayi)
{
    ilk = 0;

    while (okunacak_sayi > 0)
    {
        int basamak_deger = okunacak_sayi % 10;
        BasamakEkle(basamak_deger);
        okunacak_sayi /= 10;
    }
}

// Sayilarin program icinde fonksiyonlar calisirken karismaması icin
int Sayi::SayiOlustur()
{
    int olusturulan_sayi = 0;
    Basamak *gecici = ilk;

    while (gecici != 0)
    {
        olusturulan_sayi = olusturulan_sayi * 10 + gecici->veri;
        gecici = gecici->sonraki;
    }

    return olusturulan_sayi;
}

// Yeni basamak dugumu eklemek icin
void Sayi ::BasamakEkle(int deger)
{
    Basamak *yeni = new Basamak(deger);

    if (ilk == 0)
    {
        ilk = yeni;
        return;
    }

    Basamak *gecici = ilk;
    
    while (gecici->sonraki != 0)
    {
        gecici = gecici->sonraki;
    }

    gecici->sonraki = yeni;
}

// Yok edici fonksiyon
Sayi ::~Sayi()
{
    Basamak *gecici = ilk;

    while (gecici != 0)
    {
        Basamak *silinecek = gecici;
        gecici = gecici->sonraki;
        delete silinecek;
    }
}