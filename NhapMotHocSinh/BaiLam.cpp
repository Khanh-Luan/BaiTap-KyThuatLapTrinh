#include <iostream>
#include <string>
using namespace std;

struct HocSinh {
    string hoTen;
    double diemToan;
    double diemVan;
};

void nhap(HocSinh &hs) {
    cout << "Nhap ho ten: ";
    getline(cin, hs.hoTen);

    cout << "Nhap diem Toan: ";
    cin >> hs.diemToan;

    cout << "Nhap diem Van: ";
    cin >> hs.diemVan;
}

double diemTrungBinh(HocSinh hs) {
    return (hs.diemToan + hs.diemVan) / 2;
}

void xuat(HocSinh hs) {
    cout << "\n--- Ket qua ---" << endl;
    cout << "Ho ten: " << hs.hoTen << endl;
    cout << "Diem Toan: " << hs.diemToan << endl;
    cout << "Diem Van: " << hs.diemVan << endl;
    cout << "Diem trung binh: " << diemTrungBinh(hs) << endl;
}

int main() {
    HocSinh hs;

    nhap(hs);
    xuat(hs);

    return 0;
}

