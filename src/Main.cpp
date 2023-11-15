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
        cout<<"##########"<<endl;
        cout<< "#" << &sayilarListesi.baslangic->sayiListesi << "#" <<endl;
        cout<<"#--------#"<< "  ===>  " << endl;
        cout<<"#"<<setw(8)<< sayiDeger << "#" << endl;
        cout<<"##########" <<endl<<endl;

        sayi.yazdir();

        cout<<endl<<endl;
    }

    dosya.close();

        int secim;
    do{
        cout << "MENU:" << endl;
        cout << "1. Tek Basamaklari Basa Al." <<endl;
        cout << "2. Basamaklari Tersle." <<endl;
        cout << "3. En Buyuk Cikar." <<endl;
        cout << "4. Cikis." ;
        cin >> secim;

        switch (secim) {
            case 1:
                cout<<"1."<<endl;
                break;

            case 2:
                cout<<"2."<<endl;
                break;

            case 3:
                cout<<"3."<<endl;
                break;

            case 4:
                cout<<"Programdan cikis yapiliyor."<<endl;
                break;

            default:
                cout << "Gecersiz secim. Lutfen tekrar deneyin."<< endl;
                break;
        }

    } while (secim != 4);

    return 0;
}

