//insert and delete the element in same array
#include<iostream>
using namespace std;
void insert(int *arr,int size,int data,int pos){
for(int i=size;i>=pos;i--){
    arr[i]=arr[i-1];
}
arr[pos-1]=data;
}
void del(int *arr,int size,int pos){
for(int i=pos-1;i<size;i++){
    arr[i]=arr[i+1];
}
}
void display(int *arr,int size){
for(int i=0;i<size;i++){
    cout<<arr[i]<<" ";
}
}
int main(){
int size,pos,data,ch;
cout<<"Enter the size of array : ";
cin>>size;
int *arr=new int[size];
for(int i=0;i<size;i++){
    cout<<"Enter your no : ";
    cin>>arr[i];
}
cout<<"1-Add New Element \n 2-Delete Element \n Enter your Choice :";
cin>>ch;
switch(ch){
 case 1:
        cout<<"Enter your new Element to add :";
        cin>>data;
        cout<<"Enter the position to add new Element :";
        cin>>pos;
        insert(arr,size,data,pos);
        size++;
        display(arr,size);
        break;
 case 2:
        cout<<"Enter your position to delete Element : ";
        cin>>pos;
        del(arr,size,pos);
        size--;
        display(arr,size);
        break;
}
return 0;
}
