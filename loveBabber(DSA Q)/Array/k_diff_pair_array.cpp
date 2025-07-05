//  K-diff Pairs in an Array
// Using Two Pointer Approach

#include<bits/stdc++.h>
using namespace std;

int findKUniquePair(vector<int> arr,int k)
{
    sort(arr.begin(), arr.end());

    int i = 0;
    int j = 1;

    // for Unique Element using Set
    set<pair<int, int>> ans;

    while(j<=arr.size()-1){
        int diff = arr[j] - arr[i];
        if(diff==k){
            ans.insert({arr[i], arr[j]});
            i++;
            j++;
        }else if(diff > k){
            i++;
        }else{
            j++;
        }
        if(i==j)
            j++;
    }
    return ans.size();
}

int main(){

    vector<int> arr= {3, 1, 4, 1, 5};
    int k = 2;

    int result = findKUniquePair(arr,k);
    cout << "No of K Unique Pair :" << result << endl;

    return 0;
}