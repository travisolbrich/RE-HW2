#include "tree.h"

int *sort(int *input, int count)
{
	struct node *root = 0;

	int i = 0;

	for (i; i < count; i++)
	{
		insert(input[i], &root);
	}

	output(root);

}

// I used http://www.cprogramming.com/tutorial/c/lesson18.html to learn how
// to do a tree insertion function in C.
void insert(int key, struct node **leaf)
{
	if (*leaf == 0)
	{
		*leaf = (struct node*) malloc(sizeof(struct node));

		(*leaf)->value = key;
		(*leaf)->left = 0;
		(*leaf)->right = 0;
	}
	else if (key < (*leaf)->value)
	{
		insert(key, &(*leaf)->left);
	}
	else if (key >(*leaf)->value)
	{
		insert(key, &(*leaf)->right);
	}
}


void output(struct node *leaf)
{
	if (leaf != 0)
	{
		output(leaf->left);
		printf("%d ", leaf->value);
		output(leaf->right);
	}
}