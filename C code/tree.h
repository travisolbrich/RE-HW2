struct node
{
	int value;
	struct node *left;
	struct node *right;
};

int *sort(int *input, int count);
void insert(int key, struct node **leaf);
void output(struct node *leaf);