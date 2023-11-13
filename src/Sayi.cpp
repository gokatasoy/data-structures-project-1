#include "Sayi.hpp"
#include <iostream>
using namespace std;

Sayi::Sayi(){
    basamakHead = nullptr;
}

Sayi::Sayi(int deger){
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
        cout<<current->deger<<" ";
        current = current->sonraki;
    }
    cout<<endl;
}

