// Online Stock Span
#include<bits/stdc++.h>
using namespace std;
stack<pair<int,int>> st;
int OnlineStockSpan(int price){
  int span =1;

  while(!st.empty() && st.top().first <= price){
    span+=st.top().second;
    st.pop();
  }
  st.push({price,span});
  return span;
}

int main(){
  int price[] = {100,80,60,70,60,75,85};

  for(int i=0;i<7;i++){
    cout<<OnlineStockSpan(price[i])<<" ";
  }


  return 0;
}