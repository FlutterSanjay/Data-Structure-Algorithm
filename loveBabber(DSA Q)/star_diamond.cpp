#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the no of Row :";
    cin>>n;
    
    // Half Part
    for(int row=0;row<n;row++){
        // Half Pyramid
        for(int col=0;col<n-row;col++){
            cout<<"* ";
        }
    
        
        // Full Space Pyramid
    
    for(int space =0;space<2*row+1;space++){
        cout<<"  ";
    }    
        // Half Pyramid
        
        for(int col=0;col<n-row;col++){
            cout<<"* ";
        }
         cout<<endl;
    }
    
    //Half Part
    for(int row=0;row<n;row++){
        //Half Inverted Pyramid
        for(int col=0;col<row+1;col++){
            cout<<"* ";
        }
        // Full Space Inverted Pyramid
        for(int space=0;space<2*n-2*row-1;space++){
            cout<<"  ";
        }
        
        // Half Inverted Pyramid
        for(int col=0;col<row+1;col++){
            cout<<"* ";
        }
        cout<<endl;
    }
   
    return 0;
}