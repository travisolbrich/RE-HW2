#pragma once
#include <windows.h>
#include <iostream>
using namespace std;
struct Node{
	Node *left;
	Node *right;
	int value;
};

class Tree{
public:


	Tree();
	Tree(Node * root);
	void insert(int key);
	Node *search(int key);
	void destroy_tree();
	void display();

private:
	void destroy_tree(Node *leaf);
	void insert(int key, Node *leaf);
	void display(Node **leaf);
	Node *search(int key, Node *leaf);

	Node *root;
};


