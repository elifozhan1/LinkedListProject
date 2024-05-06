/**
 * @file VeriYapilariOdevi
 * @description bagli listelerde islemler
 * @course 1.ogretim C grubu
 * @assignment 1.odev
 * @date 02.11.2023
 * @author Elif Ozhan / elif.ozhan1@ogr.sakarya.edu.tr
 */

#include "dugum.hpp"

/* sayi icinde tutacagı sayi bagli listesinin adresidir ve
sonraki dugumu gostermesi icin sonraki_dugum_adresi adinda
bir isaretci belirlenmistir */
Dugum ::Dugum(Sayi *sayi)
{
    this->sayi = sayi;
    sonraki_dugum_adresi = 0;
}

Dugum ::~Dugum()
{
    delete sayi;
}