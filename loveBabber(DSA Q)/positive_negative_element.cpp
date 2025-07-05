#include<iostream>
#include<vector>
using namespace std;
int main(){
    int start=1;
    int i=0;
    vector<int> arr {-1, 2, -3, 4, -5, 6};
    while(i<arr.size()){
        if(arr[i]<=0){
            swap(arr[i],arr[start]);
            i+=2;
            start+=2;
        }
        else{
            i++;
            start++;
        }
    }
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}