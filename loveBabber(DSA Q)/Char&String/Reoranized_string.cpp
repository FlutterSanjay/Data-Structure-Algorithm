// Reorganized the String
#include<bits/stdc++.h>
using namespace std;

string reorganizedString(string s){

    int hash[26] = {0};

// place the character count in hash
    for (int i = 0; i < s.size();i++){
        hash[s[i] - 'a']++; // increment at particular index
    }

    // find most occurence char
    char max_freq_char;
    int max_freq = INT_MIN;
    for (int i = 0; i < 26;i++){
        if(hash[i]>max_freq){
            max_freq = hash[i];
            max_freq_char = i + 'a';
        }
    }

    int index = 0;
    while(max_freq>0 && index<s.size()){
        s[index] = max_freq_char;
        max_freq--;
        index += 2;
    }

    if(max_freq!=0){
        return "";
    }

    hash[max_freq_char - 'a'] = 0;

    // let place the rest of the character
    for (int i = 0; i < 26;i++){
        while(hash[i]>0){
            index = index >= s.size() ? 1 : index;

            s[index] = i + 'a';
            hash[i]--;
            index += 2;
        }
    }
    return s;
}
int main(){
    string s = "aaab";

    string result = reorganizedString(s);
    cout << "Reorganized String : " << result << endl;

    return 0;
}