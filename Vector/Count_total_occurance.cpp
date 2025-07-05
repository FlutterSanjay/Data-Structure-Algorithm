// count the total no of occurance of given no
#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector <int> v(5);
    
    for(int i=0;i<5;i++){
        cout<<"Enter your no:";
        cin>>v[i];
    }
    int x,count=0;
    cout<<"Enter your no to count the total no of occurance:";
    cin>>x;
    for(int i=0;i<5;i++){
        if(v[i]==x){
            count++;
        }
    }
    cout<<"TOtal no of Occurance: "<<count;
    return 0;
}