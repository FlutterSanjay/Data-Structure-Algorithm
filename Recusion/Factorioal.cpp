// find the factoial of given no
#include<iostream>
using namespace std;
int fact(int num){
    if(num==0) return 1;
    return num*fact(num-1);
}
int main(){
    int var;
    cout<<"Enter your no: ";
    cin>>var;
    int result=fact(var);
    cout<<"Factorial of given no: "<<result;
    return 0;
    
}