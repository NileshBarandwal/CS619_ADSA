#include<iostream>
using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;

	Node(int value){
		data = value;
		left = right = nullptr;
	}
};

Node* insert(Node* root, int value){
	if(root == nullptr){
		return new Node(value);
	}

	if(value < root->data){
		root->left = insert(root->left, value);
	}else{
		root->right = insert(root->right, value);
	}

	return root;
}

void inorder(Node* root){
	if(root == nullptr){
		return;
	}

	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

void preorder(Node* root){
	if(root == nullptr){
		return;
	}
	
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

int main(){

	Node* root = nullptr;
	
	int n, value;
	// Take input from the user for the number of elements to insert
    	cout << "Enter the number of elements to insert into the BST: ";
    	cin >> n;

	 // Take input for the values and insert them into the BST
    	cout << "Enter the values to insert into the BST: " << endl;
    	for (int i = 0; i < n; i++) {
        	cin >> value;
   		root = insert(root, value);
    	}

	/*
	root = insert(root, 50);
	root = insert(root, 40);
	root = insert(root, 1);
	root = insert(root, 100);
	*/

	cout<<"In-order Traversal of the BST: ";
	inorder(root);
	cout<<endl;

	cout<<"Pre-Order Traversal of the BST: ";
	preorder(root);
	cout<<endl;

	return 0;
}
