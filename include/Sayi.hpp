#ifndef SAYI_HPP
#define SAYI_HPP

#include "Basamak.hpp"

class Sayi{
    public:
        Basamak* basamakHead;

        Sayi();
        Sayi(int deger);

        void ekleBasamak(int deger);
        void yazdir();
    
};


#endif