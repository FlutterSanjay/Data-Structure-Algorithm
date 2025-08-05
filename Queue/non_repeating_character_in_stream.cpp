// Non repeating character in stream
#include<bits/stdc++.h>
using namespace std;

string NonRepeatingCharacter(string& s){
    queue<char> q;
    string ans = "";
    int freq[26] = {0};

    for (int i = 0; i < s.length();i++){
        char ch = s[i];
        freq[ch - 'a']++;
        q.push(ch);

        while(!q.empty()){
            if(freq[q.front() - 'a']>1){
                q.pop();
            }else{
                ans.push_back(q.front());
                break;
            }
        }

        if(q.empty()){
            ans.push_back('#');
        }
    }
    return ans;
}

int main(){
     string s="aabc";
  string ans=NonRepeatingCharacter(s);
  cout<<ans<<endl;


    return 0;
}