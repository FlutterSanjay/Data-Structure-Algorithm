// Minimum Cost for Ticket

// T.C -> O(3^n)
// S.C -> O(n)
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& day,vector<int>& cost,int i){
    // Base Case
    if(i >= day.size())
        return 0;

    // 1 day pass
    int cost1 = cost[0] + solve(day, cost, i + 1);

    // 7 day pass
    int endDay = day[i] + 7 - 1;
    int j = i;
    
    while(j<day.size() && day[j]<=endDay){
        j++;
    }
    int cost7 = cost[1] + solve(day, cost, j);


    // 30 day Pass
    endDay = day[i] + 30 - 1;
    j = i;

    while(j<day.size() && day[j]<=endDay){
        j++;
    }
    int cost30 = cost[2] + solve(day, cost, j);

    return min(cost1, min(cost7, cost30));
}

int main(){

    vector<int> cost = {2,7,15};
    vector<int> day = {1,2,3,4,5,6,7,8,9,10,30,31};

    int result = solve(day, cost, 0);
    cout << "Minimum Cost for Ticket : " << result;
    return 0;
}