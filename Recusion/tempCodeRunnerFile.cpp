// find the key using Recursion
#include<iostream>
using namespace std;
bool search(int *arr,int size,int key){
    if(size==0) return false;
    if(arr[0]==key) return true;
    else{
        int remain_search=search(arr+1,size-1,key);
        return remain_search;
    }
}

int main(){
    int size,key;
    cout<<"Enter the size of Array : ";
    cin>>size;
    int *arr=new int[size];
    for(int i=0;i<size;i++){
      cout<<"Enter your no : ";
      cin>>arr[i];
    }
    cout<<"Enter your key :";
    cin>>key;
    bool result=search(arr,size,key);
    if(result==true) cout<<"Data Found !";
    else cout<<"Data Not Found !";

    return 0;
}