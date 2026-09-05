#include <bits/stdc++.h>
//===== sorting, set/map =====
using namespace std;

const int N = 2e5 + 5;
int a[N];

int main()
{
    int n;
    cin >> n;
    int count = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 1; i < n - 1; i++)
    {
        if (a[i] != a[i + 1])
            count++;
    }
    cout << count;
}
//===== CÁCH 2 =====
// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int n;
//     cin >> n;
//     set<int> s;
//     for (int i = 0; i < n; i++) {
//         int x;
//         cin >> x;
//         s.insert(x); // Nếu x bị trùng với số đã có, set sẽ tự động từ chối nạp thêm
//     }
//     cout << s.size();
// }