// Longest Common Prefix
// maxm match character from all string toward left to right
#include<bits/stdc++.h>
using namespace std;
string longestCommonPrefix(vector<string>s){
    int i = 0;
    string ans = "";
    while(true){
        char ch = 0; // initialized by null character

        for(auto str:s){
            if(i>=str.length()){
                ch = 0;
                break;
            }

            if(ch==0){
                ch = str[i];
            }
            else if(ch!=str[i]){
                ch = 0;
                break;
            }
        }
        if(ch==0){
            break;
        }
        ans.push_back(ch);
        i++;
    }
    return ans;
}

int main(){
    vector<string> s = {"flower", "flow", "flight"};
    string result = longestCommonPrefix(s);
    cout << "Longest Common Prefix : " << result << endl;
    return 0;
}