// a) Viet chuong trinh nhap vao mot ngay.
// Tim ngay ke tiep va xuat ket qua.

#include <bits/stdc++.h>
using namespace std;

struct Date {
    int d, m, y;
};

// Kiem tra nam nhuan
bool NamNhuan(int y) {
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}

// So ngay trong thang
int SoNgayTrongThang(int m, int y) {
    switch(m) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31;
        case 4: case 6: case 9: case 11: return 30;
        case 2: return NamNhuan(y) ? 29 : 28;
    }
    return 30;
}

// Nhap ngay
void NhapNgay(Date &a) {
    cout << "Nhap ngay: "; cin >> a.d;
    cout << "Nhap thang: "; cin >> a.m;
    cout << "Nhap nam: "; cin >> a.y;
}

// Xuat ngay
void XuatNgay(Date a) {
    cout << a.d << "/" << a.m << "/" << a.y << endl;
}

// Tim ngay ke tiep
void NgayKeTiep(Date a) {
    int maxDay = SoNgayTrongThang(a.m, a.y);
    a.d++;
    if (a.d > maxDay) {
        a.d = 1;
        a.m++;
        if (a.m > 12) {
            a.m = 1;
            a.y++;
        }
    }
    cout << "Ngay ke tiep la: ";
    XuatNgay(a);
}

// b) Viet chuong trinh nhap ho ten, diem toan,
// diem van cua mot hoc sinh.
// Tinh diem trung binh va xuat ket qua

struct HS {
    string hoten;
    float toan, van;
};

// Nhap thong tin hoc sinh
void NhapHS(HS &a) {
    cin.ignore(); // bo ky tu xuong dong con lai
    cout << "Nhap ho ten: ";
    getline(cin, a.hoten);
    cout << "Nhap diem Toan: ";
    cin >> a.toan;
    cout << "Nhap diem Van: ";
    cin >> a.van;
}

// Xuat ket qua
void XuatHS(HS a) {
    float dtb = (a.toan + a.van) / 2;
    cout << "Hoc sinh: " << a.hoten << endl;
    cout << "Diem trung binh = " << dtb << endl;
}

// Ham main
int main () {
	cout << "=== Bai4 a) ===\n";
	Date d;
	NhapNgay(d);
	NgayKeTiep(d);
	
	cout <<"=== Bai4 b) ===\n";
	HS h;
	NhapHS(h);
	XuatHS(h);
	
	return 0;
}
