#include<iostream>
#include<vector>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;

	Node(int value){
		data=value;
		left=right=nullptr;
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

void  preorder(Node* root){
	if(root == nullptr){
		return;
	}

	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

// Function to flip the tree (swap left and right children of every node)
void flip(Node* root) {
    if (root == nullptr) {
        return;  // Base case: if the node is empty, return
    }

    // Swap the left and right children of the current node
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recursively flip the left and right subtrees
    flip(root->left);
    flip(root->right);
}

int main(){
	Node* root = nullptr;
	int n,value;

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
	root = insert(root, 30);
	root = insert(root, 20);
	root = insert(root, 40);
    	root = insert(root, 70);
    	root = insert(root, 60);
    	root = insert(root, 80);
	*/
    	// Print the in-order traversal of the BST
    	cout << "In-order traversal of the BST: ";
    	inorder(root);
	cout<<endl;
	// Print the pre-order traversal of the BST
    	cout << "Pre-order traversal of the BST: ";
    	preorder(root);
    	cout << endl;
	
	// Perform the flip operation on the BST
    	flip(root);

    	// Print the in-order traversal of the flipped BST
    	cout << "In-order traversal of the flipped BST: ";
    	inorder(root);
    	cout << endl;

    	// Print the pre-order traversal of the flipped BST
    	cout << "Pre-order traversal of the flipped BST: ";
    	preorder(root);
    	cout << endl;
	return 0;
}
