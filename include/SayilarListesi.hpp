#ifndef SAYILAR_LISTESI_HPP
#define SAYILAR_LISTESI_HPP

#include "Sayi.hpp"
#include "Dugum.hpp"

class SayilarListesi{
    public:
        //Düğüm sınıfından oluşan bir başlangıç noktası çünkü SayilarListesi bağlı listesi Dugum adlı node'lardan oluşur.
        Dugum* baslangic;

        SayilarListesi(); 
        ~SayilarListesi(); 

        //Bir sayı nesnesi ekleyen fonksiyon.
        void ekleSayi(Sayi& sayi);

        //SayilarListesi'ndeki tüm Sayi nesnelerini yazdıran fonksiyon.
        void yazdir();

        //Menü 3. seçenek. SayilarListesi'ndeki en büyük sayı nesnesini bulur ve listeden çıkartır. Ardında şu sayısı listede çıkartıldı diye bize bir çıktı verir.
        void enBuyukCikar();

};

#endif