// check the sorted array or not
#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector <int> v(6);
    for(int i=0;i<6;i++){
        cout<<"Enter your no:";
        cin>>v[i];
    }

    bool flag=true;
    for(int i=0;i<6;i++){
        if(v[i]<=v[i-1]){
            flag=false;
        }
    }
    if(flag==1){
        cout<<"Sorted Array !";
    }
    else {
        cout<<"Array Not Sorted !";
    }

    return 0;
}