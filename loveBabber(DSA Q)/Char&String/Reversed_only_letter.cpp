// Reverse Only Letter

#include<bits/stdc++.h>
using namespace std;

string reverseOnlyLetter(string s){
    int i = 0;
    int e = s.length();
    int j = e-1;
    while(i<=j){
        if(!isalpha(s[i]) && !isalpha(s[j])){
            i++;
            j--;
        }else if(!isalpha(s[i])){
            i++;
        }else if( !isalpha(s[j])){
            j--;
        }else{
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
    return s;
}

int main(){
    string s = "ab-cd";
    string result = reverseOnlyLetter(s);
    cout << "Reverse : " << result << endl;
    return 0;
}