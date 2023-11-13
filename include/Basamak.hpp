#ifndef BASAMAK_HPP
#define BASAMAK_HPP

class Basamak{
    public:
        Basamak(int veri);

        //Sayının basamak değerini tutar.
        int veri;

        //Sayının bir sonraki basamağının adresini tutar.
        Basamak* sonraki;

};

#endif