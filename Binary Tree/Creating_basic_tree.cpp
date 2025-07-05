// creating the Binary Tree
#include<iostream>
#include<queue>
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
class tree{
    public:
    Node* root;
    tree(){
        root=NULL;
    }
};

Node* build_root(Node* root){
    cout<<"Enter the Data  : "<<endl;
    int data;
    cin>>data;
    root=new Node(data);
    if(data==-1){
        return NULL;
    }
    // left part
    cout<<"Enter the left part Data  :"<<endl;
    root->left=build_root(root->left);

    // right part
    cout<<"Enter the right part Data : "<<endl;
    root->right=build_root(root->right);
     return root;
}
Node* deletion(Node* root, int key)
{
    if (root == NULL)
        return NULL;
    if (root->left == NULL && root->right == NULL) {
        if (root->data == key)
            return NULL;
        else
            return root;
    }
    Node* key_node = NULL;
    Node* temp;
    Node* last;
    queue<Node*> q;
    q.push(root);
    
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        if (temp->data == key)
            key_node = temp;
        if (temp->left) {
            last = temp; // storing the parent node
            q.push(temp->left);
        }
        if (temp->right) {
            last = temp; // storing the parent node
            q.push(temp->right);
        }
    }
    if (key_node != NULL) {
        key_node->data
            = temp->data; // replacing key_node's data to
                          // deepest node's data
        if (last->right == temp)
            last->right = NULL;
        else
            last->left = NULL;
        delete (temp);
    }
    return root;
}
void inorder(Node* root){
    if(root==NULL){
        return ;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}
void preorder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main(){
    tree t;
    int key=2;
  t.root=build_root(t.root);
  cout<<"******Before Deletion Element*******\n";
   inorder(t.root);
   cout<<endl;
   preorder(t.root);
   cout<<endl;
   postorder(t.root);
  Node* temp=deletion(t.root,key);
   cout<<"\n******After Deletion Element*******\n";
   inorder(temp);
   cout<<endl;
   preorder(temp);
   cout<<endl;
   postorder(temp);

    return 0;
}