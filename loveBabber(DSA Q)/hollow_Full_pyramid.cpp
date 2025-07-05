#include<iostream>
using namespace std;
int main(){
 int n;
 cout<<"Enter the Number of Row :";
 cin>>n;
for(int row=0;row<n;row++){
    for(int space =0;space<n-1-row;space++){
        cout<<"  ";
    }
    for(int col=0;col<2*row+1;col++){
        if(row==0||col==0||col==2*row){
            
            cout<<"* ";
        }else{
            if(row==n-1){
                cout<<"* ";
            }else{
            cout<<"  ";
        }
    }
    }
    cout<<endl;
}
 return 0;
}