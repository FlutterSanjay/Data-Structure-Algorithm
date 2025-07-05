#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the Number of Row :";
    cin>>n;
    for(int row=0;row<n;row++){
        int col;
        for(col=0;col<row+1;col++){
            char ch=col+'A';
            cout<<ch;
        }
        col--;
        for(;col>=1;col--){
            char ch=col+'A'-1;
            cout<<ch;
        }
        cout<<endl;
    }
    return 0;
}