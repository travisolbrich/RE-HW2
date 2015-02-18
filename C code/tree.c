#include "tree.h"

int *sort(int *input, int count)
{
	struct node *root = 0;

	int i = 0;

	// Insert everything from the integer array
	for (i; i < count; i++)
	{
		insert(input[i], &root);
	}

	// Output the sorted array
	output(root);

}

// I used http://www.cprogramming.com/tutorial/c/lesson18.html to learn how
// to do a tree insertion function in C.
void insert(int key, struct node **leaf)
{
	// If we have reached a null leaf create a new leaf
	if (*leaf == 0)
	{
		*leaf = (struct node*) malloc(sizeof(struct node));

		(*leaf)->value = key;
		(*leaf)->left = 0;
		(*leaf)->right = 0;
	}

	// Insert to the left if the key is lower than leaf value
	else if (key < (*leaf)->value)
	{
		insert(key, &(*leaf)->left);
	}

	// Insert to the right if the key is higher than leaf value
	else if (key >(*leaf)->value)
	{
		insert(key, &(*leaf)->right);
	}
}

// Recursively output the sorted list
void output(struct node *leaf)
{
	if (leaf != 0)
	{
		output(leaf->left);
		printf("%d ", leaf->value);
		output(leaf->right);
	}
}