#include "ll.h"


// Insert value into the sorted linked list
void ll_push(struct ll_node *node, int val)
{

	// If the current node is higher, insert before
	if (val < node->value)
	{
		struct ll_node* newNode = malloc(sizeof(struct ll_node));
		newNode->next = node->next;
		newNode->value = node->value;

		node->value = val;
		node->next = newNode;
	}

	// If the next node is null, insert
	else if (node->next == 0)
	{
		struct ll_node* newNode = malloc(sizeof(struct ll_node));
		newNode->value = val;
		newNode->next = 0;

		node->next = newNode;
	}

	// If the next node is higher than our number, insert
	else if (val <= node->next->value)
	{
		struct ll_node* nextNode = node->next;
		struct ll_node* newNode = malloc(sizeof(struct ll_node));

		newNode->value = val;
		newNode->next = nextNode;
		node->next = newNode;
	}

	// Else, continue
	else
	{
		ll_push((node->next), val);
	}

}