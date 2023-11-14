#include "Sayi.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

Sayi::Sayi(){
    //Head düğümün başlangıç değerini Null atadık.
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
        //Basamğın bellek adresi bir stringe dönüştürülür ve bu stringin son3 karaketir çıktı verilir.
        int* ptr = &current->deger;
        stringstream ss;
        ss << ptr;
        string addressString = ss.str();
        string lastThreeCharacters = addressString.substr(addressString.length() - 3);

        //Mevcut basamağın değerini yazdır.
        cout<< "*******" <<endl;
        cout<<"*"<<setw(4)<<lastThreeCharacters<< setw(2) << "*" <<endl;
        cout<< "*******" << endl;
        cout<< "*" << setw(3) << current->deger << setw(3) << "*" <<endl;
        cout<< "*******" <<endl<<endl;

        //Bir sonraki basamağa geç. 
        current = current->sonraki;
    }
    cout<<endl;
}

