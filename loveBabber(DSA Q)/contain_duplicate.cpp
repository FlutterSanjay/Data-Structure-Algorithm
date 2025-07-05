#include<iostream>
#include<vector>
using namespace std;
 void containsDuplicate(vector<int> arr) {
    int i=0;
    while(i<arr.size()){
    int index=abs(arr[i]);
    if(arr[index-1]<0){
      i++;  
        // return true;
    }else{
        arr[index-1]*=-1;
        i++;
    }
    }
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
        // return false;
    }
int main(){
    vector<int> arr{3,1,2,2,3};
containsDuplicate(arr);
    return 0;
}