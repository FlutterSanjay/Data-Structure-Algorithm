// Fins the First Occurence using Binary Search
#include<iostream>
#include<vector>
using namespace std;

int firstOccurence(vector<int> arr,int key){
    int s = 0;
    int e = arr.size() - 1;
    int ans = -1;
    while(s<=e){
        int mid = s + (e - s) / 2;
        if(arr[mid]==key){
            ans = mid;
            e = mid - 1; // for last Ocuurence it move the start s=mid+1
        }else if(arr[mid]>key){
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
    }
    return ans;
}
int main(){
    vector<int> ans{1,3,4,4,4,5,6,7};
    int key = 4;
    cout << "Index at : " << firstOccurence(ans, key);
    return 0;
}