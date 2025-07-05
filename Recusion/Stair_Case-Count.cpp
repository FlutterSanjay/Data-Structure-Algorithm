// Stair Case Count to Reach to Nth Stair case Problem
#include<bits/stdc++.h>
using namespace std;

int countStair(int n){
    // Base Case
    if( n==0 || n==1) return 1;
    
    return countStair(n-1) + countStair(n-2);
}
int main(){
    int n;
    cout<<"Enter the No of Stair :";
    cin>>n;
    int ans = countStair(n);
    cout<<"Total No Of Stair :"<<ans;
    return 0;
}