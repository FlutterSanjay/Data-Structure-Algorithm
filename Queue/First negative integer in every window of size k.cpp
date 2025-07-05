// C++ code for First negative integer
// in every window of size k

#include<iostream>
#include<queue>
using namespace std;

queue<int> negative(int arr[],int n,int k){
    queue<int> dq;
    int fnegativeIndex=0;
    int fnegativeElement;

for(int i=k-1;i<n;i++){
    while((fnegativeIndex<i)&&(fnegativeIndex<=i-k || arr[fnegativeIndex]>=0)){
        fnegativeIndex++;
    }
    // check if a number is a negative element is found
    if(arr[fnegativeIndex]<0){
        fnegativeElement=arr[fnegativeIndex];
    }
    else{
        fnegativeElement=0;
    }
    dq.push(fnegativeElement);
}
return dq;
}

int main(){
    queue<int> q;
    int size,k;
    cout<<"Enter the size of array : ";
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++){
        cout<<"Enter your no : ";
        cin>>arr[i];
    }
    cout<<"Total negative number Enter : ";
    cin>>k;
q=negative(arr,size,k);
while(!q.empty()){
    cout<<q.front()<<" ";
    q.pop();
}
return 0;
}