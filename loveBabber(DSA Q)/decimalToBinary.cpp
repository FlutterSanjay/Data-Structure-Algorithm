// Decimal to Binary Conversion

#include<iostream>
#include<cmath>
using namespace std;

int decimalToBinary(int n){
    int binary;
    int i = 0;
    while(n>0){
        int bit = n % 2;
        binary = bit * pow(10,i++) + binary;
        n = n/2;

    }
    return binary;

}
int main(){
    int n;
    cout << "Enter Your Number :";
    cin >> n;
    cout << "Binary Number :" << decimalToBinary(n);
    return 0;
}