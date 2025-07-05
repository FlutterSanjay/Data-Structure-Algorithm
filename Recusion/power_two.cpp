//Power of two
#include<iostream>
using namespace std;
bool power(int n){
    if(n<=0) return false;
    return ((n&(n-1))==0);
}

int main(){
    int n;
    cout<<"Enter your no :";
    cin>>n;
    bool result=power(n);
    if(result==true) cout<<"It is the Power of Two !...";
    else cout<<"NO is not the Power of Two";
    return 0;
}