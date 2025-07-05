// Maximum sum of Non-Adjacent Element
#include<bits/stdc++.h>
using namespace std;

void maxElement(vector<int>& arr,int i,int sum,int& maxi){
    // Base Case
    if(i > arr.size() - 1){
        maxi = max(sum, maxi);
        return;
    }

    // include function
    maxElement(arr, i + 2, sum + arr[i], maxi);

    //exclude function
    maxElement(arr, i + 1, sum, maxi);
}
int main(){
    vector<int> arr = {2, 4, 1, 7};
    int i = 0;
    int maxi = INT_MIN;
    int sum = 0;
    maxElement(arr, i, sum, maxi);
    cout << "Max Element : " << maxi;
    return 0;
}