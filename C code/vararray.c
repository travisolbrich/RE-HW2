#include "vararray.h"

void vararray_init(struct vararray *va, int capacity)
{
	va->size = 0;
	va->capacity = capacity;
	
	va->data = malloc(sizeof(int) * capacity);
}

void vararray_append(struct vararray *va, int value)
{
	vararray_grow_if_full(va);

	va->data[va->size] = value;
	va->size++;
}

int  vararray_get(struct vararray *va, int index)
{
	return va->data[index];
}

void vararray_set(struct vararray *va, int index, int value)
{
	// Zero up to the set index
	while (index >= va->size)
	{
		vararray_append(va, 0);
	}

	va->data[index] = value;
}

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
