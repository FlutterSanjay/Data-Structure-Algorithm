//8. String to Integer (atoi)
#include<bits/stdc++.h>
using namespace std;

int stringToInteger(string& s){
    int num = 0;
    int i = 0;
    int sign = 1;//+ve
 // check for the whitespace 
    while(s[i]==' '){
        i++;
    }
// check for sign part
    if(i<s.size() && (s[i]=='-' ||s[i]=='+')){
        sign = s[i] == -1 ? -1 : 1;
    }
// check for digit part
    while(i<s.size()&& isdigit(s[i])){
        if(num>INT_MAX/10 || (num==INT_MAX && s[i]>'7')){
            return sign == -1 ? INT_MIN : INT_MAX;
        }
        num = num * 10 + (s[i] - '0');
        i++;
    }
    return sign * num;
}
int main(){
    string s = "   123hello";
    int result = stringToInteger(s);
    cout << "Integer :" << result << endl;

    return 0;
}