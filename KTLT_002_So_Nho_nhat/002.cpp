#include <bits/stdc++.h>
//===== greedy =====
using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n % 9 != 0)
        cout << n % 9;
    // n/9 : số lượng số 9
    for (int i = 1; i <= n / 9; i++)
        cout << 9;
    return 0;
}
