// Decimal to Bianry Conversion using bit
#include<iostream>
#include<math.h>
using namespace std;

int binaryToDecimal(int n){
    int decimal;
    int i = 0;
    while(n>0){
        int bit = n & 1;
        decimal += bit * pow(2, i++);
        n = n / 10;
    }
    return decimal;
}
int main(){
    int n;
    cout<<"Enter Your Binary Number :";
    cin>>n;
    cout<<binaryToDecimal(n);
    return 0;
}

