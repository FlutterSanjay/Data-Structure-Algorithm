// valid string or not leetcode no -1003
#include<bits/stdc++.h>
using namespace std;

bool isValid(string s){
  if(s[0]!='a') return false;

  stack<char> st;

  for(char ch:s){
    if(ch=='a'){
      st.push(ch);
    }else if(ch=='b'){
      if(!st.empty() && st.top() == 'a'){
        st.push(ch);
      }else{
        return false;
      }
       }else{
      // for c
      if(!st.empty() && st.top() =='b'){
        st.pop();
        if(!st.empty() && st.top() == 'a'){
          st.pop();
        }else{
          return false;
        }
      }else{
        return false;
      }
    }
  }
return st.empty();
}
  


int main(){
  string s="aabcbc";
  if(isValid(s))
    cout<<"Valid String";
  else
    cout<<"Invalid String";

  return 0;
}