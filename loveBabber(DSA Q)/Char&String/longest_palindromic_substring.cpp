// Longest Palindromic Substring
#include<bits/stdc++.h>
using namespace std;
bool isPalindromic(string &s,int start,int end){
    while(start<end){
        if(s[start]!=s[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
}
string longestPalindromicSubstring(string &s){
    string ans = "";

    for (int i = 0; i < s.size();i++){
        for (int j = i; j < s.size();j++){
            if(isPalindromic(s,i,j)){
                string t = s.substr(i, j - i + 1);
                ans = t.size() > ans.size() ? t : ans;
            }
        }
    }
    return ans;
}

int main(){
    string s = "babad";

    string result = longestPalindromicSubstring(s);
    cout << "Longest Plaindromic Substring : " << result << endl;

    return 0;
}