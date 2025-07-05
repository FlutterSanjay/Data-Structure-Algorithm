// Integer To Roman 
#include<bits/stdc++.h>
using namespace std;
string integerToRoman(int& num){
    string ans = "";
    vector<string> romanSymbol = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    for (int i = 0;i<13;i++){
        while(num>=values[i]){
            ans+=romanSymbol[i];
            num -= values[i];
        }
    }
    return ans;
}
int main(){
    int s = 1994;
    string result = integerToRoman(s);
    cout << result << endl;

    return 0;
}