// check the Valid Palindrome II

#include<bits/stdc++.h>
using namespace std;
bool checkPalindrome(string s,int i,int j){
    while(i<=j){
        if(s[i]!=s[j]){
            return false;
        }else{
            i++;
            j--;
        }
    }

    return true;

}

bool palindrome(string s){
    int i = 0;
    int j = s.length() - 1;

    while(i<=j){
        if(s[i]!=s[j]){
            // check by removing one ith and jth part
            return checkPalindrome(s, i + 1, j) || checkPalindrome(s, i, j - 1);
        }else{
            i++;
            j--;
        }
    }
    return true;
}

int main(){
    string s = "abc";
    bool result = palindrome(s);
    cout <<( result?"true":"false");
    return 0;
}