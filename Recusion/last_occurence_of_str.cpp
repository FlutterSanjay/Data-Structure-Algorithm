// Find the Last Occuence of given char
// Method =1 left -> Right 
// Mathod =2 Right -> left

// Method -> 1
#include<bits/stdc++.h>
using namespace std;

// int lastOccurence(string &arr,int n,int i,char& x){
//     static int ans = -1;
//     // Base Case
//     if(i > n){
//         return ans;
//     }

//     if(arr[i] == x){
//         ans = i;
//     }

//     return lastOccurence(arr, n, i + 1, x);
// }


// Method 2
int lastOccurence(string &arr,int n,char& x){
    // Base Case
    if(arr[n] == x){
        return n;
    }
    return lastOccurence(arr, n - 1, x);
}
int main(){
    string arr = "abcegd";
    int n = arr.size() -1;
    int i = 0;
    char x = 'd';
    // int result = lastOccurence(arr, n, i, x);
    int result = lastOccurence(arr, n, x);
    cout << "Index At : " << result;
    return 0;
}