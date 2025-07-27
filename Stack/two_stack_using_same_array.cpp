// Two Stack Implementation Using Same Array
#include<bits/stdc++.h>
using namespace std;


class Stack{
    public:
        int top1;
        int top2;
        int size;
        int *arr;
        Stack(int size){
            this->size = size;
            this->arr = new int[size];
            this->top1 = -1;
            this->top2 = size;
        }

        // Stack Operation

        // Push Operation
        void push1(int data){
            // full or not
            if(top2-top1==1){
                cout << "Stack is Full"<<endl;
            }else{
                top1++;
                arr[top1] = data;
            }
        }

        void push2(int data){
            //full or not
            if(top2-top1==1){
                cout << "Stack is Full"<<endl;
            }else{
                top2--;
                arr[top2] = data;
            }
        }

        //Pop Operation
        void pop1(){
            //Empty or Not
            if(top1==-1){
                cout << "Underflow";
            }else{
                top1--;
            }
        }

        void pop2(){
            // Empty or Not
            if(top2==size){
                cout << "Underflow";
            }else{
                top2++;
            }
        }

        // Top Element
        int getTop1(){
            //Empty
            if(top1==-1){
                return -1;
            }
            return arr[top1];
        }

        int getTop2(){
            if(top2==size){
                return -1;
            }
            return arr[top2];
        }
};
int main(){
    Stack s(10);
    s.push1(10);
    s.push1(20);
    s.push1(30);
    s.push1(40);
    

    s.push2(100);
    s.push2(200);
    s.push2(300);
    s.push2(400);
    s.push2(500);
    s.push2(600);
     

    s.pop1();
    s.pop2();
    cout << s.getTop1() << endl;
    cout<<s.getTop2();
   

    return 0;
}