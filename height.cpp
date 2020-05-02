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

int height(Node* node){

	if(node==NULL){
		return 0;
	}

	if(node->right==NULL && node->left== NULL)return 0;

	return findmax(height(node->right),height(node->left))+1;
}

int getdiameter(Node* root,int diameter){

	if(root==NULL)return 0;

	int maxdiameter = getdiameter(root->left,diameter) + getdiameter(root->right,diameter) + 1;
	diameter = max(diameter,maxdiameter);

	return max(getdiameter(root->left,diameter),getdiameter(root->right,diameter)) +1;
}

int getdiameter(Node* root){
	int diameter = 0;
	diameter = getdiameter(root,diameter)

	return diameter;
}

int main(){

	int n; 
	cin >> n;
	Node* node = tree(n);
	cout << height(node);
}