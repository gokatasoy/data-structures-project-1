#include "SayilarListesi.hpp"
#include "Sayi.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>
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

        //SAYI DEĞERLERİ VE BELLEK ADRESLERİ EKRAN ÇIKTILARI:
        cout<<"##########"<< setw(10) << "*******" <<endl;
        //Sayı adresi
        cout <<"#"<< &sayilarListesi.baslangic->sayiListesi << "#" << setw(4) << "*" << "-----" <<"*" <<endl;
        cout<<"#--------#"<< setw(10) << "*******" << endl;
        //Sayi degeri
        cout <<"#"<<setw(8)<< sayiDeger << "#" << setw(4) << "*" << "-----" << "*" <<endl;
        cout<<"##########" << setw(10) << "*******" <<endl<<endl;
    }

    dosya.close();

    return 0;
}