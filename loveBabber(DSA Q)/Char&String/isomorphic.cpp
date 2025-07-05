// Isomorphic
#include<bits/stdc++.h>
using namespace std;

bool isomorphic(string s,string t){
    int hash[256]={0};
    bool chMap[256]= {0};
    
    for(int i=0;i<s.size();i++){
        if(hash[s[i]]== 0 && chMap[t[i]] == 0){
            hash[s[i]] =t[i];
            chMap[t[i]]=true;
        }
    }
    
    for(int i=0;i<s.size();i++){
        if(hash[s[i]] != t[i]){
            return false;
        }
    }
    return true;
}

int main(){
  string s="egg";
  string t = "add";
  
  bool result = isomorphic(s,t);
  cout<<" Isomorphic : "<<result<<endl;
        return 0;
}