#include <bits/stdc++.h>
using namespace std;
struct Node{
  int data;
  Node* left;
  Node* right;
};
Node* getNode(int d){
    Node* n=(Node*)malloc(sizeof(Node));
    n->data=d;
    n->left=NULL;
    n->right=NULL;
    return n;
}
Node* findNode(Node* root,int d){
    if(root){
        if(root->data == d){
            return root;
        }
        Node * l =findNode(root->left,d);
        if(l!=NULL){
            return l;
        }else{
            return findNode(root->right,d);
        }
    }
    return NULL;
}
Node* createBinaryTree(){
    int rootNode,childNode;
    char branch;
    int n;
    cin>>n;
    Node * root=NULL;
    Node * temp = NULL;
    for(int i=0;i<n;i++){
        cin>>rootNode>>childNode;
        cin>>branch;
        if(root==NULL){
            root = getNode(rootNode);
            if(branch=='L'){
                root->left = getNode(childNode);
            }else{
                root->right = getNode(childNode);
            }
        }else{
            temp = findNode(root,rootNode);
            if(branch=='L'){
                temp->left = getNode(childNode);
            }else{
                temp->right = getNode(childNode);
            }
        }
    }
    return root;
}
void preorder(Node* root){
    if(root){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
Node* convertToBinaryTree(Node* root){
    if(!root)return NULL;
    queue<Node*> q;
    q.push(root);
    Node * ret = root;
    Node* cur=NULL;
    Node* prev=NULL;
    while(!q.empty()){
        prev = cur;
        cur = q.front();q.pop();
        if(cur->left){
            q.push(cur->left);
        }
        if(cur->right){
            q.push(cur->right);
        }
        cur->right = q.front();
        cur->left = prev;
    }
    return ret;
}
int main() {
    Node* root = createBinaryTree();
    
    preorder(root);
    cout<<endl;
    Node* head= convertToBinaryTree(root);
    Node *itr =head;
    while(itr!=NULL){
        cout<<itr->data<<" ";
        itr=itr->right;
    }
    cout<<endl;
}
/*
Input:
4
10 20 L 10 30 R 20 40 L 20 60 R
Output:
10 20 40 60 30 
10 20 30 40 60
*/
