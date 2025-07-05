// Sort Stack element
#include<iostream>
#include<vector>
using namespace std;
class stack{
    public:
    int *arr;
    int size; //    Sort the stack
    int top;
    stack(int capacity){
        arr=new int[capacity];
        size=capacity-1;
        top=-1;
    }
    // for insertion
    void push(int data){
        if(top==size) cout<<"Stack is full...";
        else{
            top++;
            arr[top]=data;
        }
    }
    // for deletion
    int pop(){
        if(top==-1) cout<<"Stack is Empty...";
        else{
            int val=arr[top--];
            return val;
        }
    }
    
};
void sort(vector<int> &arr){
    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            if(arr[i]>arr[j]){
                swap(arr[i],arr[j]);
            }
        }
    }
}
int main(){
vector<int> arr;
int data;
 for(int i=0;i<5;i++){
     cout<<"Enter your no  :";
     cin>>data;
     arr.push_back(data);
 }
 sort(arr);
 stack st(5);
 for(int i=0;i<5;i++){
     st.push(arr[i]);
 }
 for(int i=0;i<5;i++){
     cout<<st.pop()<<" ";
 }
    return 0;
    
}