// push the element in stack
#include<iostream>
using namespace std;
class stack{
    int capacity;
    int* arr;
    int top;
    public:
    stack(int data){
        this->capacity=data;
        this->arr=new int[data];
        this->top=-1;
    }
    void push(int data){
        if(top==capacity-1){
            cout<<"OverFlow !"<<endl;
        }
        top++;
        arr[top]=data;

    }
    void display(){
        for(int i=0;i<capacity;i++){
            cout<<arr[i]<<" ";
        }
    }
};
int main(){
    int data,size;
    cout<<"Enter the Size of Stack : ";
    cin>>size;
    stack aa(size);
    for(int i=0;i<size;i++){
        cout<<"Enter your Element : ";
        cin>>data;
        aa.push(data);
    }
    aa.display();
        cout<<"Enter your Element : ";
        cin>>data;
    aa.push(data);
    return 0;
}