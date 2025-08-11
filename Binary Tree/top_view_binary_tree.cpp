// Top View In Binary Tree
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d){
            this->data = d;
            this->left = NULL;
            this->right = NULL;
        }
};
Node* CreateTree(Node* &root){
  int data;
  cout<<"Enter the data :";
  cin>>data;

  if(data == -1){
    return NULL;
  }
  root=new Node(data);

  cout<<"Enter the data for left : "<<root->data<<endl;
 root->left=CreateTree(root->left);
  cout<<"Enter the data for right : "<<root->data<<endl;
root->right = CreateTree(root->right);

  return root;
}
void TopView(Node* root){
    if(root==NULL)
        return;
    // requirement
    map<int, int> mp;
    queue<pair<Node *, int>> q;

    // Initialization
    q.push({root, 0});

    while(!q.empty()){
        pair<Node *, int> temp = q.front();
        q.pop();

        Node *NodeTree = temp.first;
        int hd = temp.second;

        if(mp.find(hd) == mp.end()){
            mp[hd] = NodeTree->data;
        }

        if(NodeTree->left){
            q.push({NodeTree->left, hd - 1});
        }

        if(NodeTree->right){
            q.push({NodeTree->right, hd + 1});
        }
    }
    for(auto it : mp){
        cout << it.second << " ";
    }
}
int main(){
    Node *root = NULL;
    CreateTree(root);
    cout << "Top View of the Binary Tree: ";
    TopView(root);
    cout << endl;
    return 0;
    
}