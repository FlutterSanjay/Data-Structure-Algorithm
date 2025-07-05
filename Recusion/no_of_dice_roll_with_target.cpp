// no of Dice Roll with the Target


// T.C - O(2^n) && S.C - O(n)
#include<bits/stdc++.h>
using namespace std;
int solve(int n,int& k,int t){
    // Base Case
    
    if( t < 0)
        return 0;

        if(n == 0 && t ==0){
            return 1;
        }

    if( n==0 && t != 0)
        return 0;

    if( n != 0 && t == 0)
        return 0;

    int ans = 0;
    // processing
    for (int i = 1; i <= k;i++){
        ans = ans + solve(n - 1, k, t - i);
    }
    return ans;
}

int main(){
    int n = 2;
    int k =6;
    int t = 7;
    int result = solve(n, k, t);
    cout << "Result : " << result << endl;

    return 0;
}