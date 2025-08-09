// Path Sum I.cpp
// Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node* left;
    Node* right;
    Node(int d){
        this->val = d;
        left = NULL;
        right = NULL;
    }
};
Node* CreateTree(Node* &root){
    int data;
    cout<<"Enter Your Value :";
    cin>>data;
    if(data == -1){
        return NULL;
    }
    Node* newNode = new Node(data);
    cout<<"Enter Left child of "<<newNode->val<<endl;
    newNode->left = CreateTree(newNode->left);
    cout<<"Enter Right Child of "<<newNode->val<<endl;
    newNode->right = CreateTree(newNode->right);
    return newNode;
}

bool solve(Node* root, int target, int currSum) {
        // Base Case
        if (root == NULL) {
            return false;
        }

        if (root->left == NULL && root->right == NULL) {

            currSum += root->val;

            if (currSum == target) {
                return true;
            }
        }

        // Other Node

        currSum += root->val;

     bool leftPart=   solve(root->left, target, currSum);
      bool rightPart=  solve(root->right, target, currSum);
        return (leftPart || rightPart);
    }

// Main function to check if there is a path sum
    bool hasPathSum(Node* root, int targetSum) {
        vector<int> path;
        int currSum = 0;
        return solve(root, targetSum, currSum);
    }

    int main(){
        Node* root = NULL;
        root = CreateTree(root);
        int targetSum;
        cout << "Enter the target sum: ";
        cin >> targetSum;
        if (hasPathSum(root, targetSum)) {
            cout << "There is a root-to-leaf path with the sum equal to " << targetSum << endl;
        }
        else {
            cout << "There is no root-to-leaf path with the sum equal to " << targetSum << endl;
        }
        return 0;
    }