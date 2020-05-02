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

int sumtree(Node* &node){

	if(node==NULL)return 0;

	if(node->right==NULL && node->left==NULL)return node->data;

	 node->data = sumtree(node->left)+sumtree(node->right);

	return node->data;
}

void PostOrder(Node* node){

	if(node== NULL){
		return ;
	}

	PostOrder(node->left);
	PostOrder(node->right);
	cout << node->data << " ";
}

int main(){

	int n;
	cin >> n;
	Node* root = tree(n);

	sumtree(root);

	PostOrder(root);
}