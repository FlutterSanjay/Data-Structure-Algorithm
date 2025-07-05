#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the Row :";
    cin>>n;
    
    int start;
    for(int row=0;row<n;row++){
        //space
        for(int space =0;space<n-1-row;space++){
            cout<<"  ";
        }
        // number
        for(int num=0;num<row+1;num++){
            start=row+1+num;
            cout<<start<<" ";
        }
        start--;
        // Revese number 
        for(int i=0;i<row;i++){
            cout<<start<<" ";
            start--;
        }
        cout<<endl;
    }
}