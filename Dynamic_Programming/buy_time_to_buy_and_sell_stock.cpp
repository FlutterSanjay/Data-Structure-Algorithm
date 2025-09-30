// Best Time to Buy or Sell the Stock
#include <bits/stdc++.h>
using namespace std;

int maxProfitGain(vector<int> &price)
{
    int mini = price[0];
    int maxProfit = 0;
    int n = price.size();
    for (int i = 1; i < n; i++)
    {
        int cost = price[i] - mini;
        maxProfit = max(maxProfit, cost);
        mini = min(mini, price[i]);
    }
    return maxProfit;
}
int main()
{
    vector<int> price = {7, 1, 5, 3, 6, 4};
    cout << maxProfitGain(price);

    return 0;
}