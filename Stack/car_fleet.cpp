//LeetCode [853]. Car Fleet

#include<bits/stdc++.h>
using namespace std;
int CarFleet(int target,vector<int> & pos,vector<int>& speed){
   vector<pair<int,int>> cars;

  for(int i=0;i<pos.size();i++){
    cars.push_back({pos[i],speed[i]});
  }

  vector<double> time(pos.size());
  // sort arroding to pisition 
 sort(cars.begin(), cars.end());  


  for(int i=0;i<cars.size();i++){
    time[i]=(double)(target-cars[i].first)/cars[i].second;
  }
  stack<double> st;

  for(int i=0;i<cars.size();i++){
    while(!st.empty() &&time[i] >= st.top() && i<cars.size()){
      st.pop();
    }
      st.push(time[i]);
        }
  int count=0;
  while(!st.empty()){
    count++;
    st.pop();
  };
  return count;
    }


int main(){
  int target=10;
  vector<int> pos={0,4,2};
  vector<int> speed={2,1,3};
  cout<<CarFleet(target,pos,speed);

  return 0;
}