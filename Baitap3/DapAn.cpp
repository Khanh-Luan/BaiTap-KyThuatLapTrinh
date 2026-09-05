#include <bits/stdc++.h>
using namespace std;

struct PS {
    int tu;
    int mau;
};

// Ham rut gon phan so
void RutGon(PS &a) {
    int x = abs(a.tu), y = abs(a.mau);
    while (y != 0) {
        int r = x % y;
        x = y;
        y = r;
    }
    int ucln = x;
    if (ucln != 0) {
        a.tu /= ucln;
        a.mau /= ucln;
    }
    if (a.mau < 0) {
        a.tu = -a.tu;
        a.mau = -a.mau;
    }
}

// Ham nhap phan so
void NhapPhanSo(PS &a) {
    cout << "Nhap tu so: ";
    cin >> a.tu;
    cout << "Nhap mau so: ";
    cin >> a.mau;
    while (a.mau == 0) {
        cout << "Mau so phai khac 0. Nhap lai: ";
        cin >> a.mau;
    }
    RutGon(a);
}

// Ham xuat phan so
void XuatPhanSo(PS a) {
    // Neu mau so = 1 thi in ra so nguyen
    if (a.mau == 1) {
        cout << a.tu << endl;
    } else if (a.tu == 0) {
        cout << 0 << endl; // truong hop tu so = 0
    } else {
        cout << a.tu << "/" << a.mau << endl;
    }
}


// a. Nhap, rut gon và xuat
void BaiA() {
    PS p;
    cout << "Nhap phan so:\n";
    NhapPhanSo(p);
    cout << "Phan so sau khi rut gon: ";
    XuatPhanSo(p);
}

// b. Nhap 2 phan so, tim lon nhat
void BaiB() {
    PS p1, p2;
    cout << "Nhap phan so thu nhat:\n";
    NhapPhanSo(p1);
    cout << "Nhap phan so thu hai:\n";
    NhapPhanSo(p2);

    // So sanh bang cach quy ve double
    double v1 = (double)p1.tu / p1.mau;
    double v2 = (double)p2.tu / p2.mau;

    cout << "Phan so lon nhat la: ";
    if (v1 >= v2) XuatPhanSo(p1);
    else XuatPhanSo(p2);
}

// c. Nhap 2 phan so, tinh tong, hieu, tich, thuong
void BaiC() {
    PS p1, p2, kq;
    cout << "Nhap phan so thu nhat:\n";
    NhapPhanSo(p1);
    cout << "Nhap phan so thu hai:\n";
    NhapPhanSo(p2);

    // Tong
    kq.tu = p1.tu * p2.mau + p2.tu * p1.mau;
    kq.mau = p1.mau * p2.mau;
    RutGon(kq);
    cout << "Tong = "; XuatPhanSo(kq);

    // Hieu
    kq.tu = p1.tu * p2.mau - p2.tu * p1.mau;
    kq.mau = p1.mau * p2.mau;
    RutGon(kq);
    cout << "Hieu = "; XuatPhanSo(kq);

    // Tich
    kq.tu = p1.tu * p2.tu;
    kq.mau = p1.mau * p2.mau;
    RutGon(kq);
    cout << "Tich = "; XuatPhanSo(kq);

    // Thuong
    kq.tu = p1.tu * p2.mau;
    kq.mau = p1.mau * p2.tu;
    RutGon(kq);
    cout << "Thuong = "; XuatPhanSo(kq);
}

int main() {
    cout << "=== Bai A ===\n";
    BaiA();
    cout << "\n=== Bai B ===\n";
    BaiB();
    cout << "\n=== Bai C ===\n";
    BaiC();
    return 0;
}

