#ifndef BASAMAK_HPP
#define BASAMAK_HPP

class Basamak{
    public:
        Basamak(int deger);

        //Sayının basamak değerini tutar.
        int deger;

        //Sayının bir sonraki basamağının adresini tutar.
        Basamak* sonraki;

};

#endif