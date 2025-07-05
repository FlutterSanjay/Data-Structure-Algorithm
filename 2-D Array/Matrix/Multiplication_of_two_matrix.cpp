// find the Multiplication of two matrix
#include<iostream>
using namespace std;
int main(){
    int n1,m1,n2,m2;
    cout<<"Enter the size of row :";
    cin>>n1;
    cout<<"Enter the size of Col :";
    cin>>m1;

    // for matrix two
    cout<<"Enter the size of row :";
    cin>>n2;
    cout<<"Enter the size of Col :";
    cin>>m2;

    int arr[2][2];
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++){
            cout<<"Enter your Element : ";
            cin>>arr[i][j];
        }
    }


     int brr[2][2];
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++){
            cout<<"Enter your Element : ";
            cin>>brr[i][j];
        }
    }
int sum=0;
    if(n1==m2){
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                sum=sum+(arr[i][j]*brr[i][j]);
            }
        }
    }
    cout<<sum<<" ";
    return 0;
}