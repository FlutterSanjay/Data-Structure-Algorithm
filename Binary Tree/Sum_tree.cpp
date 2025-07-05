/* Given a Binary Tree. Return true if, 
for every node X in the tree other than the leaves,
 its value is equal to the sum of its left subtree's value and 
 its right subtree's value. Else return false.
An empty tree is also a Sum Tree as the sum of an empty tree can be considered to be 0.
 A leaf node is also considered a Sum Tree.

 */
#include<iostream>
#include<utility>
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
    // letf Part
    cout<<"Enter the data for left part of "<<data<<":"<<endl;
    root->left=build_tree(root->left);
    
    //right Part
    cout<<"Enter the data for right part of "<<data<<":"<<endl;
    root->right=build_tree(root->right);
    
    return root;
}

pair<bool,int> isSum(Node* root){
    if(root==NULL){
        pair<bool,int> p =make_pair(true,0);
        return p;
    }
    if(root->left ==NULL && root->right==NULL){
        pair<bool,int> p=make_pair(true,root->data);
        return p;
    }
        pair<bool,int> left_ans=isSum(root->left);
        pair<bool,int> right_ans=isSum(root->right);
        
        bool left=left_ans.first;
        bool right=right_ans.first;
        
        bool cond=root->data==left_ans.second + right_ans.second;
        
        pair<bool,int> ans;
        if(left && right && cond){
            ans.first=true;
            ans.second=2*root->data;
        }
        else{
            ans.first=false;
        }
        return ans;
    }
    bool isSumFast(Node* root){
        return isSum(root).first;
    }
    
    int main(){
        Node* root=NULL;
        root=build_tree(root);
        
        bool result=isSumFast(root);
        if(result) cout<<"The Sum of Tree Branches is Equal to the Root Data..."<<endl;
        else cout<<"The Sum of Tree Branches is Not Equal to the Root Data..."<<endl;
        return 0;
    }
        
    