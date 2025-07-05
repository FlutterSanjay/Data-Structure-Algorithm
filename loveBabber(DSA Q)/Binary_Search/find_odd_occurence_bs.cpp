// Type-3 Problem (Imp)
// Find the Odd Occurence of Element using Binary Search
#include<bits/stdc++.h>
using namespace std;

int findOddOccurence(vector<int> arr){
    int s = 0;
    int e = arr.size() - 1;

    while(s<=e){
        int mid = (s + e) / 2;
        if(s==e){
            return s;
        }

        //mid==Even
        if(mid%2==0){
            if(arr[mid]==arr[mid+1]){
                s = mid+2;
            }else{
                e = mid;
            }
        }else{
            if(arr[mid-1]==arr[mid]){
                s = mid + 1;
            }else{
                e = mid - 1;
            }
        }
    }
}

int main(){

    vector<int> arr = {5, 5, 4, 4, 3, 3, 2, 2, 4, 600, 600, 4, 4};
    int result = findOddOccurence(arr);
    cout << "Odd Occurnce Element :" << arr[result];
    return 0;
}