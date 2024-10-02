#include<iostream>
#include<vector>
#include<algorithm>
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

void flip(Node* root){
	if(root == nullptr){
		return;
	}

	Node* temp = root->left;
	root->left = root->right;
	root->right = temp;

	flip(root->left);
	flip(root->right);
}

void extractinorderkeys(Node* root, vector<int>& keys){
	if(root == nullptr){
		return;
	}
	extractinorderkeys(root->left, keys);
	keys.push_back(root->data);
	extractinorderkeys(root->right, keys);
}

void fillFlippedStructure(Node* root, vector<int>& keys, int& index){
	if(root == nullptr){
		return;
	}

	fillFlippedStructure(root->left, keys, index);
	root->data  = keys[index++];
	fillFlippedStructure(root->right, keys, index);
}

int main(){

	Node* root = nullptr;

	root = insert(root, 4);
	root = insert(root, 5);
	root = insert(root, 9);
	root = insert(root, 2);
	root = insert(root, 12);
	root = insert(root, 6);
	
	vector<int> keys;
        extractinorderkeys(root, keys);

	cout<<"In-order Traversal of the BST: ";
	inorder(root);
	cout<<endl;

	cout<<"Pre-Order Traversal of the BST: ";
	preorder(root);
	cout<<endl;

	flip(root);

	cout<<"In-Order Traversal of the flipped BST: ";
	inorder(root);
	cout<<endl;

	cout<<"Pre-Order Traversal of the flipped BST: ";
	preorder(root);
	cout<<endl;

	//vector<int> keys;
	//extractinorderkeys(root, keys);
	
	//sort(keys.begin(), keys.end());	

	int index=0;
	fillFlippedStructure(root, keys, index);
	cout<<"Filled flipped structure values (In-order): ";
	inorder(root);
	cout<<endl;
	cout<<"Filled flipped structure value (Pre_Order): ";
	preorder(root);
	cout<<endl;
	
	return 0;
}
