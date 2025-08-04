// First -ve integer in every window of size k

#include<bits/stdc++.h>
using namespace std;

void firstNegativeInteger(int arr[],int n,int k){

    deque<int> q;

    // first negative number in window 
    for (int i = 0; i < k;i++){
        if(arr[i]<0){
            q.push_back(i);
        }
    }

    // remaining window
    for (int i = k; i < n;i++){
        if(q.empty()){
            cout << 0 << " ";
        }else{
            cout << arr[q.front()] << " ";
        }

        while((!q.empty()) && (i-q.front()>=k)){
            q.pop_front();
        }

        if(arr[i]<0){
            q.push_back(i);
        }
    }
    if(q.empty()){
            cout << 0 << " ";
        }else{
            cout << arr[q.front()] << " ";
        }
}

int main(){

     int arr[] = {12, -1, -7, 8, -15, 30, 16, 28};
  int n = sizeof(arr)/sizeof(arr[0]);
  int k = 3;
  firstNegativeInteger(arr, n, k);

  return 0;
}