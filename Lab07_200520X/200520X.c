#include <iostream>
using namespace std;

struct node {
	int key;
	struct node *left, *right;
};

//newNode Creation
struct node *newNode(int item){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}


// Inorder traversal
void traverseInOrder(struct node *root) {
	if (root != NULL) {
		traverseInOrder(root->left);  //Left traversion
		cout << root->key << " ";
		traverseInOrder(root->right);  //Right traversion
	}
}

// Insert a node
struct node *insertNode(struct node *node, int key) {
	if (node == NULL) return newNode(key);
	
	if (key < node->key)
	node->left = insertNode(node->left, key);
	else
	node->right = insertNode(node->right, key);
	
	return node;
}

//Succesor of the tree
struct node *minValueNode(struct node *node) {
	struct node *current = node;

	while (current && current->left != NULL)
	current = current->left;

	return current;
}


// Deleting a node
struct node *deleteNode(struct node *root, int key) {
	
	if (root == NULL) return root;   //Empty Tree

	if (key < root->key)
	root->left = deleteNode(root->left, key);
	else if (key > root->key)
	root->right = deleteNode(root->right, key);
	else {
		// Node with only one child or no child
		if (root->left == NULL) {
			struct node *temp = root->right;
			free(root);
			return temp;
			} else if (root->right == NULL) {
			struct node *temp = root->left;
			free(root);
			return temp;
		}

		// Node has two children
		struct node *temp = minValueNode(root->right);

		// Place successor
		root->key = temp->key;

		// Delete the inorder successor
		root->right = deleteNode(root->right, temp->key);
	}
	return root;
	
}

// Driver code
int main() {
	struct node *root = NULL;

	int operation;
	int operand;
	cin >> operation;

	while (operation != -1) {
		switch(operation) {
			case 1: // insert
			cin >> operand;
			root = insertNode(root, operand);
			cin >> operation;
			break;
			case 2: // delete
			cin >> operand;
			root = deleteNode(root, operand);
			cin >> operation;
			break;
			default:
			cout << "Invalid Operator!\n";
			return 0;
		}
	}
	
	traverseInOrder(root);
}