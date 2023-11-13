#include "SayilarListesi.hpp"
#include <iostream>

SayilarListesi::SayilarListesi(){
    baslangic = nullptr;
}

SayilarListesi::~SayilarListesi(){
    Dugum* current = baslangic;
    while (current != nullptr){
        Dugum* temp = current->sonraki;
        delete temp;
    }
}

void SayilarListesi::ekleSayi(Sayi& sayi){
        Dugum* yeniDugum = new Dugum(sayi);
        yeniDugum->sonraki = baslangic;
        baslangic = yeniDugum;
        yeniDugum->sayiListesi = sayi;
}

void SayilarListesi::yazdir() {
    Dugum* temp = baslangic;
    while (temp != nullptr) {
        temp->sayiListesi.yazdir();
        temp = temp->sonraki;
    }
}