// Return the minimum no of squares to make the sum of equal to N leetcode - 279

// T.C - O(n^n)
// S.C - O(n)
#include<bits/stdc++.h>
using namespace std;
int solve(int num){

    // Base Case
    if( num == 0)
        return 1;
    
    if(num < 0)
        return 0;

    // Processing
    int ans = INT_MAX;
    int i = 1;
    int end = sqrt(num);

    while(i<= end){
        int perfetchSquare = i * i;
        int noOfPerfetchSquare = 1 + solve(num - perfetchSquare);
        if( ans > noOfPerfetchSquare){
            ans = noOfPerfetchSquare;
        }
        ++i;
    }
    return ans;
}
int main(){
    int num = 13;
    int result = solve(num) - 1;
    cout << "Minimum No of Perfetch Squares :" << result;
    return 0;
}