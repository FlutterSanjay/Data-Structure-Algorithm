// Valid Anagram
// TC - O(n+m)

#include<bits/stdc++.h>
using namespace std;

bool validAnagram(string s,string t){
    int freqTable[256] = {0};
    
    // increment
    for(int i=0;i<s.length();i++){
        freqTable[s[i]]++;
    }
    // decrement
    for(int i=0;i<t.length();i++){
        freqTable[t[i]]--;
    }
    
    // check all table value is zero or not
    for(int i=0;i<256;i++){
        if(freqTable[i]!=0){
            return false;
        }
    }
    
    return true;
    
}

int main(){
    string s="anagram";
    string t="nagaram";
    bool result = validAnagram(s,t);
    cout<<"Vald Anagram :"<<result<<endl;
    
    
    return 0;
}