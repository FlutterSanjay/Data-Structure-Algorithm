// interchanging the rowsof a matrix
#include<iostream>
#include<vector>
using namespace std;

void interchange(int arr[3][3],int row,int col){
    for(int i=0;i<row/2;i++){
        for(int j=0;j<col;j++){
            swap(arr[i][j],arr[row-1-i][j]);
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<arr[i][j]<<" ";
        }
    }
}

int main(){
    int arr[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<"Enter the your No :";
            cin>>arr[i][j];
        }
    }
    interchange(arr,3,3);
    return 0;
}