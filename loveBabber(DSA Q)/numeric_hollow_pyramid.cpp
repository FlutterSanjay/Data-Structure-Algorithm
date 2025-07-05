#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter your Row :";
    cin>>n;
     int start =0;
     int end=1;
    for(int row=0;row<n;row++){
        for(int space=0;space<n-1-row;space++){
            cout<<"  ";
        }
       
        for(int i=0;i<2*row+1;i++){
            if(row==0 ||i==0){
                cout<<i+1;
                start++;
            }else if(row==n-1){
                if(i%2==0){
                    cout<<++end;
                }else{
                    cout<<"   ";
                }
             
            }
            else{
                cout<<"  ";
                if(i==2*row){
                    cout<<start;
                }
            }
            
        }
        
        cout<<endl;
    }
    return 0;
}