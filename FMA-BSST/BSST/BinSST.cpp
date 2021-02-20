#include "BinSST.h"

BinSST::~BinSST() {
	/* Delete all node pointers! */
}

Node* BinSST::Delete(Node* node, int x) {
	if (node == nullptr) return node;

	if (x < node->key) 
		node->left = Delete(node->left, x);

	if (x > node->key) 
		node->right = Delete(node->right, x);

	//if leaf node
	if (node->left == nullptr && node->right == nullptr) {
		free(node);
		node = nullptr;
	
	} else {

		//if two children
		if (node->left != nullptr && node->right != nullptr) {
			Node* successor = FindMin(node->right);
			node->key = successor->key;
			node->right = Delete(node->right, successor->key);
			return node;
		}

		//if only left child
		if (node->left != nullptr) {
			Node* temp = node->left;
			free(node);
			return temp;
		}

		//if only right child
		if (node->right != nullptr) {
			Node* temp = node->right;
			free(node);
			return temp;
		}
	}

	return node;
}

Node* BinSST::Find(Node* node, int x) {
	if (&node == nullptr) return node;

	if (node->key == x)
		return node;

	if (node->left == nullptr && node->right == nullptr)
		return nullptr;

	if (x < node->key)
		return Find(node->left, x);
	else
		return Find(node->right, x);
}

Node* BinSST::FindMin(Node* node) {
	Node* parent = node;
	Node* leftmost = node->left;
	Node* orphan = node->right;

	//get left most node of sub tree
	while (leftmost != nullptr) {
		parent = leftmost;
		orphan = leftmost->right;
		leftmost = leftmost->left;
	}

	//shift up dangling orphan, if any
	if (orphan != nullptr)
		parent->left = orphan;

	//return left most child
	return leftmost;
}

Node* BinSST::FindMax(Node* node) {
	Node* parent = node;
	Node* rightmost = node->right;
	Node* orphan = node->left;

	//get left most node of sub tree
	while (rightmost != nullptr) {
		parent = rightmost;
		orphan = rightmost->left;
		rightmost = rightmost->right;
	}

	//shift up dangling orphan, if any
	if (orphan != nullptr)
		parent->right = orphan;

	//return right most child
	return rightmost;
}

void BinSST::Insert(int x) {
	if (_root == nullptr) {
		_root = new Node(x);
		return;
	}

	Insert(_root, x); 
}

Node* BinSST::Insert(Node* node, int x) {
	if (node == nullptr) {

		//node = newNode;// (x);
		return new Node(x);
	}

	if (x < node->key)
		return Insert(node->left, x);
	else
		return Insert(node->right, x);
}

void BinSST::Print(Node* node, int leg) {
	if (node == nullptr) {
		std::cout << "{}";
		return;
	}

	std::cout << leg << ": " << node->key << std::endl;

	leg++;

	Print(node->left, leg);
	Print(node->right, leg);
}
