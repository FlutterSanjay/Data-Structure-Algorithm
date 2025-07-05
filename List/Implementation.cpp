// Basic implementation of List
#include<iostream>
#include<list>
using namespace std;

void display(list<int> & lst){
    list<int>:: iterator it;
     cout<<"List Element :";
    for(it=lst.begin();it!=lst.end();it++){
        cout<<*it<<" ";
    }
}

int main(){
    int data,size;
    list<int> list1;
    cout<<"Enter the size of list : ";
    cin>>size;
    for(int i=0;i<5;i++){
        cout<<"Enter your element : ";
        cin>>data;
        list1.push_back(data);
    }
    display(list1);
    return 0;
}