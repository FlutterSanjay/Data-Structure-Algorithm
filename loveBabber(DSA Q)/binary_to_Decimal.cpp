#include<iostream>
#include<math.h>
using namespace std;

int binaryToDecimal(int n){
    int decimal;
    int i = 0;
    while(n>0){
        int bit = n % 2;
        decimal += bit * pow(2, i++);
        n = n / 10;
    }
    return decimal;
}
int main(){
    int n;
    cout << "Enter Your Number :";
    cin >> n;
    cout << "Decimal Number :" << binaryToDecimal(n);
    return 0;
}