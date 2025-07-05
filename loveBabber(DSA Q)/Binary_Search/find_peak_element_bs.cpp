// Find the Peak elment using Binary search
#include<bits/stdc++.h>
using namespace std;

int peak_element(vector<int>arr){
    int s = 0;
    int e = arr.size() - 1;
   
    while(s<e){
        int mid = s + (e - s) / 2;
        if(s==e){
            return s;
        }

//Line - A
        if(arr[mid]<arr[mid+1]){
               s = mid + 1;
        }
        //Line -B
        else{
            e = mid;
        }
    
    }
    // for single Element Only
}
int main(){
    vector<int> arr = {1};
    int index = peak_element(arr);
    cout << "Peak Element Found at Index : " << index;
    return 0;
}