// 85. Maximal Rectangle [LeetCode]

#include<bits/stdc++.h>
using namespace std;

vector<int> preSmallElement(vector<int>& v) {
  stack<int> st;
  st.push(-1);
  vector<int> ans;

  for (int i = 0; i < v.size(); i++) {
      int curr = v[i];

      while (st.top() != -1 && curr <= v[st.top()]) {
          st.pop();
      }

      ans.push_back(st.top());
      st.push(i);
  }
  return ans;
}

vector<int> nextSmallerElement(vector<int>& arr) {
  stack<int> st;
  vector<int> ans(arr.size());
  st.push(-1);

  for (int i = arr.size() - 1; i >= 0; i--) {
      int curr = arr[i];

      while (st.top() != -1 && curr <= arr[st.top()]) {
          st.pop();
      }
      ans[i] = st.top();
      st.push(i);
  }

  return ans;
}
int largestRectangleArea(vector<int>& heights) {
  vector<int> next = nextSmallerElement(heights);
  vector<int> prev = preSmallElement(heights);
  int maxArea = INT_MIN;

  for (int i = 0; i < heights.size(); i++) {
      int length = heights[i];
      if (next[i] == -1) {
          next[i] = heights.size();
      }
      int width = next[i] - prev[i] - 1;
      maxArea = max(maxArea, length * width);
  }
  return maxArea;
}
int maximalRectangle(vector<vector<char>>& matrix) {
  vector<vector<int>> v;
  int n = matrix.size();   // row
  int m = matrix[0].size(); // col

          for (int i = 0; i < n; i++) {
      vector<int> t;
      for (int j = 0; j < m; j++) {
          t.push_back(matrix[i][j] - '0'); // convert into number
      }
      v.push_back(t);
  }

  int area =largestRectangleArea(v[0]);

  for(int i=1;i<n;i++){
      for(int j=0;j<m;j++){
          if(v[i][j]){
              v[i][j]+=v[i-1][j];
          }else{
              v[i][j]=0;
          }
      }
      area=max(area,largestRectangleArea(v[i]));
  }
  return area;
}

int main(){

  vector<vector<char>> matrix = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
  cout<<"Largest Rectangle:"<<maximalRectangle(matrix);
  

  return 0;
}