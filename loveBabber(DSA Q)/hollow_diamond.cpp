#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the Number of Row :";
    cin>>n;
    
//First Part    
for(int row=0;row<n;row++){
    
    //Starting Space
    for(int space=0;space<n-row-1;space++){
        cout<<" ";
    }
    for(int col=0;col<2*row+1;col++){
        if(col==0 || col==2*row){
            cout<<"*";
        }else{
            cout<<" ";
        }
    }
    cout<<endl;
    
}

// second part
for(int row=0;row<n;row++){
 
 // starting space
 for(int space=0;space<row;space++){
     cout<<" ";
 }
 
// Total no of character
for(int col=0;col<2*n-2*row-1;col++){

 // first & last star
 if(col==0 || col==2*n-2*row-2){
     cout<<"*";
 }
 else{
     cout<<" ";
 }
}
cout<<endl;
}
    return 0;
}