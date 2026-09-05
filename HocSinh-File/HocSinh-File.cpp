#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct HocSinh {
    char ma[10];
    char ten[50];
    double diemToan;
    double diemVan;
};

double diemTrungBinh(HocSinh hs) {
    return (hs.diemToan + hs.diemVan) / 2;
}

int main() {
    HocSinh h1;

    strcpy(h1.ma, "HS01");
    strcpy(h1.ten, "Nguyen Van A");
    h1.diemToan = 8.5;
    h1.diemVan = 7.5;

    fstream outfile;
    outfile.open("D:/Baitap-KyThuatLapTrinh/HocSinh-File/data.txt", ios::out | ios::binary);

    outfile.write((char*)&h1, sizeof(HocSinh));

    outfile.close();

    HocSinh *h2 = new HocSinh;

    fstream infile;
    infile.open("D:/Baitap-KyThuatLapTrinh/HocSinh-File/data.txt", ios::in | ios::binary);

    infile.read((char*)h2, sizeof(HocSinh));

    infile.close();

    cout << "Ma: " << h2->ma << endl;
    cout << "Ten: " << h2->ten << endl;
    cout << "Diem Toan: " << h2->diemToan << endl;
    cout << "Diem Van: " << h2->diemVan << endl;
    cout << "Diem trung binh: " << diemTrungBinh(*h2) << endl;

    delete h2;

    return 0;
}
