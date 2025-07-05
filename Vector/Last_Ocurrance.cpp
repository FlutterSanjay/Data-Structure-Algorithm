// find the last occurance of given no
#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector <int> v(6); // vector declaration
    for(int i=0;i<6;i++){
        cout<<"Enter your no:";
        cin>>v[i];
    }
    int x,occurance=0;
    cout<<"Enter your no to search:";
    cin>>x;
    for(int i=6;i>0;i--){
        if(v[i]==x){
            occurance=i;
            break;
        }
    }
    if(occurance==0){
        cout<<"Data Not Found !";
    }
    else{
        cout<<"Last Occurance Index No:"<<occurance;
    }
    return 0;
}