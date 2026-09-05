#include <bits/stdc++.h>
using namespace std;

struct CongTy
{
    struct NV
    {
        string maNV;
        string hoten;
        string phongban;
        int luongcb;
        int thuong;
        int thucLanh;
    };

    NV ds[100]; // mang nhan vien, gia su toi da 100 nguoi
    int n;      // so luong nh�n vi�n

    void NhapDS()
    {
        cout << "Nhap so nhan vien: ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cout << "\nNhap nhan vien thu " << i + 1 << ":\n";
            cout << "Nhap ma NV: ";
            cin >> ds[i].maNV;
            cin.ignore();
            cout << "Nhap ho ten: ";
            getline(cin, ds[i].hoten);
            cout << "Nhap phong ban: ";
            cin >> ds[i].phongban;
            cout << "Nhap luong co ban: ";
            cin >> ds[i].luongcb;
            cout << "Nhap thuong: ";
            cin >> ds[i].thuong;
            ds[i].thucLanh = ds[i].luongcb + ds[i].thuong;
        }
    }

    void XuatNV(NV nv)
    {
        cout << nv.maNV << " - " << nv.hoten << " - "
             << nv.phongban << " - LuongCB: " << nv.luongcb
             << " - Thuong: " << nv.thuong
             << " - Thuc lanh: " << nv.thucLanh << endl;
    }

    void XuatDS()
    {
        for (int i = 0; i < n; i++)
        {
            XuatNV(ds[i]);
        }
    }

    void TongThucLanh()
    {
        long long tong = 0;
        for (int i = 0; i < n; i++)
            tong += ds[i].thucLanh;
        cout << "Tong thuc lanh thang = " << tong << endl;
    }

    void LuongCBThapNhat()
    {
        int minLCB = ds[0].luongcb; // lay luong co ban cua NV dau tien
        for (int i = 1; i < n; i++)
        {
            if (ds[i].luongcb < minLCB)
                minLCB = ds[i].luongcb;
        }
        cout << "Danh sach NV co luong co ban thap nhat:\n";
        for (int i = 0; i < n; i++)
        {
            if (ds[i].luongcb == minLCB)
                XuatNV(ds[i]);
        }
    }

    void DemThuong()
    {
        int dem = 0;
        for (int i = 0; i < n; i++)
        {
            if (ds[i].thuong >= 1200000)
                dem++;
        }
        cout << "So NV co thuong >= 1200000: " << dem << endl;
    }

    void SapXep()
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (ds[i].phongban > ds[j].phongban ||
                    (ds[i].phongban == ds[j].phongban && ds[i].maNV < ds[j].maNV))
                {
                    swap(ds[i], ds[j]);
                }
            }
        }
        cout << "Danh sach sau khi sap xep:\n";
        XuatDS();
    }
};

int main()
{
    CongTy ct;
    ct.NhapDS();

    cout << "\n=== a. Tong thuc lanh ===\n";
    ct.TongThucLanh();

    cout << "\n=== b. Luong co ban thap nhat ===\n";
    ct.LuongCBThapNhat();

    cout << "\n=== c. Dem NV thuong >= 1200000 ===\n";
    ct.DemThuong();

    cout << "\n=== d. Sap xep danh sach ===\n";
    ct.SapXep();

    return 0;
}
