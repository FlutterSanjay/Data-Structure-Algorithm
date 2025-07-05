#include<iostream>
using namespace std;
int main(){
 int n;
 cout<<"Enter the Number of Row :";
 cin>>n;
for(int row=0;row<n;row++){
    //space 
    for(int space=0;space <n-1-row;space++){
        cout<<" ";
    }
    //star
    for(int star=0;star<2* row+1;star++){
        cout<<"*";
    }
    cout<<endl;
}
 return 0;
}