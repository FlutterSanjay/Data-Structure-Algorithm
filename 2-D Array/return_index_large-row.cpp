// print the sum of row int 2d array by using function
#include<iostream>
using namespace std;
int print(int arr[][3],int row){
    int temp=0,k=0;
    for(int i=0;i<3;i++){
        int sum=0;
        for(int j=0;j<3;j++){
            sum=sum+arr[i][j];
        }
        cout<<"sum:"<<sum<<endl;
        if(sum>temp){
             temp=sum;
           k=i;
        
           }
    }
    return k;
}
int main(){
    int arr[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<"Enter your no: ";
            cin>>arr[i][j];
        }
    }
    
 int result=print(arr,3);
cout<<"Index no: "<<result;
    return 0;
}