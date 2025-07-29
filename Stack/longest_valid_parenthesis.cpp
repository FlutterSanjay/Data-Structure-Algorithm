// Longest Valid Parenthesis
#include<bits/stdc++.h>
using namespace std;
int longestValidParentheses(string s){
  if(s=="") return 0;
  stack<int> st;
  int maxm=0;
  st.push(-1);

  for(int i=0;i<s.length();i++){
    if(s[i]=='('){
      st.push(i);
    }else{
      st.pop();
      if(st.empty()){
        st.push(i);
      }else{
        int len=i-st.top();
        maxm=max(maxm,len);
        }
    }
  }
  return maxm;
}

int main(){
    string s = ")()())";
    cout << longestValidParentheses(s);

    return 0;
}