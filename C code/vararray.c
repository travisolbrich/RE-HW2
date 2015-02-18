// I used http://www.happybearsoftware.com/implementing-a-dynamic-array.html to learn how to make
// variable sized arrays in C.

#include "vararray.h"

// Create a new variable sized array
void vararray_init(struct vararray *va, int capacity)
{
	va->size = 0;
	va->capacity = capacity;
	
	va->data = malloc(sizeof(int) * capacity);
}

// Add to the end of a variable sized array
void vararray_append(struct vararray *va, int value)
{
	vararray_grow_if_full(va);

	va->data[va->size] = value;
	va->size++;
}

// Get a certain item from the variable sized array
int  vararray_get(struct vararray *va, int index)
{
	return va->data[index];
}

// Set an item in the variable sized array (may need to grow to that point)
void vararray_set(struct vararray *va, int index, int value)
{
	// Zero up to the set index
	while (index >= va->size)
	{
		vararray_append(va, 0);
	}

	va->data[index] = value;
}

// If the variable array has reached capacity, grow it
void vararray_grow_if_full(struct vararray *va)
{
	if (va->size >= va->capacity)
	{
		va->capacity += AMOUNT_TO_GROW;
		va->data = realloc(va->data, sizeof(int)* va->capacity);
	}
}

void vararray_free(struct vararray *va)
{
	free(va->data);
}
