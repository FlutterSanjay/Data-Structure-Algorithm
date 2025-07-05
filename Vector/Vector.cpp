// take 5 input to vector and print out using for each loop
#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector <int > v(5);
    for(int i=0;i<5;i++){
        cout<<"Enter your no:";
        cin>>v[i];
    }

    for(int ele:v){
        cout<<ele<<" ";
    }
    return 0;
}