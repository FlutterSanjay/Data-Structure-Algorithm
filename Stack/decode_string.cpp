// Decode String
/*
Example 1:

Input: s = "3[a]2[bc]"
Output: "aaabcbc"

*/
#include<bits/stdc++.h>
using namespace std;

string decodeString(string s){
  if(s=="") return "";
  stack<string>st;

  for(char ch:s){
    string temp(1,ch);

    if(ch==']'){
      string str="";
      while(!st.empty() && st.top()!="["){
        str+=st.top();
        st.pop();
      }

      if(!st.empty() && st.top() =="[") st.pop();

      string numStr="";
      while(!st.empty() && isdigit(st.top()[0])){
        numStr+=st.top();
        st.pop();
      }
       reverse(numStr.begin(),numStr.end());
      int n=stoi(numStr);

      string expandedStr="";

      while(n--){
        expandedStr+=str;
      }

      st.push(expandedStr);
    }else{
      st.push(temp);
    }
  }
  // final decode
  string decodedStr="";
  while(!st.empty()){
    decodedStr+=st.top();
    st.pop();
  }
  reverse(decodedStr.begin(),decodedStr.end());
  return decodedStr;
 
}

int main(){
  string s="3[a]2[bc]";
  cout<<decodeString(s);


  return 0;
}