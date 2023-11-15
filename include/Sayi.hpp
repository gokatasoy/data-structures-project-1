#ifndef SAYI_HPP
#define SAYI_HPP

#include <iostream>

#include "Basamak.hpp"

class Sayi{
    public:
        //Basamak sınıfından oluşan bir basamak başlangıç pointer'ı çünkü Sayi bağlı listesi Basamak adlı node'lardan oluşur.
        Basamak* basamakHead;

        Sayi();
        Sayi(int deger);

        //Yeni bir basamak ekler ve bağlı listeyi günceller.
        void ekleBasamak(int deger);

        //Basamakları yazdıran fonksiyon.
        void yazdir();

        //Sayi değerlerini döndüren fonksiyon.
        int sayiDegeri() const;

        //Sayi değerlerinin basamak düğümlerini ters çevirir.
        void tersCevir();
};

#endif