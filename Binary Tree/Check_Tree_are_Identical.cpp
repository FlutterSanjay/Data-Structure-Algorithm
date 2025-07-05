// Two Tree are Idenatical or Not
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data==val;
        left==NULL;
        right==NULL;
    }
};

Node* build_tree(Node* root){
    cout<<"Enter your no : ";
    int data;
    cin>>data;
    root=new Node(data);
    
    if(data==-1){
        return NULL;
    }
    
    // left part
    cout<<"Enter your left part data of "<<data<<":"<<endl;
    root->left=build_tree(root->left);
    
    // right part
    cout<<"Enter your Right part data of "<<data<<":"<<endl;
    root->right=build_tree(root->right);
    return root;
}

// identical
bool identical(Node* root1,Node* root2){
    if(root1== NULL && root2==NULL){
        return  true;
    }
    if(root1==NULL && root2 != NULL){
        return false;
    }
    if(root1!= NULL && root2==NULL){
        return false;
    }
    
    bool left=identical(root1->left,root2->left);
    bool right=identical(root1->right,root2->right);
    
    bool value=root1->data== root2->data;
    if(left && right && value){
        return true;
    }
    else return false;
}

int main(){
    Node* root1=NULL;
    Node* root2=NULL;
    root1=build_tree(root1);
    root2=build_tree(root2);
    bool result=identical(root1,root2);
    if(result){
        cout<<"Tree are Identical....";
    }
    else{
        cout<<"Tree are Not Identical...";
    }
    return 0;
}