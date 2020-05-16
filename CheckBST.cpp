#include<bits\stdc++.h>

using namespace std;

struct Node{

    Node* left,*right;
    int data;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
        
    }
};

// Node* insert(Node* root,int x){

//     if(root==NULL){
//         root = new Node(x);
//         return root;
//     }

//     if(x>root->data)root->right=insert(root->right,x);
//     else if(x< root->data)root->left = insert(root->left,x);

//     return root;
// }

bool check(Node* node,int min,int max){

    if(node==NULL)return true;

    if(node->data<min || node->data>max)return false;

    return (check(node->left,min,node->data-1) && check(node->right,node->data+1,max));
    
}

bool isBST(Node* node){
    return check(node,INT_MIN,INT_MAX);
}

void Inorder(Node* root){

    if(root==NULL)return;

    Inorder(root->left);
    cout << root->data;
    Inorder(root->right);
}

int main(){

    Node* root = new Node(3);

    root->left = new Node(1);
    root->right = new Node(6);
    root->left->right = new Node(2);
    
    Inorder(root);
    cout << isBST(root);
}

