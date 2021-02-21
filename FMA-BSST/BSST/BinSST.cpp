/*	BinSST.cpp - by Rece Thompson-Hamilton */

#include "BinSST.h"

string StrRepeat(string str, int amount) {
	string result = "";
	for (int i = 0; i < amount; ++i)
		result += str;
	return result;
}

Node* BinSST::Delete(Node* node, int x) {
	if (node == nullptr) return node;

	if (x < node->key) {
		node->left = Delete(node->left, x);
		return node;
	}

	if (x > node->key) {
		node->right = Delete(node->right, x);
		return node;
	}

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
	return parent;
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

Node* BinSST::Insert(Node* node, int x) {
	if (node == nullptr) {
		return new Node(x);
	}

	if (x < node->key)
		node->left = Insert(node->left, x);
	else
		node->right = Insert(node->right, x);

	return node;
}

string BinSST::Print(Node* node, int leg) {
	string str = "";
	if (node == nullptr)
		return "{}";

	string branch = "\tLeg " + to_string(leg) + ":\t";
	string key = "[" + to_string(node->key) + "]";

	string lt = "";
	string lNode = "";
	if (node->left != nullptr){
		lt = "L: " + to_string(node->left->key);
		lNode = "\nLeft" + Print(node->left, leg + 1);
	}

	string rt = "";
	string rNode = "";
	if (node->right != nullptr) {
		rt = " | R: " + to_string(node->right->key);
		rNode = "\nRight" + Print(node->right, leg + 1);
	}
	
	str = branch + key + " (" + lt + rt +")"+ lNode + rNode;
	
	return str;
}
