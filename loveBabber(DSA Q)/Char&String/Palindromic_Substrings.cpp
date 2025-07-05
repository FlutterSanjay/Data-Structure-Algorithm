//647. Palindromic Substrings
/* Given a string s, return the number of palindromic substrings in it.
A string is a palindrome when it reads the same backward as forward.
A substring is a contiguous sequence of characters within the string.
*/

#include<bits/stdc++.h>
using namespace std;

int expandRemaining(string s,int i,int j){
    int count = 0;
    while (i >= 0 && j < s.length() && s[i]==s[j]){
        i--;
        j++;
        count++;

    }
    return count;
}

int countPalindromeString(string s){
    int n = s.length();
    int count = 0;

    for (int i = 0; i < n;i++){

        // odd
        int oddAns = expandRemaining(s, i, i);
        count += oddAns;


        // even
        int evenAns = expandRemaining(s, i, i + 1);
        count += evenAns;
    }
    return count;
}

int main(){
    string s = "noon";
    int result = countPalindromeString(s);
    cout << "Total no of Palindromic String : " << result << endl;
    return 0;
}