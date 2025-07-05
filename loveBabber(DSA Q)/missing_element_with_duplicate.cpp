#include<iostream>
#include<vector>
using namespace std;
void findMissing(vector<int> arr){
 
 int i=0;
 // Sort the array
 while(i<arr.size()){
     int index=arr[i];
     if(arr[index]!=arr[i]){
         swap(arr[i],arr[index]);
         i++;
     }else{
         i++;
     }
 }
 // find the missing element
 for(int i=0;i<arr.size();i++){
     if(arr[i]!=i+1){
         cout<< i+1<<" ";
     }
 }
}
int main(){
    vector<int> arr{1,2,2,2,3};
    findMissing(arr);
    return 0;
}