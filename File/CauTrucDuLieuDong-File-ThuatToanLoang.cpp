#include <iostream>
#include <fstream>
using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool hopLe(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void loang(int **a, bool **mark, int n, int m, int x, int y, int &kichThuoc) {
    mark[x][y] = true;
    kichThuoc++;

    for (int i = 0; i < 4; i++) {
        int xMoi = x + dx[i];
        int yMoi = y + dy[i];

        if (hopLe(xMoi, yMoi, n, m) &&
            a[xMoi][yMoi] == 1 &&
            mark[xMoi][yMoi] == false) {
            loang(a, mark, n, m, xMoi, yMoi, kichThuoc);
        }
    }
}

int main() {
    ifstream infile("D:/Baitap-KyThuatLapTrinh/File/input.txt");
    ofstream outfile("D:/Baitap-KyThuatLapTrinh/File/output.txt");

    if (!infile) {
        cout << "Khong mo duoc file input.txt";
        return 0;
    }

    int n, m;
    infile >> n >> m;

    int **a = new int*[n];
    bool **mark = new bool*[n];

    for (int i = 0; i < n; i++) {
        a[i] = new int[m];
        mark[i] = new bool[m];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            infile >> a[i][j];
            mark[i][j] = false;
        }
    }

    int soVetDau = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 1 && mark[i][j] == false) {
                soVetDau++;

                int kichThuoc = 0;
                loang(a, mark, n, m, i, j, kichThuoc);

                outfile << "Vet dau thu " << soVetDau
                        << " co kich thuoc: " << kichThuoc << endl;
            }
        }
    }

    outfile << "Tong so vet dau: " << soVetDau << endl;

    for (int i = 0; i < n; i++) {
        delete[] a[i];
        delete[] mark[i];
    }

    delete[] a;
    delete[] mark;

    infile.close();
    outfile.close();

    return 0;
}
