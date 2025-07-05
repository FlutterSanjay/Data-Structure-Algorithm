// return the Number which is equal to the target number
#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node* prev;

    Node(int data){
        val=data;
        next=NULL;
        prev=NULL;
    }
};

class doubly{
    public:
    Node* head;
    Node* tail;
    doubly(){
        head=NULL;
        tail=NULL;
    }
    void insert(int data){
        Node* end=new Node(data);
        while(tail==NULL){
            head=end;
            tail=end;
            return ;

        }
        tail->next=end;
        end->prev=tail;
        tail=end;
        return;

    }
};
vector<int> neighbour(Node* &head,Node* &tail,int target){
    vector<int> arr(2,-1);
    while(head!=tail){
        int sum=head->val+tail->val;
        if(sum==target){
            arr[0]=head->val;
            arr[1]=tail->val;
            return arr;
        }
        else if(sum>target){
            tail=tail->prev;
        }
        else{
            head=head->next;
        }
    }
    return arr;
}

void display(Node* head){
    while(head!=NULL){
        cout<<head->val<<" ";
        head=head->next;
    }
}
int main(){
    doubly aa;
    int data;
    int target;
    for(int i=0;i<7;i++){
        cout<<"Enter your no : ";
        cin>>data;
        aa.insert(data);
    }
    display(aa.head);
    cout<<endl;
    cout<<"Enter your no to find : ";
    cin>>target;
    vector<int> ans=neighbour(aa.head,aa.tail,target);
    cout<<ans[0]<<" "<<ans[1];
    return 0;

}