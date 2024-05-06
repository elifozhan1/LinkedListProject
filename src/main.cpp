/**
 * @file VeriYapilariOdevi
 * @description bagli listelerde islemler
 * @course 1.ogretim C grubu
 * @assignment 1.odev
 * @date 02.11.2023
 * @author Elif Ozhan / elif.ozhan1@ogr.sakarya.edu.tr
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "sayilarlistesi.hpp"

using namespace std;

// Fonksiyon tanimlari
void Menu(SayilarListesi *);
void TekleriBasaAl(SayilarListesi *);
void BasamaklariTersle(SayilarListesi *);
void EnBuyukCikar(SayilarListesi *);

int main()
{
    // Dosya okuma
    int okunacak_sayi = 0;
    ifstream SayilariOku("./doc/sayilar.txt");

    SayilarListesi *sayi_listesi = new SayilarListesi();
    while (SayilariOku >> okunacak_sayi)
    {
        sayi_listesi->SayiOlusturucu(okunacak_sayi);
    }

    /* Basamaklar tersten okundugu icin normal sekilde yazdirmak icin
    BasamaklariTersle fonksiyonu */
    BasamaklariTersle(sayi_listesi);
    Menu(sayi_listesi);

    SayilariOku.close();
    delete sayi_listesi;
    return 0;
}

void Menu(SayilarListesi *sayi_listesi)
{

    int secim = 0;

    cout << "1. tek basamaklari basa al" << endl;
    cout << "2. basamaklari tersle" << endl;
    cout << "3. en buyuk cikar" << endl;
    cout << "4. cikis" << endl;
    cout << endl;
    cout << "seciminiz: ";
    cin >> secim;
    cout << endl;

    // Menu icin switch-case blogu
    switch (secim)
    {
    case 1:
        TekleriBasaAl(sayi_listesi);
        Menu(sayi_listesi);
        break;
    case 2:
        BasamaklariTersle(sayi_listesi);
        Menu(sayi_listesi);
        break;
    case 3:
        EnBuyukCikar(sayi_listesi);
        Menu(sayi_listesi);
        break;
    case 4:
        break;
    default:
        cout << "HATA\n";
    }
}

void TekleriBasaAl(SayilarListesi *sayilar_listesi)
{
    Dugum *gecici = sayilar_listesi->ilk;

    while (gecici != 0)
    {
        if (gecici->sayi->ilk == 0 || gecici->sayi->ilk->sonraki == 0)
        {
            return;
        }

        // Ayri ayri ilk ve son tek ve cift basamaklar tespit edilir
        Basamak *tek_basamak_ilk = 0;
        Basamak *cift_basamak_ilk = 0;
        Basamak *tek_basamak_son = 0;
        Basamak *cift_basamak_son = 0;

        Basamak *yeni = gecici->sayi->ilk;

        while (yeni != 0)
        {
            if (yeni->veri % 2 != 0)
            {
                if (tek_basamak_ilk == 0)
                {
                    tek_basamak_ilk = yeni;
                    tek_basamak_son = yeni;
                }

                else
                {
                    tek_basamak_son->sonraki = yeni;
                    tek_basamak_son = yeni;
                }
            }

            else
            {
                if (cift_basamak_ilk == 0)
                {
                    cift_basamak_ilk = yeni;
                    cift_basamak_son = yeni;
                }

                else
                {
                    cift_basamak_son->sonraki = yeni;
                    cift_basamak_son = yeni;
                }
            }

            yeni = yeni->sonraki;
        }

        // Dugumler arasi baglantilar
        if (tek_basamak_ilk != 0)
        {
            tek_basamak_son->sonraki = cift_basamak_ilk;
            gecici->sayi->ilk = tek_basamak_ilk;
        }

        else
        {
            gecici->sayi->ilk = cift_basamak_ilk;
        }

        if (cift_basamak_son != 0)
        {
            cift_basamak_son->sonraki = 0;
        }

        gecici = gecici->sonraki_dugum_adresi;
    }

    sayilar_listesi->Yazdir();
}

void BasamaklariTersle(SayilarListesi *sayilar_listesi)
{
    Dugum *gecici = sayilar_listesi->ilk;

    while (gecici != 0)
    {
        // Dugumler arasi yer degisikligi
        Basamak *okunan_basamak = 0;
        Basamak *yeni = gecici->sayi->ilk;
        Basamak *sonraki_basamak = 0;

        while (yeni != 0)
        {
            sonraki_basamak = yeni->sonraki;
            yeni->sonraki = okunan_basamak;
            okunan_basamak = yeni;
            yeni = sonraki_basamak;
        }

        gecici->sayi->ilk = okunan_basamak;

        gecici = gecici->sonraki_dugum_adresi;
    }

    sayilar_listesi->Yazdir();
}

void EnBuyukCikar(SayilarListesi *sayilar_listesi)
{
    // Son dugum silinirken
    if (sayilar_listesi->ilk == 0)
    {
        cout << "Liste bos!!!" << endl;

        return;
    }

    Dugum *gecici = sayilar_listesi->ilk;

    if (gecici->sonraki_dugum_adresi == 0)
    {
        // Son dugum siliniyor
        delete sayilar_listesi->ilk;
        sayilar_listesi->ilk = 0;

        return;
    }

    // Enbuyuk dugum ve ondan onceki farklı pointerlarla belirtilmis
    Dugum *en_buyuk_dugum = gecici;
    Dugum *en_buyuk_onceki = 0;
    Dugum *yeni = gecici;

    while (yeni != 0)
    {
        if ((yeni->sayi->SayiOlustur()) > (en_buyuk_dugum->sayi->SayiOlustur()))
        {
            en_buyuk_dugum = yeni;
        }

        yeni = yeni->sonraki_dugum_adresi;
    }

    yeni = gecici;

    while (yeni->sonraki_dugum_adresi != 0)
    {
        if (yeni->sonraki_dugum_adresi == en_buyuk_dugum)
        {
            en_buyuk_onceki = yeni;
        }

        yeni = yeni->sonraki_dugum_adresi;
    }

    if (en_buyuk_onceki != 0)
    {
        en_buyuk_onceki->sonraki_dugum_adresi = en_buyuk_dugum->sonraki_dugum_adresi;
    }

    else
    {
        sayilar_listesi->ilk = en_buyuk_dugum->sonraki_dugum_adresi;
    }

    // Silme islemi
    delete en_buyuk_dugum;

    sayilar_listesi->Yazdir();
}