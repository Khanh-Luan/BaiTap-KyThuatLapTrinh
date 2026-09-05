#include <bits/stdc++.h>
//===== dynamic-programming, greedy =====
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long current_sum = 0;
    long long max_sum = -1e18;
    long long x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        current_sum += x;
        max_sum = max(max_sum, current_sum);
        if (current_sum < 0)
        {
            current_sum = 0;
        }
    }
    cout << max_sum;
}