// Simplify Path
#include<bits/stdc++.h>
using namespace std;

// reverse the stack and build the path
void build(stack<string> st,string &ans){
  if(st.empty()) return;
  string top=st.top();
  st.pop();
  build(st,ans);
  ans+=top;
}
string simplifyPath(string path){
  if(path=="") return "";
  stack<string> st;
  int i=0;
  while(i<path.size()){
    int start=i;
    int end=i+1;
    while(end<path.size() && path[end]!='/'){
      end++;
    }
    string minPath=path.substr(start,end-start);
    i=end;
    if(minPath=="/." || minPath == "/") continue;

    if(minPath != "/.."){
      st.push(minPath);
    }else if(!st.empty()){
      st.pop();
    }

  }
  
    string ans=st.empty()?"/":"";
    build(st,ans);
    return ans;
}
int main(){
  string path="/home/user/Documents/../Pictures";
  cout<<simplifyPath(path)<<endl;
 return 0;
}