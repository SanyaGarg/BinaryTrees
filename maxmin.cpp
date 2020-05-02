#include<bits/stdc++.h>

using namespace std;


struct Node
{
	int data;
	Node* left;
	Node* right;

	Node(int x){
		data = x;
		left = NULL;
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

	for(int i=1;i<n;i++){				//1 to n-1
			
			cin >> a>>b>>c;

			if(c=='L'){
				arr[a]->left = arr[b];
			}else if(c == 'R'){
				arr[a]->right = arr[b];
			}
	}

	for(int i=1;i<n+1;i++){
		cin >> arr[i]->data;
	}
	Node* root = arr[1];
	return root;

}

int findmax(int a,int b){
	if(a>b)return a;
	else return b;

}

int max(Node* node){
	if(node->left==NULL && node->right==NULL){
		return node->data;
	}

	return findmax(max(node->left),max(node->right));
}

void PostOrder(Node* node){

	if(node== NULL){
		return ;
	}

	PostOrder(node->left);
	cout << max(node) << " ";
	PostOrder(node->right);
	
}

int main(){

	int n; 
	cin >> n;
	Node* node = tree(n);
	PostOrder(node);
}