// Find the Total No of Occurence
// Formula -> Last Occurence - First Occurence + 1
#include<bits/stdc++.h>
using namespace std;

int first_Occurence(vector<int>arr,int target){
    int s = 0;
    int e = arr.size() - 1;
    int storeIndex;
    while(s<=e){
        int mid = s + (e - s) / 2;
        if(arr[mid]==target){
            storeIndex = mid;
            e = mid - 1;
        }else if(arr[mid]<target){
            s = mid + 1;
        }else{
            e = mid - 1;
        }
    }
    return storeIndex;
}



int last_Occurence(vector<int>arr,int target){
    int s = 0;
    int e = arr.size() - 1;
    int storeIndex;
    while(s<=e){
        int mid = s + (e - s) / 2;
        if(arr[mid]==target){
            storeIndex = mid;
            s = mid +1;
        }else if(arr[mid]<target){
            s = mid + 1;
        }else{
            e = mid - 1;
        }
    }
    return storeIndex;
}

int main(){
    vector<int> arr = {1, 2, 3, 3, 3, 3, 4, 5, 6};
    int target = 3;
    int firstIndex = first_Occurence(arr, target);
    int lstIndex = last_Occurence(arr, target);

    cout << "Total no of Occurence :" << (lstIndex-firstIndex + 1);
    return 0;
}