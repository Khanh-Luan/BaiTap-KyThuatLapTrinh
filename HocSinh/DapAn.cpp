#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

#define MAX_HS 100

struct LopHoc {
    struct HocSinh {
        string ten;
        float diemToan;
        float diemVan;
        float diemAnh;
        float diemTB;
    } danhSach[MAX_HS];

    int soLuong;
};

// ==================== NHAP ====================
void nhapLop(LopHoc &lop) {
    cout << "Nhap so luong hoc sinh: ";
    cin >> lop.soLuong;
    cin.ignore();

    for (int i = 0; i < lop.soLuong; i++) {
        printf("\n--- Hoc sinh thu %d ---\n", i + 1);

        printf("  Ten    : ");
        getline(cin, lop.danhSach[i].ten);

        printf("  Diem Toan: ");
        cin >> lop.danhSach[i].diemToan;

        printf("  Diem Van : ");
        cin >> lop.danhSach[i].diemVan;

        printf("  Diem Anh : ");
        cin >> lop.danhSach[i].diemAnh;
        cin.ignore();

        lop.danhSach[i].diemTB =
            (lop.danhSach[i].diemToan +
             lop.danhSach[i].diemVan +
             lop.danhSach[i].diemAnh) / 3.0f;
    }
}

// ==================== TINH DIEM TB LOP ====================
float tinhDiemTBLop(const LopHoc &lop) {
    float tong = 0;
    for (int i = 0; i < lop.soLuong; i++)
        tong += lop.danhSach[i].diemTB;
    return tong / lop.soLuong;
}

// ==================== IN 1 HOC SINH ====================
void inHocSinh(const LopHoc &lop, int i) {
    printf("  %-25s | Toan: %.2f | Van: %.2f | Anh: %.2f | TB: %.2f\n",
           lop.danhSach[i].ten.c_str(),
           lop.danhSach[i].diemToan,
           lop.danhSach[i].diemVan,
           lop.danhSach[i].diemAnh,
           lop.danhSach[i].diemTB);
}

// ==================== XUAT HS DIEM TB CAO NHAT ====================
void xuatHSCaoNhat(const LopHoc &lop) {
    float max = lop.danhSach[0].diemTB;
    for (int i = 1; i < lop.soLuong; i++)
        if (lop.danhSach[i].diemTB > max)
            max = lop.danhSach[i].diemTB;

    printf("\n=== HOC SINH CO DIEM TB CAO NHAT (%.2f) ===\n", max);

    for (int i = 0; i < lop.soLuong; i++)
        if (lop.danhSach[i].diemTB == max)
            inHocSinh(lop, i);
}

// ==================== XUAT HS DUOI TB LOP ====================
void xuatHSDuoiTBLop(const LopHoc &lop) {
    float tbLop = tinhDiemTBLop(lop);

    printf("\n=== HOC SINH CO DIEM TB THAP HON DIEM TB LOP (%.2f) ===\n", tbLop);

    int dem = 0;
    for (int i = 0; i < lop.soLuong; i++) {
        if (lop.danhSach[i].diemTB < tbLop) {
            inHocSinh(lop, i);
            dem++;
        }
    }

    if (dem == 0)
        printf("  (Khong co hoc sinh nao duoi trung binh lop)\n");
}

// ==================== MAIN ====================
int main() {
	
    LopHoc lop;
    nhapLop(lop);
    xuatHSCaoNhat(lop);
    xuatHSDuoiTBLop(lop);

    return 0;
}
