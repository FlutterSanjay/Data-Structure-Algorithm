// Redundant Bracket
#include<bits/stdc++.h>
using namespace std;

bool redundantBracket(string &s){
    if(s==""){
        return false;
    }
    stack<char> st;
    bool op = false;
    for (int i = 0; i < s.length();i++){
        char ch = s[i];

        if(ch=='(' || ch =='+' || ch =='-' || ch == '*' || ch=='/'){
            st.push(ch);
        }else if (ch == ')'){
            op = false;

            while(!st.empty() && st.top() != ')'){
                if(st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/'){
                    op = true;
                }
                st.pop();
            }
            if(!st.empty()){
                st.pop();
            }
        }
    }
    if(op){
        return true;
    }else{
        return false;
    }
}

int main(){
  string s = "(a+b))";
  cout<<redundantBracket(s)<<endl;

    return 0;
}