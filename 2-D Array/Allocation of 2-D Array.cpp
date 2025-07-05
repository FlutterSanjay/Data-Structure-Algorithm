// allocation of heap memory
#include<iostream>
using namespace std;
int main(){
    int row;
    cout<<"Enter your Row:";
    cin>>row;
    int col;
    cout<<"Enter your coloumn : ";
    cin>>col;

    // creating 2-D Array
    int **arr=new int *[row];

    for(int i=0;i<row;i++){
       arr[i]=new int[col];
    }

    // taking input
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
           cout<<"Enter your no: ";
           cin>>arr[i][j];
        }
    }

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}