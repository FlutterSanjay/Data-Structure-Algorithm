// implementaion of Queue
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int val){
        data=val;
    }
};
class queue{
    public:
    Node* head;
    Node* tail;
    int front=-1;
    int rear=-1;
    int size;
    queue(int capacity){
        size=capacity-1;
        head=NULL;
        tail=NULL;
        front=-1;
        rear=-1;
    }

    // Enqueue Method
    void enqueue(int data){
        if(rear==size){
            cout<<"Queue is Full...";
        }
        else if(front==-1 && rear==-1){
            front++;
            rear++;
            Node* temp=new Node(data);
            if(head==NULL){
                head=temp;
                tail=temp;
                return;
            }
        }
        else{
            rear++;
            Node* temp=new Node(data);
            tail->next=temp;
            temp->prev=tail;
            tail=temp;
        }
    }

    // Dequeue Method
    int dequeue(){
        if(front==rear){
        cout<<"Queue is Empty...";
        return 0;
        }
        else{
            front++;
            Node* dell=head;
            head=head->next;
            head->prev=NULL;
            int val =dell->data;
            return val;
        }
    }

    // Full Check Method
     void isFull(){
         if(rear==size){
            cout<<"Queue is Full...";
        }else{
            cout<<"Queue is not Full...";
        }
     }

     // Empty Check Method

     void isEmpty(){
         if(front==rear){
            cout<<"Queue is Empty...";
        } else{
            cout<<"Queue is not Empty...";
        }
     }
};
int main(){
    queue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    cout<<"Dequeue Method : "<<q.dequeue()<<endl;
    cout << "Empty Method:";
    q.isEmpty();
    cout << "\nFull Method:";
    q.isFull();

    return 0;
}