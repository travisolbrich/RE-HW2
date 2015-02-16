#pragma once
#include <iostream>
using namespace std;
class dataTypes
{
public:
	int size;

	dataTypes(int s);
	~dataTypes();

	void PrintOut();
	// Basic types
	char c = 'a';
	signed char sc = 'a';
	unsigned char uc = 'a';

	int i = 1000;
	int * _vArray;
	unsigned int ui = 1000;
	short int si = 1000;
	unsigned short int usi = 1000;
	long int li = 1000;
	unsigned long int uli = 1000;
	long long int lli = 1000;
	unsigned long long int ulli = 1000;

	float f = 1000.1001;

	double d = 1000.1001;
	long double ld = 1000.1001;

	bool b = true;

	// Structs
	struct s
	{
		char name[100];
		long int uin;
		int day;
		int month;
		int year;
	};

	// Arrays
	char ca[30];
	int ia[30];
	float fa[30];
	double da[30];

	// Pointers
	char *cp = &c;
	int *ip = &i;
	float *fp = &f;
	double *dp = &d;

};
