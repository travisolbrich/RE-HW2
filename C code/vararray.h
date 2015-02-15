// I used http://www.happybearsoftware.com/implementing-a-dynamic-array.html to learn how to make
// variable sized arrays in C.

#define AMOUNT_TO_GROW 10

struct vararray
{
	int size;
	int capacity;
	int *data;
};

void vararray_init(struct vararray *va, int capacity);

void vararray_append(struct vararray *va, int value);

int  vararray_get(struct vararray *va, int index);

void vararray_set(struct vararray *va, int index, int value);

void vararray_grow_if_full(struct vararray *va);

void vararray_free(struct vararray *va);