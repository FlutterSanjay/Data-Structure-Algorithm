#include<iostream>
using namespace std;
int main(){
    int arr[6]={0,1,0,3,12,0};
    int i=0;
    int j=0;
    while(j<6){
        if(arr[j]!=0){
            swap(arr[i],arr[j]);
               i++;
               j++;
        }
        else{
               j++;
        }
     
    }
    for(int i=0;i<6;i++){
        cout<<arr[i]<<"\t";
    }
    
    return 0;
}