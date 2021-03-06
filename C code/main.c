#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "tree.h"
#include "vararray.h"
#include "ll.h"

void data_types();
void control_structures();
void n_appears_n_times(struct vararray *va);
int recursive(int num, int flag);


int main()
{
	/*
		Binary tree sort
		----------------

		This implements the rquired binary tree and makes use of fixed sized arrays and two or more function calls.
	*/

	// The numbers 1-100 in random order
	int ints[100] = { 50, 62, 19, 36, 40, 29, 20, 94, 60, 96, 92, 30, 53, 32, 67, 59, 73, 33, 66, 47, 26, 12, 6, 74, 48, 1, 21, 49, 84, 79, 2, 9, 11, 31, 97, 56, 91, 15, 87, 61, 7, 16, 5, 100, 28, 38, 68, 89, 77, 17, 54, 39, 86, 93, 85, 99, 58, 75, 25, 34, 98, 8, 71, 83, 82, 88, 35, 14, 45, 22, 3, 78, 64, 81, 37, 55, 69, 43, 10, 42, 63, 90, 72, 57, 24, 13, 27, 4, 23, 44, 70, 41, 80, 76, 95, 46, 65, 51, 52, 18 };
	
	printf("Result of sorting using binary tree: \n");
	sort(&ints, 100);

	/*
		Variable Array Test
		-------------------

		This implements the required variable sized array and the loop nesting requirement
	*/

	// Create a variable sized array with only a capacity of 2
	struct vararray va;
	vararray_init(&va, 2);

	// Exercise the variable sized array by having the n_appears_n_times function work on it
	n_appears_n_times(&va);

	// This will grow the array to fit 130 values and will zero out the values until 130.
	vararray_set(&va, 130, 123456);

	printf("\n\nResult of insertion into variable array: \n");
	
	for (int i = 0; i < va.size; i++)
	{
		printf("%d ", vararray_get(&va, i));
	}

	/*
		Sorted Linked List Test
		-----------------------

		This implements a simple insert-only sorted linked list
	*/

	// Create the root node
	struct ll_node* root = malloc(sizeof(struct ll_node));
	root->next = 0;
	root->value = ints[0];

	// Insert everything from the integer array into the sorted linked list
	for (int i = 1; i < 100; i++)
	{
		ll_push(root, ints[i]);
	}

	
	printf("\n\nResult of sorting using linked list: \n");

	struct ll_node* node = root;

	// Output all node values
	while (1) 
	{
		printf("%d ", node->value);

		// Stop advancing if the next node is null
		if (node->next == 0) 
		{
			break;
		}

		node = node->next;
	}

	/*
		Basic Functionality Tests
		-------------------------

		This tests the differet C data types, control structures, and includes an example of a recursive function
	*/
	data_types();
	control_structures();
	recursive(4, 0);

	getch();
	return 0;
}



void data_types()
{
	// Manipulate character type
	char c = 'a';
	signed char sc = 'a';
	unsigned char uc = 'a';

	c = 'b';
	sc++;
	uc++;

	// Maniuplate int type
	int i = 1000;
	unsigned int ui = 1000;
	short int si = 1000;
	unsigned short int usi = 1000;
	long int li = 1000;
	unsigned long int uli = 1000;
	long long int lli = 1000;
	unsigned long long int ulli = 1000;

	i += 100;
	ui += 100;
	si += 100;
	usi += 100;
	li += 100;
	uli += 100;
	lli += 100;
	lli += 100;
	ulli += 100;	

	// Manipulate foat type
	float f = 1000.1001;
	f += 1.1;
	
	// Manipulate double type
	double d = 1000.1001;
	long double ld = 1000.1001;
	
	d += 1.1;
	ld += 1.1;

	// Manipulate boolean type
	bool b = true;
	b = false;


	// Structs
	struct s
	{
		char name[100];
		long int uin;
		int day;
		int month;
		int year;
	};
	struct s s_example = { "Example Student", 123456789, 1, 1, 2001 };

	// Arrays (manipulated elsewhere)
	char ca[] = { 'a', 'b', 'c' };
	int ia[] = { 1, 2, 3 };
	float fa[] = { 1.0, 2.0, 3.0 };
	double da[] = { 1.0, 2.0, 3.0 };

	// Pointers (manipulated elsewhere)
	char * cp = &c;
	int * ip = &i;
	float * fp = &f;
	double * dp = &d;
}

/*
	Covers all C control structures:
	- if, else, elseif
	- while, do while
	- for
	- switch
	- break, continue
	- goto
*/
void control_structures()
{
	int if_flag;
	int switch_flag;

	// for, if, else, elseif, switch, break
	for (int i = 0; i < 3; i++)
	{
		if (i == 0) if_flag = 0;
		else if (i == 1) if_flag = 1;
		else if_flag = i;

		switch (i)
		{
		case 0: 
			switch_flag = 0;
			break;
		case 1:
			switch_flag = 1;
			break;
		default:
			switch_flag = i;
		}
	}

	// while, continue
	int i = 0;
	while (i < 10)
	{
		if (i == 3)
		{
			i += 2;
			continue;
		}

		i++;
	}

	// do while
	i == 0; // Note this is skipped in ASM
	do
	{
		i++;
	} while (i < 10);

	// goto
	int x = 0;

	goto target;

	// This bit should be skipped
	x = 1;

target:
	// X will only set to 3 if the x = 1 was skipped
	if(x == 0) x = 3;
}

void n_appears_n_times(struct vararray *va)
{
	// Creative method build the "n appears n times" sequence (https://oeis.org/A002024) 
	int z = 0;
	for (int i = 1; i <= 15; i += 1) // Compute the sequence out to 15
	{
		for (int x = 2; x > 0; x--) // This loop does nothing except make the asm more complicated
		{
			for (int y = 0; y < i; y += 1) // Actual loop that outputs "n n times"
			{
				if (x == floor(sqrt(256) / 6)) // Complicated way of saying: if( x == 2 )
				{
					vararray_set(va, z++, abs(i));
				}
				else
				{
					continue;
					vararray_append(va, abs(i)); // Never gets reached but still in asm					
				}
			}
		}
	}
}

int recursive(int num, int flag)
{
	if (flag == 8){
		return num;
	}
	else {
		return recursive(num + 4, ++flag);
	}
}