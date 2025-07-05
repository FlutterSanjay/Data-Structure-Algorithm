#include<iostream>
using namespace std;

int setBit(int num,int k){
    int setK=1<<k;
    int result=num | setK;
    return result;
    
}
int main(){
    int n=10;
    int k=2;
    cout<<"Set Bit :"<<setBit(n,k);
    return 0;
}