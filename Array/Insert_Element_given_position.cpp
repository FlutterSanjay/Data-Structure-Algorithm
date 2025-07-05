// insert the Element in given position
#include<iostream>
using namespace std;
void insert(int arr[],int size,int value,int pos){
    for(int i=size;i>=pos;i--){
        arr[i]=arr[i-1];
    }
    arr[pos-1]=value;
}

int main(){
    int size,pos,value;
    cout<<"Enter the position to add Element in array :";
    cin>>pos;
    cout<<"Enter the value to add the Element in array :";
    cin>>value;
    cout<<"Enter your Array Size :";
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++){
        cout<<"Enter your no :";
        cin>>arr[i];
    }
    size++;
    insert(arr,size,value,pos);
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}