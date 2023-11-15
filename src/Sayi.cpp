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
        // Bağlı listenin sonuna gidilir.
        Basamak* current = basamakHead;
        while (current->sonraki != nullptr) {
            current = current->sonraki;
        }

        // Yeni basamak sona eklenir.
        current->sonraki = yeniBasamak;
    }
}


void Sayi::yazdir() {
    // Matrisi oluştur
    vector<vector<string>> matris;

    Basamak* current = basamakHead;

    while (current != nullptr) {
        // Basamağın bellek adresi bir stringe dönüştürülür ve bu stringin son 3 karakteri çıktı verilir.
        int* ptr = &current->deger;
        stringstream ss;
        ss << ptr;
        string addressString = ss.str();
        string lastThreeCharacters = addressString.substr(addressString.length() - 3);

        // Mevcut basamağın değerini matrise ekleyin
        vector<string> satir;
        satir.push_back("*******");
        satir.push_back("*  " + to_string(current->deger) + "  *");
        satir.push_back("*******");
        satir.push_back("* " + lastThreeCharacters + " *");
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

