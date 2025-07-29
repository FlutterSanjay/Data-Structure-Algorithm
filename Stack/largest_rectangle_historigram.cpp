// Largest Rectangle Histogram
#include<bits/stdc++.h>
using namespace std;
vector<int> preSmallElement(vector<int>& v){
   stack<int> st;
      st.push(-1);
      vector<int> ans;

      for (int i = 0; i <v.size();i++){
          int curr = v[i];


          while(st.top() !=-1 && curr <= v[st.top()]){
              st.pop();
          }

          ans.push_back(st.top());
          st.push(i);
      }
      return ans;
  }

vector<int> nextSmallerElement(vector<int> &arr){
  stack<int> st;
  vector<int> ans(arr.size());
  st.push(-1);

  for(int i=arr.size()-1;i>=0;i--){
    int curr=arr[i];
    
      while(st.top() !=-1 && curr <= arr[st.top()]){
        st.pop();
      }
      ans[i] = st.top();  
      st.push(i);
    }
  
  return ans;
}

  int largestRectangleArea(vector<int>& heights){
    vector<int> next=nextSmallerElement(heights);
    vector<int> prev=preSmallElement(heights);
    int maxArea=INT_MIN;

    for(int i=0;i<heights.size();i++){
      int length=heights[i];
      if(next[i]==-1){
        next[i]=heights.size();
      }
      int width =next[i]-prev[i]-1;
      maxArea=max(maxArea,length*width);
    }
    return maxArea;
  }

int main(){
  vector<int> v={2,1,5,6,2,3};

  cout<<largestRectangleArea(v)<<endl;

  return 0;
}