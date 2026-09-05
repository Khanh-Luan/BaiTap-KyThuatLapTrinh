#include <bits/stdc++.h>
//===== greedy, sorting ===== 
using namespace std;

const int N = 1e5 + 5;

int a[N];


bool compare(int first_number, int second_number) {

    return first_number > second_number;
}


int main() {

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n, compare); // Sap xep giam dan

    long long ans = 0;

    for (int i = 0; i < n; i++)
        ans += a[i];
 
    for (int i = 2; i < n; i += 3)
        ans -= a[i];

    cout << ans;
}
