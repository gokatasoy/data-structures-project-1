#include "SayilarListesi.hpp"
#include <iostream>
using namespace std;

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

void SayilarListesi::enBuyukCikar() {
    if(baslangic == nullptr){
        cout << "Liste bos. En buyuk sayi cikartilamaz." << endl;
        return;
    }

    // Başlangıç düğümünden başlayarak en büyük sayıyı bulma
    Dugum* temp = baslangic;
    Dugum* enBuyukDugum = baslangic;
    int enBuyukSayi = baslangic->sayiListesi.sayiDegeri();

    while (temp != nullptr) {
        // Her düğümün temsil ettiği sayının değeri hesaplanır
        int tempSayiDeger = temp->sayiListesi.sayiDegeri();

        // Eğer bulunan değer, en büyük değerden büyükse güncelle
        if (tempSayiDeger > enBuyukSayi) {
            enBuyukSayi = tempSayiDeger;
            enBuyukDugum = temp;
        }

        // Bir sonraki düğüme geç.
        temp = temp->sonraki;
    }

    // En büyük sayıyı çıkartma
    if (enBuyukDugum == baslangic) {
        baslangic = baslangic->sonraki;
    } else {
        Dugum* onceki = baslangic;
        while (onceki->sonraki != enBuyukDugum) {
            onceki = onceki->sonraki;
        }
        onceki->sonraki = enBuyukDugum->sonraki;
    }

    // En büyük sayıyı ekrana yazdırma
    cout << endl <<  "En buyuk sayi cikartildi: " << enBuyukSayi << endl << endl;;

    // Bellekten temizleme
    delete enBuyukDugum;
}

void SayilarListesi::basamaklariTersCevir(){
    Dugum* temp = baslangic;

    while(temp != nullptr) {
        temp->sayiListesi.tersCevir();
        temp = temp->sonraki;
    }
}
