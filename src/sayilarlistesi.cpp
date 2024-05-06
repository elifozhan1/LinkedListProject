/**
 * @file VeriYapilariOdevi
 * @description bagli listelerde islemler
 * @course 1.ogretim C grubu
 * @assignment 1.odev
 * @date 02.11.2023
 * @author Elif Ozhan / elif.ozhan1@ogr.sakarya.edu.tr
 */

#include "sayilarlistesi.hpp"
#include <iomanip>

SayilarListesi ::SayilarListesi()
{
    ilk = 0;
}

// Sayi listesinin olusmasi icin
void SayilarListesi ::SayiOlusturucu(int okunacak_sayi)
{
    Sayi *sayi = new Sayi(okunacak_sayi);
    DugumEkle(sayi);
}

// Yeni dugum eklemek icin
void SayilarListesi ::DugumEkle(Sayi *sayi)
{
    Dugum *yeni = new Dugum(sayi);

    if (ilk == 0)
    {
        ilk = yeni;
        return;
    }

    Dugum *gecici = ilk;
    while (gecici->sonraki_dugum_adresi != 0)
    {
        gecici = gecici->sonraki_dugum_adresi;
    }

    gecici->sonraki_dugum_adresi = yeni;
}

// Program icerisinde sayi listelerinin ekrana ciktisinin alinmasini saglayan fonksiyon
void SayilarListesi ::Yazdir()
{
    Dugum *gecici = ilk;

    while (gecici != 0)
    {
        Basamak *gecici_sayi = gecici->sayi->ilk;

        cout << "############### ";

        while (gecici_sayi != 0)
        {
            cout << "*************** ";
            gecici_sayi = gecici_sayi->sonraki;
        }

        cout << endl;
        gecici_sayi = gecici->sayi->ilk;

        cout << "#" << setw(13) << gecici << "# ";

        while (gecici_sayi != 0)
        {
            cout << "*     " << setw(13) << hex << setw(3) << ((uintptr_t)gecici_sayi % 0x1000) << "     * ";
            gecici_sayi = gecici_sayi->sonraki;
        }

        cout << endl;
        gecici_sayi = gecici->sayi->ilk;

        cout << "#-------------# ";

        while (gecici_sayi != 0)
        {
            cout << "*-------------* ";
            gecici_sayi = gecici_sayi->sonraki;
        }

        cout << endl;
        gecici_sayi = gecici->sayi->ilk;

        cout << "#" << setw(13) << dec << (gecici->sayi->SayiOlustur()) << "# ";

        while (gecici_sayi != 0)
        {
            cout << "*      " << gecici_sayi->veri << "      * ";
            gecici_sayi = gecici_sayi->sonraki;
        }

        cout << endl;
        gecici_sayi = gecici->sayi->ilk;

        cout << "############### ";

        while (gecici_sayi != 0)
        {
            cout << "*************** ";
            gecici_sayi = gecici_sayi->sonraki;
        }

        cout << endl <<endl;
        gecici = gecici->sonraki_dugum_adresi;
    }
}

// Yok edici fonksiyon
SayilarListesi ::~SayilarListesi()
{
    Dugum *gecici = ilk;

    while (gecici != 0)
    {
        Dugum *silinecek = gecici;
        gecici = gecici->sonraki_dugum_adresi;
        delete silinecek;
    }
}