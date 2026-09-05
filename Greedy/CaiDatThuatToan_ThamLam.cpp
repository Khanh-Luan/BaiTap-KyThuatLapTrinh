#include <bits/stdc++.h>
using namespace std;

void greedyCoinChange(int amount)
{
    // Bước 1: Khởi tạo tập dữ liệu đã sắp xếp tối ưu (mệnh giá lớn ưu tiên trước)
    vector<int> coins = {500, 200, 100, 50, 20, 10, 5, 2, 1};
    vector<int> selected_coins;

    // Bước 2: Duyệt qua các lựa chọn từ tốt nhất đến kém nhất
    for (int i = 0; i < coins.size(); i++)
    {
        // Lấy nhiều nhất có thể đối với mệnh giá đang xét
        while (amount >= coins[i])
        {
            amount -= coins[i];
            selected_coins.push_back(coins[i]);
        }
    }

    // In kết quả
    for (int coin : selected_coins)
    { // duyệt qua các coin trong vector selected_coins
        cout << coin << " ";
    }
}

int main()
{
    int amount = 873;
    greedyCoinChange(amount);
    return 0;
}