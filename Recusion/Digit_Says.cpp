// digit says Problem

#include<iostream>
using namespace std;
void name(int n,string arr[10]){
    if(n==0) return ;
    int digit=n%10;
    n/=10;
    name(n,arr);
    cout<<arr[digit]<<" ";
}
int main(){
    int n;
    cout<<"Enter your no : ";
    cin>>n;
    string arr[10]={"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
    name(n,arr);
    return 0;
  
}