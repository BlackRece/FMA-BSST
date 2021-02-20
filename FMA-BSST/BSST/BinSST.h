#pragma once
#include <iostream>

using namespace std;

class Node {
public:
	int key = 0;
	Node* left = nullptr;
	Node* right = nullptr;

	Node(int x) { key = x; }
	~Node() {
		if (left != nullptr)free(left);
		if (right != nullptr)free(right);

		left = nullptr;
		right = nullptr;
	}
};

class BinSST {
private:
	Node*	_root =	nullptr;

public:

	BinSST() :_root(nullptr) {}
	~BinSST();

	Node* Delete(int x) { _root = Delete(_root, x); }
	Node* Find(int x) { return Find(_root, x); }
	void Insert(int x);
	void Print() { Print(_root); }

private:
	
	Node*	Delete	(Node* node, int x);
	Node*	Find	(Node* node, int x);
	Node*	FindMin	(Node* node);
	Node*	FindMax	(Node* node);
	Node*	Insert	(Node* node, int x);
	void	Print	(Node* node, int leg = 0);
};
