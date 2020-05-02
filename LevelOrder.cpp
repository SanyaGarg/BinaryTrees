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

void PostOrder(Node* node){

	if(node== NULL){
		return ;
	}

	PostOrder(node->left);
	PostOrder(node->right);
	cout << node->data << " ";
}

int cnt =0;
void Inorder(Node* node,int k){
	
	if(node==NULL){
		cnt++;
		return;
	}

	Inorder(node->left,k);
	if(cnt==k)cout << node->data;
	Inorder(node->right,k);
}

void LevelOrder(Node* node){

	if(node== NULL){
		return;
	}

	queue<Node*> q;

	q.push(node);

	while(!q.empty()){

		Node* node = q.front();
		cout << node->data << " ";

		if(node->left!=NULL){
			q.push(node->left);
		}

		if(node->right!=NULL){
			q.push(node->right);
		}

		q.pop();
	}
}

int main(){

	int n; 
	cin >> n;
	Node* node = tree(n);
	//LevelOrder(node);
	int k;
	cin >> k;
    Inorder(node,k);
	
} 