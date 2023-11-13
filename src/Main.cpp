#include "SayilarListesi.hpp"
#include "Sayi.hpp"
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
        //Yeni bir sayı değeri oluşturulur.
        Sayi sayi;

        int temp = sayiDeger;
        //SayiDeger'in her bir basamağını Sayi nesnesine eklemek için:
        while (temp > 0){
            int basamak = temp % 10;
            sayi.ekleBasamak(basamak);
            temp /= 10;
        }
        //Oluşturulan Sayi nesnesi, SayilarListesi'ne ekleriz.
        sayilarListesi.ekleSayi(sayi);

        cout << "Sayi: " << sayiDeger << ", Adres: " << &sayilarListesi.baslangic->sayiListesi << endl;
    }

    dosya.close();

    return 0;
}