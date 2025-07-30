// Celebrity Problem
#include<bits/stdc++.h>
using namespace std;

int celebrityProblem(vector<vector<int>> &M, int n){
  stack<int>st;

  //Step 1: Push all the elements in the stack
  for(int i=0;i<n;i++){
    st.push(i);
  }

  // Step 2: Get 2 elements and compare them

  while(st.size() !=1){
    int a = st.top();
    st.pop();
      int b = st.top();
    st.pop();

    // a know b
    if(M[a][b]){
      //a can't be celebrity
      st.push(b);
    }
    else{
      // b can't be celebrity
      st.push(a);
    }
  }

  // Step 3: Remaing Stack candidate is  celebrity or not
  int celebrity = st.top();
  st.pop();

  // condition 1: All the rows should have 0
  for(int i=0;i<n;i++){
    if(i != celebrity && M[celebrity][i] !=0){
      return -1;
    }
  
  }

  // condition 2: All the col should have 1
  for(int i=0;i<n;i++){
    if(i != celebrity && M[i][celebrity] !=1){
      return -1;
    }
  }
  return celebrity;
}

int main(){

  vector<vector<int>>M = {{0,1,0},{0,0,0},{0,1,0}};
  int n = 3;
  int ans = celebrityProblem(M,n);
  cout<<"Celebrity is "<<ans<<endl;


  return 0;
}