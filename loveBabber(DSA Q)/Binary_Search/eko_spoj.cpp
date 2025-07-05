// Eco Spoj
#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> arr,int m,int mid){

    int woodCutting = 0;
    for (int i = 0;i<arr.size();i++){
        if(arr[i]>mid){
            woodCutting += (arr[i] - mid);
        }

    }
    return woodCutting>=m;
}
int WoodCut(vector<int> arr,int m){

    int s = 0;
    int e = *max_element(arr.begin(), arr.end());
    int ans = -1;

    while(s<=e){
        int mid = s + (e - s) / 2;

        if(isPossible(arr,m,mid)){
            ans = mid;
            s = mid + 1;
        }else{
            e = mid - 1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {20, 15, 10, 17};
    int m = 7;

    int result = WoodCut(arr, m);
    cout << result << endl;
    return 0;
}