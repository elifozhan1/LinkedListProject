/**
 * @file VeriYapilariOdevi
 * @description bagli listelerde islemler
 * @course 1.ogretim C grubu
 * @assignment 1.odev
 * @date 02.11.2023
 * @author Elif Ozhan / elif.ozhan1@ogr.sakarya.edu.tr
 */

#include "basamak.hpp"

/* veri icinde tutacagı tek basamakli sayi degeridir ve
sonraki basamak dugumunu gostermesi icin sonraki adinda bir isaretci belirlenmistir */
Basamak ::Basamak(int veri)
{
    this->veri = veri;
    sonraki = 0;
}

Basamak ::~Basamak()
{}