// count the no of element greater than givrn no
#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector <int> v(6);
    for(int i=0;i<6;i++){
        cout<<"Enter your no:";
        cin>>v[i];
    }
    int x,count=0;
    cout<<"Enter your no to search:";
    cin>>x;
    for(int i=0;i<6;i++){
        if(v[i]>x){
            count++;
        }
    }
    cout<<"Total no greater than given no:"<<count;
    return 0;
}