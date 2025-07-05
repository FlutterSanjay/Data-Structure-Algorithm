// A raised to Power B using Recursion
#include<iostream>
using namespace std;

int exponent(long b,long p){
    if(p==0) return 1;
    else{
        long ans = exponent(b, p / 2);
        if(p % 2==0)
            return ans * ans;
        else{
            if(p>0){
               return ans *ans *b;
            }
            else{
                return ans * ans / b;
            }
        }
    }
}

int main(){
    long a, b;
    cout << "Enter Your Base No : ";
    cin >> a;
    cout << "Enter Your Power No :";
    cin >> b;
    long result = exponent(a, b);
    cout << "A Raised to Power B :" << result;
    return 0;
}