#include<iostream>
using namespace std;

int main(){
    int arr[3][3]={{1,2,4},{2,5,8},{0,2,9}};
    int max=arr[0][0];
    int min=arr[0][0];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(arr[i][j]>max){
                max=arr[i][j];
            }
            else if(arr[i][j]<min){
                min=arr[i][j];
            }
        }
    }
    cout<<"Max :"<<max<<endl;
    cout<<"Min :"<<min<<endl;
    return 0;
}