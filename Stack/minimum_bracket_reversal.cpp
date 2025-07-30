// Minimum Bracket Reversal
#include<bits/stdc++.h>
using namespace std;

int minBracketTraversal(string &s){
    if(s==""){
        return -1;
    }

    if(s.length() % 2 !=0){
        return -1;
    }
    int count = 0;
    stack<char> st;
    for (int i = 0; i < s.length();i++){

        char ch = s[i];

        if(ch=='{'){
            st.push(ch);
        }else if(!st.empty() && st.top() == '{'){
            st.pop();
        }else{
            st.push(ch);
        }
    }

    // Handle opp and same direction bracket
    while(!st.empty()){
        char a = st.top();
        st.pop();
        char b = st.top();
        st.pop();

        if(a== b){
            count += 1;
        }else{
            count += 2;
        }
    }
    return count;
}



int main(){
    string s = "{{{{}}";
    cout << minBracketTraversal(s) << endl;
  

    return 0;
}