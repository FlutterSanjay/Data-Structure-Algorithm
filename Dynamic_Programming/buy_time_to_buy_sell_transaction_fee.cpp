// Buy Time to Buy & Sell Stock with Transaction Fee
#include <bits/stdc++.h>
using namespace std;

int func(int n, int fee, vector<int> &value)
{
    int aheadNotBuy, aheadBuy, currBuy, currNotBuy;

    aheadNotBuy = aheadBuy = 0;

    for (int ind = n - 1; ind >= 0; ind--)
    {

        // sell
        currNotBuy = max(value[ind] + aheadBuy, 0 + aheadNotBuy);

        // buy
        currBuy = max(-value[ind] - fee + aheadNotBuy,
                      0 + aheadBuy);

        aheadBuy = currBuy;
        aheadNotBuy = currNotBuy;
    }
    return aheadBuy;
}
int main()
{
    vector<int> value = {1, 3, 2, 8, 4, 9};
    int fee = 2;
    int n = value.size();
    cout << func(n, fee, value);

    return 0;
}