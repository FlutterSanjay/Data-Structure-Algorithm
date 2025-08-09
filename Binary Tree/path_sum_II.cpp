// Path Sum II 
// Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
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

void solveUtil(Node* root, int target, int currSum, vector<int>& path, vector<vector<int>>& ans) {
    // Base Case
    if(root ==NULL){
        return;
    }
    // for Leaf Node
    if(root->left == NULL && root->right == NULL){
        path.push_back(root->val);
        currSum += root->val;

        if(currSum == target){
            ans.push_back(path);
        }

        path.pop_back();
        currSum -= root->val;
        return;

    }

    // for Other Node
    path.push_back(root->val);
    currSum += root->val;
    solveUtil(root->left, target, currSum, path, ans);
    solveUtil(root->right, target, currSum, path, ans);

    // Backtracking
    path.pop_back();
    currSum -= root->val;
}
vector<vector<int>> solve(Node* root, int target) {

    // Requirement
    vector<vector<int>> ans;
    vector<int> path;
    int currSum = 0;
    solveUtil(root, target, currSum, path, ans);
    return ans;
}

int main(){
    Node* root = NULL;
    root = CreateTree(root);
    int targetSum;
    cout << "Enter the target sum: ";
    cin >> targetSum;
    vector<vector<int>> result = solve(root, targetSum);
    cout << "Paths with sum " << targetSum << " are:" << endl;
    for (const auto& path : result) {
        for (int val : path) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}