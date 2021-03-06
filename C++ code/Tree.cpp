#include "Tree.h"

Tree::Tree()
{
	root = NULL;
}

//Public method for displaying the 
void Tree::display(){
	display(&root);
}

//simple in order tree traversal
void Tree::display(Node **leaf){

	if (leaf != NULL)
	{
		//cout << endl;
		if (!(*leaf)->left == NULL)
			display(&(*leaf)->left);

		cout << (*leaf)->value << " ";

		if (!(*leaf)->right == NULL)
			display(&(*leaf)->right);
		//cout << endl;
	}
	
}
//Destorys the tree
void Tree::destroy_tree(Node *leaf)
{
	if (leaf != NULL)
	{
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
}

void Tree::insert(int key, Node *leaf)
{
	// insert the value to the left if the value is less 
	if (key< leaf->value)
	{
		if (leaf->left != NULL)
			insert(key, leaf->left);
		else
		{
			leaf->left = new Node;
			leaf->left->value = key;
			leaf->left->left = NULL;    //Sets the left child of the child node to null
			leaf->left->right = NULL;   //Sets the right child of the child node to null
		}
	}
	else if (key >= leaf->value)
	{
		if (leaf->right != NULL)
			insert(key, leaf->right);
		else
		{
			leaf->right = new Node;
			leaf->right->value = key;
			leaf->right->left = NULL;  //Sets the left child of the child node to null
			leaf->right->right = NULL; //Sets the right child of the child node to null
		}
	}
}
//public method to insert value
void Tree::insert(int key)
{
	if (root != NULL)
		insert(key, root);
	else
	{
		root = new Node;
		root->value = key;
		root->left = NULL;
		root->right = NULL;
	}
}

//search method
Node *Tree::search(int key)
{
	return search(key, root);
}
Node *Tree::search(int key, Node *leaf)
{
	if (leaf != NULL)
	{
		if (key == leaf->value)
			return leaf;
		if (key<leaf->value)
			return search(key, leaf->left);
		else
			return search(key, leaf->right);
	}
	else return NULL;
}

void Tree::destroy_tree()
{
	destroy_tree(root);
}