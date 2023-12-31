#include "Sayi.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>

using namespace std;

Sayi::Sayi() {
    //sınıfın başlangıç fonkyionu null olarak ayarlanır.
    basamakHead = nullptr;
}

Sayi::Sayi(int deger) {
    //bir tamsayı alır ve bu tam sayıyı bir basamak olarak kullanarak başlangıç noktasını oluşturur.
    basamakHead = new Basamak(deger);
}

void Sayi::ekleBasamak(int deger) {
    // Yeni bir basamak oluşturulur ve degeri içine atanır.
    Basamak* yeniBasamak = new Basamak(deger);

    // Eğer bağlı liste boşsa, yeni basamak başlangıç noktası olur.
    if (basamakHead == nullptr) {
        basamakHead = yeniBasamak;
    } else {
        // Yeni basamağı listenin başına ekle.
        yeniBasamak->sonraki = basamakHead;
        basamakHead = yeniBasamak;
    }
}



void Sayi::yazdir() {
    // Matrisi oluştur
    vector<vector<string>> matris;

    Basamak* current = basamakHead;

    while (current != nullptr) {
        // Bir sonraki basamağın bellek adresini alır.
        // int* nextPtr = (current->sonraki != nullptr) ? &current->sonraki->deger : nullptr;

        // Bellek adresini bir stringe çevirir.
        std::stringstream addressStream;
        addressStream << current;
        std::string addressString = addressStream.str();

        // Adres stringinin son 3 karakterini alır.
        std::string lastThreeDigits = (addressString.length() >= 3) ? addressString.substr(addressString.length() - 3) : "000";

        // Mevcut basamağın değeri ve bir sonraki basamağın bellek adresini matrise ekleyin
        vector<string> satir;
        satir.push_back("*******");
        satir.push_back("* " + lastThreeDigits + " *");
        satir.push_back("*******");
        satir.push_back("*  " + to_string(current->deger) + "  *");
        satir.push_back("*******");
        matris.push_back(satir);

        // Bir sonraki basamağa geç. 
        current = current->sonraki;
    }

    // Matrisi kullanarak çıktı oluştur
    for (size_t i = 0; i < matris[0].size(); ++i) {
        for (size_t j = 0; j < matris.size(); ++j) {
            cout << setw(10) << left << matris[j][i];
        }
        cout << endl;
    }
    cout << endl;
}

int Sayi::sayiDegeri() const {
    int deger = 0;
    int basamakKatSayisi = 1;

    // Başlangıç düğümü
    Basamak* current = basamakHead;

    // Bağlı listedeki her basamak üzerinde dolaşılır
    while (current != nullptr) {
        // Her basamağın değeri, onun pozisyonundaki basamakKatSayisi ile çarpılır ve toplama eklenir.
        deger += current->deger * basamakKatSayisi;

        // Bir sonraki basamağa geç.
        current = current->sonraki;

        // Basamak kat sayısını artır.
        basamakKatSayisi *= 10;
    }

    // Hesaplanan sayı değeri geri döndürülür.
    return deger;
}

void Sayi::tersCevir(){
    Basamak* prev = nullptr;
    Basamak* current = basamakHead;
    Basamak* next = nullptr;

    while(current != nullptr) {
        next = current->sonraki;
        current->sonraki = prev;
        prev = current;
        current = next;
    }

    basamakHead = prev;
}

