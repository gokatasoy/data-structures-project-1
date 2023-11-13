#include "SayilarListesi.hpp"
#include <iostream>

SayilarListesi::SayilarListesi(){
    baslangic = nullptr;
}

SayilarListesi::~SayilarListesi(){
    //While döngüsü kullanarak bağlı listeyi dolaşır ve bellek temizliği yaparız. Program durduğundan yıkıcı çağrılır ve bellek temizliği yapılır.
    Dugum* current = baslangic;
    while (current != nullptr){
        Dugum* temp = current->sonraki;
        delete temp;
    }
}

void SayilarListesi::ekleSayi(Sayi& sayi){
    //Yeni bir düğüm nesnesi oluştur ve bağlı listeye ekle.
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

