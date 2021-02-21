/*	BinSST.h - by Rece Thompson-Hamilton */

#pragma once
#include <iostream>
#include <string>

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
public:

	Node*	_root =	nullptr;

	BinSST() : _root(nullptr) {}
	~BinSST() { free(_root); }

	Node*	Delete	(Node* node, int x);
	Node*	Find	(Node* node, int x);
	Node*	Insert	(Node* node, int x);
	string	Print	(Node* node, int leg = 0);

private:
	
	Node*	FindMin	(Node* node);
	Node*	FindMax	(Node* node);
};
