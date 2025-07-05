// find the power of any value
#include<iostream>
using namespace std;
int power(int a,int p){
    if(p==0) return 1;
    if(p==1) return a;
    int ans=power(a,p/2);
    if(p%2==0) return ans*ans;
    else return a*ans*ans;
}

int main(){
    int base,pwr;
    cout<<"Enter your base & power value : ";
    cin>>base>>pwr;
    int result=power(base,pwr);
    cout<<"pow(x,y) : "<<result;
    return 0;
}