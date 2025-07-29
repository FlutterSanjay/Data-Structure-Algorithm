// Next Smallest Element
#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr){
  stack<int> st;
  vector<int> ans(arr.size());
  st.push(-1);

  for(int i=arr.size()-1;i>=0;i--){
    int curr=arr[i];
    
      while(curr<=st.top()){
        st.pop();
      }
      ans[i]=st.top();
      st.push(curr);
    }
  
  return ans;
}


int main(){
vector<int> v={2,1,4,3};
  vector<int> result = nextSmallerElement(v);  
  for(auto it:result){
      cout<<it<<" ";
  }
 
  

  return 0;
}