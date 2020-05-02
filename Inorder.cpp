#include<bits/stdc++.h>

using namespace std;

struct Node{

	int data;
	Node* left;
	Node* right;

	Node(int x){
		data = x;
		left =NULL;
		right = NULL;
	}
};

vector<Node*> io;
std::vector<Node*> pre;

Node* tree(int n){

	Node* arr[n+1];

	for(int i=0;i<n+1;i++){
		arr[i] = new Node(INT_MAX);
	}

	int a,b;
	char c;

	for(int i=1;i<n;i++){

		cin >> a >> b >> c;
		if(c=='L'){
			arr[a]->left = arr[b];
		}else if(c=='R'){
			arr[a]->right = arr[b];
		}

	}

	for(int i=1;i<n+1;i++){
		cin >> arr[i]->data;
	}

	Node* root = arr[1];
	return root;
}

void Inorder(Node* node){

	if(node==NULL)return;

	Inorder(node->left);
	io.push_back(node);
	Inorder(node->right);
}

void Preorder(Node* node){

	if(node == NULL){
		return;
	}

	pre.push_back(node);
	Preorder(node->left);
	Preorder(node->right);
}

int main(){

	int n;
	cin >> n;
	Node* node = tree(n);
	Inorder(node);
	for(Node* n:io){
		cout << n->data << " ";
	}

	cout << "\n";

	Preorder(node);
	for(Node* p:pre){
		cout << p->data << " ";
	}

}

