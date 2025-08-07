// Sum of max and min of sliding window 
#include<bits/stdc++.h>
using namespace std;

int sumMIn(vector<int> &minAns,vector<int> &ans){
int sum=0;
  for(int i=0;i<ans.size();i++){
    sum+=ans[i]+minAns[i];
  }
  return sum;
}
int slidingWindowMax(vector<int> &nums,int k){

  // Requirement
  deque<int> q1;
  deque<int> q2;
  vector<int> ans;
  vector<int> minAns;

  
  // first window
  for(int i=0;i<k;i++){
    while(!q1.empty() && nums[i]>=nums[q1.back()]){
     q1.pop_back();
    }

    while(!q2.empty() && nums[i]<=nums[q2.back()]){
      q2.pop_back();
    }
    q2.push_back(i);
    q1.push_back(i);
  }
  minAns.push_back(nums[q2.front()]);
  ans.push_back(nums[q1.front()]);

  // Remaining Windowko process
  for(int i=k;i<nums.size();i++){
    // out of window element remove
    if(!q1.empty() && i-q1.front()>=k){
      q1.pop_front();
    }

    if(!q2.empty() && i-q2.front()>=k){
      q2.pop_front();
    }

     // slide the window
    while(!q1.empty() && nums[i]>=nums[q1.back()]){
       q1.pop_back();
      }

     while(!q2.empty() && nums[i]<=nums[q2.back()]){
       q2.pop_back();
     }
      q1.push_back(i);
    q2.push_back(i);
    minAns.push_back(nums[q2.front()]);
    ans.push_back(nums[q1.front()]);
    }
  return sumMIn(minAns,ans);
   
  
  

}

int main(){
  vector<int> nums={2,5,-1,7,-3,-1,-2};
  int k=4;
int ans=slidingWindowMax(nums,k);
 cout<<"The sum of max and min of sliding window is : "<<ans<<endl;

  return 0;
}