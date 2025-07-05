// print the snake pattern 123 654 789
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int arr[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<"Enter your no :";
            cin>>arr[i][j];
        }

    }
    for(int i=0;i<3;i++){
        if(i%2==0){
            for(int j=0;j<3;i++){
                cout<<arr[i][j]<<" ";
            }
        }
        else{
            for(int j=2;j>=0;j--){
                cout<<arr[i][j]<<" ";
            }
        }    

        }
        return 0;
    }
