// Slinding window maximum
#include<bits/stdc++.h>
using namespace std;
vector<int> slidingWindowMaximum(vector<int> &nums, int k){
  // requirement
  deque<int> dq;
  vector<int> ans;

  // first window max element
  for(int i=0;i<k;i++){
    while(!dq.empty() && nums[i]>=nums[dq.back()]){
      dq.pop_back();
    }

    dq.push_back(i);
  }
  ans.push_back(nums[dq.front()]);

  // Remaining Window
  for(int i=k;i<nums.size();i++){
    // out of window element remove
    if(!dq.empty() &&i-dq.front()>=k){
      dq.pop_front();
    }
    while(!dq.empty() && nums[i]>=nums[dq.back()]){
      dq.pop_back();
    }

    dq.push_back(i);
    ans.push_back(nums[dq.front()]);
    }
    
    return ans;
  }


int main(){
  vector<int> nums = {1,3,-1,-3,5,3,6,7};
  int k = 3;
  vector<int> ans = slidingWindowMaximum(nums,k);  
  for(auto it:ans){
    cout<<it<<" ";
  }

  return 0;
}