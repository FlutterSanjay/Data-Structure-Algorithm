// Decimal to Binary Conversion using Bit
#include<iostream>
#include<math.h>
using namespace std;

int decimalToBinary(int n){
    int binary;
    int i = 0;
    while(n>0){
        int bit = (n & 1);
        binary += bit * pow(10, i++);
        n = n >> 1;
    }
    return binary;
}
int main(){
    int n;
    cout << "Enter your Number :";
    cin >> n;
    cout << "Binary Number :" << decimalToBinary(n);
    return 0;
    
}