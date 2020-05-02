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

bool findLCA(Node* node,int a,int b,Node* &lca){

	if(node== NULL)return false;

	if(node->data == a || node->data==b){
		lca = node;
		return true;
	}

	bool left = findLCA(node->left,a,b,lca);
	bool right = findLCA(node->right,a,b,lca);

	if(left && right){
		lca = node;
	}

	return (left || right);
}

int i =0;
void Inorder(Node* node,int io[],int n){

	if(node==NULL)return;

	io[i] = node->data;
	i++;
	Inorder(node->left,io,n);
	Inorder(node->right,io,n);
}

int dis(Node* root,int a,int level){

	if(root == NULL)return 0;

	if(root->data == a)return level;

	int l = dis(root->left,a,level+1);
	if(l!=0)return l;

	return dis(root->right,a,level+1);
}

int distance(Node* root,int a ,int b){

	if(root==NULL)return 0;

	Node* lca = NULL;
	Node* c = NULL;

	if(findLCA(root,a,b,lca)){
		c=lca;
	}

	return (dis(root,a,0)+ dis(root,b,0) - 2*dis(root,c->data,0));
}

int main(){

	int n;
	cin >> n;
	int io[n];

	Node* node = tree(n);

	Inorder(node,io,n);

	Node* lca = NULL;

	// findLCA(node,9,2,lca);
	// cout << lca->data;

	// for(int i=0;i<n;i++){
	// 	cout << io[i] << " ";
	// }

	cout << distance(node,4,4);
}