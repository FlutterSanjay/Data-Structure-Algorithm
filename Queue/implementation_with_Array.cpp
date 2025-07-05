// implementation of Queue using array

// optimal way of representation       //*** TIME COMPLEXITY = O(n)
#include<iostream>
using namespace std;
int n;
class queue{
    int *arr;
    int front;
    int back;
    
    public:
    queue(){
        
        cout<<"Enter the size of Array : ";
        cin>>n;
        arr=new int[n];
        
        front=back=0;
    }
    // inserting Element
    void insert(int x){
        if(back==n){
            cout<<"Queue is Full...";
            return ;
        }
        
        arr[back]=x;
        back++;
       
    }
    void remove(){
        if(front==back){
            cout<<"Queue is Empty !";
            return ;
        }
        int ans=arr[front];
        front++;
        if(front==n){
            front=back=-1;
        }
    }
    
    int peek(){
        if(front==back){
            cout<<"Queue is Empty !";
            return -1;
        }
        return arr[front];
    }
    bool empty(){
        if(front==back){
            cout<<"NO Element in Queue"<<endl;
            return true;
        }
        return false;
    }
};

int main(){
    queue q;
int num,data,del;
cout<<"Number of Element want to insert : ";
cin>>num;
for(int i=0;i<num;i++){
    cout<<"Enter your Element :";
    cin>>data;
    q.insert(data);
}

cout<<"How many Element you want to delete : ";
cin>>del;
for(int i=0;i<del;i++){
    q.remove();
}
cout<<q.peek()<<endl;
bool result=q.empty();
if(result) cout<<"Queue is Empty!";
else cout<<"Queue is Not Empty!";
return 0;
}