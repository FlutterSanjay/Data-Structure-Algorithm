// check the All Node are Balance or not
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
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
    cout<<"Enter your right part data of "<<data<<":"<<endl;
    root->right=build_tree(root->right);
    return root;
}
int height(Node* root){
    if(root==NULL){
        return 0;
    }
    int left=height(root->left);
    int right=height(root->right);
    int ans=max(left,right)+1;

    return ans;
}

bool isBalance(Node* root){
    if(root==NULL){
        return true;
    }
    bool left=isBalance(root->left);
    bool right=isBalance(root->right);
    bool diff=abs (height(root->left)-height(root->right)) <=1;

    if(diff && left && right){
        return true;
    }
    else return false;
}

int main(){
    Node* root=NULL;
    root=build_tree(root);
    bool result=isBalance(root);
    if(result){
        cout<<"Node is Balance...";
    }
    else{
        cout<<"Node is Un-Balance...";
    }
    return 0;
}