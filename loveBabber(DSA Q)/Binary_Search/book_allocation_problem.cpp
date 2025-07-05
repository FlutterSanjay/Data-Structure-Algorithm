// Book Allocation Problem
//Geek for Geeks - Allocate the min no of Pages to each student 

// Painter Problem Similar to book Allocation
#include<bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> arr,int M,int N,int sol){
    int pageSum = 0;
    int c = 1;

    for (int i = 0; i < N;i++){
        if(arr[i]>sol)
            return false;
        
        if(arr[i] + pageSum > sol){
            c++;
            pageSum = arr[i];
            if(c>M)
                return false;
        }else{
            pageSum += arr[i];
        }
    }
    return true;
}

int bookAllocation(vector<int>arr,int M,int N){
    if(M>N)
        return -1;

    int s = 0;
    int e = accumulate(arr.begin(), arr.end(), 0);
    int ans = -1;

    while(s<=e){
        int mid = s + (e - s) / 2;

        if(isPossible(arr,M,N,mid)){
            ans = mid;
            e = mid - 1; // check at the Left Side
        }else{
            s = mid + 1; // check at Right Side
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {12,34,67,90};
    int m = 2;
    int n = arr.size();
    int result = bookAllocation(arr, m, n);
    cout << "The Minimum No of Pages Allocated : " << result << endl;

    return 0;
}