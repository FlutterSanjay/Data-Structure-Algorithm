// Previous Smallest Element
#include<bits/stdc++.h>
using namespace std;
vector<int> preSmallElement(vector<int>& v){
    stack<int> st;
    st.push(-1);
    vector<int> ans;

    for (int i = 0; i <v.size();i++){
        int curr = v[i];
        

        while(curr < st.top()){
            st.pop();
        }

        ans.push_back(st.top());
        st.push(curr);
    }
    return ans;
}

int main(){
    vector<int> v = {2, 1, 4, 3};
    vector<int> result = preSmallElement(v);
    for(auto it:result){
        cout << it << " ";

    }
    

    return 0;
}