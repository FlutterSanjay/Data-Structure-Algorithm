// ButterFly Pattern
#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter Your Row : ";
    cin>>n;
    for(int row=0;row<n;row++){
        for(int col=0;col<row+1;col++){
            cout<<"* ";
        }
        for(int space=0;space<n-1-row;space++){
            cout<<"  ";
        }
        for(int space=0;space<n-1-row;space++){
            cout<<"  ";
        }
        
         for(int col=0;col<row+1;col++){
            cout<<"* ";
            
        }
        cout<<endl;
        
    }
    
    for(int row=0;row<n;row++){
        for(int col=0;col<n-row;col++){
            cout<<"* ";
        }
        for(int space=0;space<row;space++){
            cout<<"  ";
        }
         for(int space=0;space<row;space++){
            cout<<"  ";
        }
        for(int col=0;col<n-row;col++){
            cout<<"* ";
        }
        
        cout<<endl;
    }
    return 0;
    
}