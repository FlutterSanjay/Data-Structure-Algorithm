// find the duplicate element
#include<iostream>
#include<vector>
using namespace std;

int findDuplicate(vector<int> arr){
    int ans=-1;
    for(int i=0;i<arr.size();i++){
    
    int index=abs(arr[i]);
    if(arr[index]<0){
        ans=index;
        return ans;
    }else{
        arr[index]*=-1;
    }
    
}
return ans;

}

int main(){
    vector<int> arr{1,2,3,4,5,1,2,3,4};
    cout<<findDuplicate(arr);
    return 0;
}