#include<iostream>
using namespace std;

int main(){
  
for(int row=0;row<6;row++){
    for(int col=0;col<row;col++){
        cout<<" ";
    }
    for(int i=row;i<6;i++){
        cout<<"* ";
    }
    cout<<endl;
}
    return 0;
}