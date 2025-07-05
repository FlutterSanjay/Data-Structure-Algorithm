// reverse only the vowels
#include<bits/stdc++.h>
using namespace std;

bool checkVowel(char ch){
    if((ch!='a'&&ch!='e'&&ch!='i'&&ch!='o'&&ch!='u')){
        return true;
    }else{
        return false;
    }
}
string reverseVowel(string s){
    int i=0;
    int e=s.length();
    int j=e-1;
    while(i<=j){
        char ch=tolower(s[i]);
        char chj=tolower(s[j]);
        // both are not vowels
        if(checkVowel(ch) && checkVowel(chj)){
            i++;
            j--;
        }
        
        // ith is not vowel
        else if(checkVowel(ch)){
            i++;
        }
        
        // jth is not vowel
        
        else if(checkVowel(chj)){
            j--;
        }
        // i and j both are vowel
        else{
            swap(s[i],s[j]);
            i++;
            j--;
        }
    }
    return s;
}

int main(){
    string s="IceCreAm";
    string result = reverseVowel(s);
    cout<<"Reverse Vowel String : "<<result<<endl;
    return 0;
}