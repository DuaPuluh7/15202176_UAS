#include <iostream>
#include <vector>
#include <cmath>
#include <math.h>

using namespace std;

struct Data {
    double x;
    double y;
};

vector<Data> data;

double hitungRataRataX() {
    double total = 0;
    for (int i = 0; i < data.size(); i++) {
        total += data[i].x;
    }
    return total / data.size();
}

double hitungRataRataY() {
    double total = 0;
    for (int i = 0; i < data.size(); i++) {
        total += data[i].y;
    }
    return total / data.size();
}

double hitungKovarians(double rataRataX, double rataRataY) {
    double total = 0;
    for (int i = 0; i < data.size(); i++) {
        total += (data[i].x - rataRataX) * (data[i].y - rataRataY);
    }
    return total / (data.size() - 1);
}

double hitungStandarDeviasiX() {
    double rataRataX = hitungRataRataX();
    double total = 0;
    for (int i = 0; i < data.size(); i++) {
        total += pow(data[i].x - rataRataX, 2);
    }
    return sqrt(total / (data.size() - 1));
}

double hitungStandarDeviasiY() {
    double rataRataY = hitungRataRataY();
    double total = 0;
    for (int i = 0; i < data.size(); i++) {
        total += pow(data[i].y - rataRataY, 2);
    }
    return sqrt(total / (data.size() - 1));
}

double hitungKorelasiPearson() {
    double rataRataX = hitungRataRataX();
    double rataRataY = hitungRataRataY();
    double kovarians = hitungKovarians(rataRataX, rataRataY);
    double standarDeviasiX = hitungStandarDeviasiX();
    double standarDeviasiY = hitungStandarDeviasiY();
    if (standarDeviasiX == 0 || standarDeviasiY == 0)
        return nan("");
    return kovarians / (standarDeviasiX * standarDeviasiY);
}


int main() {
    int n;
    cout << "Masukkan jumlah pasangan data: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        Data dataBaru;
        cout << "Masukkan nilai x: ";
        cin >> dataBaru.x;
        while (dataBaru.x <= 0) {
            cout << "Nilai x tidak boleh kurang dari 0. Masukkan nilai x: ";
            cin >> dataBaru.x;
        }

        cout << "Masukkan nilai y: ";
        cin >> dataBaru.y;
        while (dataBaru.y <= 0) {
            cout << "Nilai y tidak boleh kurang dari 0. Masukkan nilai y: ";
            cin >> dataBaru.y;
        }

        data.push_back(dataBaru);
    }

    double korelasiPearson = hitungKorelasiPearson();
    cout << "Nilai korelasi Pearson: " << korelasiPearson << endl;

    double b = korelasiPearson * (hitungStandarDeviasiY() / hitungStandarDeviasiX());
    double a = hitungRataRataY() - (b * hitungRataRataX());
    double koefisien;

    koefisien = (korelasiPearson*korelasiPearson)*100/100;


    // ... perhitungan korelasi pearson dan regresi sederhana
    cout << "Koefisien Determinasinya adalah:   " << koefisien << endl;
    if (korelasiPearson >= 0 && korelasiPearson <= 0.09 ){
        cout << "Hubungan Korelasi diabaikan" << endl;
        cout << "(Positif)Hasil antara variable x dan Y adalah positif " << endl;
    }else if (korelasiPearson >= 0.10 && korelasiPearson <= 0.29){
        cout << "Hubungan Korelasi rendah" << endl;
        cout << "(Positif)Hasil antara variable x dan Y adalah positif " << endl;
    }else if (korelasiPearson >= 0.30 && korelasiPearson <= 0.49){
        cout << "Hubungan kolerasi moderat" << endl;
        cout << "(Positif)Hasil antara variable x dan Y adalah positif " << endl;
    }else if (korelasiPearson >= 0.50 && korelasiPearson <= 0.70){
        cout << "Hubungan kolerasi sedang" << endl;
        cout << "(Positif)Hasil antara variable x dan Y adalah positif " << endl;
    }else if (korelasiPearson > 0.70){
        cout << "Hubungan korelasi sangat kuat" << endl;
        cout << "(Positif)Hasil antara variable x dan Y adalah positif " << endl;
    }
    else if (korelasiPearson < 0)
        cout << "(Negatif)Hasil korelasi negatif dengan nilai " << endl;
    else 
        cout << "(0)Tidak ada Hubungan antara Variable x Dan y" << endl;


    return 0;
}

