// Valid Parenthesis
#include<bits/stdc++.h>
using namespace std;

bool validParenthesis(string s){

    stack<char> st;

    for (int i = 0; i < s.length();i++){
        char ch = s[i];
        if(ch=='(' || ch=='{' || ch =='['){
            st.push(ch);
        }else{
            if(!st.empty()){
                char top = st.top();
                if(ch==')' &&top=='('  || ch=='}' && top=='{' || ch ==']' && top=='['){
                    st.pop();
                }else{
                    return false;
                }
            }else{
                return true;
            }
        }
    }
    if(st.empty()){
        return true;
    }else{
        return false;
    }
}

int main(){
    string s = "{{[()]}}";
     if(validParenthesis(s))
    cout<<"Valid String";
  else
    cout<<"Invalid String";
  cout<<endl;
  return 0;
}