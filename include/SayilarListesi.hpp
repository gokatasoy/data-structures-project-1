#ifndef SAYILAR_LISTESI_HPP
#define SAYILAR_LISTESI_HPP

#include "Dugum.hpp"

class SayilarListesi{
    public:
        Dugum* baslangic;

        SayilarListesi(); 
        ~SayilarListesi(); 

        void ekleSayi(Sayi& sayi);
        void yazdir();
};

#endif