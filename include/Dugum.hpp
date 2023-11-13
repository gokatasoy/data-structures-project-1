#ifndef DUGUM_HPP
#define DUGUM_HPP

#include "Sayi.hpp"

class Dugum{
    public: 
        Dugum(Sayi sayiListesi);

        //Sayi nesnesini gösteren pointer.
        Sayi sayiListesi;

        //Sonraki düğümün adresi.
        Dugum* sonraki;
};

#endif