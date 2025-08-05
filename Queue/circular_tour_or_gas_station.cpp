// Circular Tour & Gas Station Leetcode-[134]

#include<bits/stdc++.h>
using namespace std;

int gasStation( vector<int> &gas,vector<int>& cost){
  // requirement
  int deficit=0; // kitna petrol km hai
  int balance=0; // kitna petrol bacha hua hai

  int start=0; // kaha se deficit khatm huaaa hai

  for(int i=0;i<gas.size();i++){
    balance+=gas[i]-cost[i];
    if(balance<0){
      deficit+=balance;
      start=i+1;
      balance=0;
    }

   
  }
  if(balance + deficit >=0){
    return start;
  }else{
    return -1;
  }
  
}

int main(){
  vector<int> gas={1,2,3,4,5};
  vector<int> cost={3,4,5,1,2};
  cout<<gasStation(gas,cost)<<endl;


  return 0;
}