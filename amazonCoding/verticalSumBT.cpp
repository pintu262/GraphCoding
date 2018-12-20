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
void getVerticalSum(Node* root,map<int,int> &m,int p){
    if(!root){
        return;
    }
    if(m.find(p)!=m.end()){
        m[p] += root->data;
    }else{
        m[p]=root->data;
    }
    if(root->left){
        getVerticalSum(root->left,m,p-1);
    }
    if(root->right){
        getVerticalSum(root->right,m,p+1);
    }
}
void printVerticalSum(Node* root){
    map<int,int> m;
    getVerticalSum(root,m,0);
    for(auto it=m.begin();it!=m.end();it++){
        cout<<(*it).second<<" ";
    }
    cout<<endl;
}
void preorder(Node* root){
    if(root){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
int main() {
    int t;
    cin>>t;
    while(t--){
        Node* root = createBinaryTree();
        // preorder(root);
        printVerticalSum(root);
    }
    return 0;
}

/*
Input:
2
3
5 2 L 5 3 R 2 1 L
5
5 3 R 5 2 L 2 1 L 2 7 R 3 6 L
Output:
1 2 5 3 
1 2 18 3 
*/