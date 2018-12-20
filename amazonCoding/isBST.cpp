#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
};
Node* getNode(int d){
    Node* n = new Node;
    n->data = d;
    n->left= NULL;
    n->right=NULL;
    return n;
}
Node* findNode(Node* root,int d){
    if(root){
        if(root->data == d){
            return root;
        }
        if(root->left){
            Node* foundLeft = findNode(root->left,d);
            if(foundLeft!=NULL){
                return foundLeft;
            }
        }
        if(root->right){
            Node* foundRight = findNode(root->right,d);
            return foundRight;
        }
    }
    return NULL;
}
Node* createBinaryTree(){
    int n;// Number of inputs
    Node* root=NULL;Node *temp=NULL;
    int x,y;
    char child;
    cin>>n;
    cin>>x>>y;
    cin>>child;
    root = getNode(x);
    if(child =='L'){
        root->left = getNode(y);
    }else{
        root->right = getNode(y);
    }
    for(int i=1;i<n;i++){
        cin>>x>>y;
        cin>>child;
        temp = findNode(root,x);
        if(child=='L'){
            temp->left = getNode(y);
        }else{
            temp->right = getNode(y);
        }
    }
    return root;
}

bool isBst(Node* root){
    if(root){
        bool ltrue = isBst(root->left);
        bool rtrue = isBst(root->right);
        if(ltrue && rtrue){
            if(root->left && root->right){
                return (root->data > root->left->data  && root->data< root->right->data);
            }
            if(root->left){
                return (root->data > root->left->data );
            }
            if(root->right){
                return (root->data< root->right->data);
            }
            return true;
        }
        return false;
    }
    return true;
}
int main() {
    int t;
    cin>>t;
    while(t--){
        Node* root = createBinaryTree();
        if(isBst(root)){
            cout<<"BST"<<endl;
        }else{
            cout<<"Not BST"<<endl;
        }
    }
    return 0;
}
/*
Input:
3
4
20 10 L 10 5 L 5 2 L 2 3 R
3
5 2 L 5 3 R 2 1 L
5
5 3 R 5 2 L 2 1 L 2 7 R 3 6 L
Output:
BST
Not BST
Not BST
*/