#include<iostream>
#include<climits>
using namespace std;

// void countZeroOne(int arr[],int size){
//     int countZero=0;
//     int countOne=0;
//     for(int i=0;i<size;i++){
//         if(arr[i]==0){
//             countZero++;
//         }
//         else if(arr[i]==1){
//             countOne++;
//         }
//     }
//     cout<<"The Number of Zero in Array : "<<countZero<<endl;
//     cout<<"The Number of One in Array : "<<countOne<<endl;
    
// }

void maxNumber(int arr[],int size){
    
    int max=INT_MIN;
    for(int i=0;i<size;i++){
        if(max<arr[i]){
            max=arr[i];
        }
    }
    cout<<"Max Number in Array : "<<max<<endl;; 
}
void minNumber(int arr[],int size){
    int min=INT_MAX;
    for(int i=0;i<size;i++){
        if(min>arr[i]){
            min=arr[i];
        }
    }
    cout<<"Min Number in Array : "<<min<<endl;
}
int main(){
    int arr[5]={-10,-6,-2,-20,-1};
    maxNumber(arr,5);
    minNumber(arr,5);
    // countZeroOne(arr,5);
    return 0;
}