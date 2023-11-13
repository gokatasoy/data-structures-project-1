#include "SayilarListesi.hpp"
#include <iostream>
#include <fstream>
using namespace std;

int main(){
    //sayilarListesi nesnesi oluşturulur. Bu nesne, içinde sayıları saklayacak ve işleyecek bir veri yapısını temsil eder.
    SayilarListesi sayilarListesi;

    ifstream dosya("./Sayilar.txt");
    if (!dosya.is_open()) {
        cout << "Dosya acilamadi!" << std::endl;
        return 1;
    }

    //Dosyadan okunan her sayı değeri:
    int sayiDeger;
    while (dosya >> sayiDeger){
        Sayi sayi;
        while (sayiDeger > 0){
            int basamak = sayiDeger % 10;
            sayi.ekleBasamak(basamak);
            sayiDeger /= 10;
        }
        sayilarListesi.ekleSayi(sayi);
    }

    dosya.close();

    cout<<"Sayilar Listesi: "<<endl;
    sayilarListesi.yazdir();

    return 0;

}