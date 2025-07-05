#include<iostream>
using namespace std;

int main(){
    for(int row=0;row<5;row++){
        cout<<"* ";
        if(row==0){
            
        }else if(row==4){
            for(int col=0;col<row+1;col++){
                cout<<"* ";
            }
        }
        else{
            for(int i=0;i<row;i++){
                cout<<"  ";
            }
            cout<<"* ";
        }
        cout<<endl;
    }
    return 0;
    
}