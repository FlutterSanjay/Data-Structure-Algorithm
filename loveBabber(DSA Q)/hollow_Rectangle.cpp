#include<iostream>
using namespace std;

int main(){
    for(int row=0;row<3;row++){
        if(row==0 || row==2){
            for(int col=0;col<5;col++){
                cout<<"* ";
            }
        }
        else{
            cout<<"* ";
            for(int space=0;space<3;space++){
                cout<<"  ";
            }
            cout<<"* ";
        }
        cout<<endl;
    }
    return 0;
}