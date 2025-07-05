// Aggressive Cow
#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>arr,int k,int n,int mid){

    int pos = arr[0];
    int c = 1;

    for (int i = 0; i < n;i++){
        if(arr[i]- pos>=mid){
            c++;
            pos = arr[i];
            if(c==k)
                return true;
        }
    }
    return false;
}
int aggressiveCow(vector<int>arr,int k){
    int n = arr.size();

    int s = 0;
    int e = arr[n-1] - arr[0]; // max distance between the cow

    int ans = -1;
    while(s<=e){
        int mid = s + (e - s) / 2;

        if(isPossible(arr,k,n,mid)){
            ans = mid;
            s = mid + 1;
        }else{
            e = mid - 1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {1, 2, 4, 8, 9};
    sort(arr.begin(), arr.end());
    int k = 3;

    int result = aggressiveCow(arr, k);
    cout << result << endl;
    return 0;
}