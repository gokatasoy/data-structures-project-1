#include "Sayi.hpp"
#include <iostream>
using namespace std;

Sayi::Sayi(){
    basamakHead = nullptr;
}

Sayi::Sayi(int deger){
    //Belirtilen değerle bir basamak başlangıç noktası oluştur.
    basamakHead = new Basamak(deger);
}

void Sayi::ekleBasamak(int deger){
    Basamak* yeniBasamak = new Basamak(deger);
    yeniBasamak->sonraki = basamakHead;
    basamakHead = yeniBasamak;
}

void Sayi::yazdir(){
    Basamak* current = basamakHead;
    while (current != nullptr){
        //Mevcut basamağın değerini yazdır.
        cout<<current->deger<<" ";

        //Bir sonraki basamağa geç.
        current = current->sonraki;
    }
    cout<<endl;
}

