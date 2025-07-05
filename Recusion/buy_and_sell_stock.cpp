// Buy And Sell Stock

// T.C & S.C = O(n)

#include<bits/stdc++.h>
using namespace std;

void BuyAndSell(vector<int>& price, int i,int& minPrice,int& maxProfit){

// base Case
if(i >= price.size())
    return;

    if(minPrice > price[i]){
        minPrice = price[i];
    }
    int todayProfit = price[i] - minPrice;
    if(todayProfit > maxProfit){
        maxProfit = todayProfit;
    }

    // Recursive Relation
    BuyAndSell(price, i + 1, minPrice, maxProfit);
}
int main(){
    vector<int> price = {7, 1, 5, 3, 6, 4};
    int minPrice = INT_MAX;
    int maxProfit = INT_MIN;

    BuyAndSell(price, 0, minPrice, maxProfit);
    cout << "Max Profit : " << maxProfit;
    return 0;
}