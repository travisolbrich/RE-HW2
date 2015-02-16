#include <iostream>
#include <stdlib.h>     
#include <time.h> 
#include <windows.h>
#include <tchar.h>
#include <strsafe.h>
#include <vector>
#include "Tree.h"
#include "LinkedList.h"
#include "dataTypes.h"
#define Number 10

using namespace std;

int recursive(int num, int flag);

bool randTrue();

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
	i == 0;
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
	if (x == 0) x = 3;
}

void functionByref(dataTypes dt){
	cout << "By ref" << endl;
	cout << dt.f << endl;
	dt.PrintOut();
}

void functionByPointer(dataTypes * dtp){
	
	cout << "By Pointer" << endl;
	cout << dtp->f << endl;
	dtp->PrintOut();
}
int main(int argc, char* args){

	srand(time(NULL));

	cout << "Test" << endl;
	int rec = recursive(4, 0);
	cout << "Rec Number: " << rec << endl;

	//Loops
	// Creative method build the "n appears n times" sequence (https://oeis.org/A002024) 
	int z = 0;
	vector<int> vec = vector<int>();

	for (int i = 1; i <= 15; i += 1)
	{
		for (int x = 2; x > 0; x--)
		{
			for (int y = 0; y < i; y += 1)
			{
				if (x == floor(sqrt(256) / 6))
				{
					vec.emplace(vec.begin() + z++, abs(i));  
				}
				else
				{
					continue;
					vec.push_back(abs(i)); // Never gets reached but still in asm					
				}
			}
		}
	}
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}
	cout << endl;

	bool flag = true;
	int count = 0;
	while (flag){
		cout <<"Count True: "<< count << endl;
		flag = randTrue();
		count++;
	}
	
	count = 0;
	do{
		cout << "Count False: " << count << endl;
		flag = randTrue();
		count++;
	} while (!flag);
	
	cout << "Tree section" << endl;


	Tree t = Tree();

	int ints[100] = { 50, 62, 19, 36, 40, 29, 20, 94, 60, 96, 92, 30, 53, 32, 67, 59, 73, 33, 66, 47, 26, 12, 6, 74, 48, 1, 21, 49, 84, 79, 2, 9, 11, 31, 97, 56, 91, 15, 87, 61, 7, 16, 5, 100, 28, 38, 68, 89, 77, 17, 54, 39, 86, 93, 85, 99, 58, 75, 25, 34, 98, 8, 71, 83, 82, 88, 35, 14, 45, 22, 3, 78, 64, 81, 37, 55, 69, 43, 10, 42, 63, 90, 72, 57, 24, 13, 27, 4, 23, 44, 70, 41, 80, 76, 95, 46, 65, 51, 52, 18 };

	for (int i = 0; i < 100; i++){
		t.insert(ints[i]);
	}

	t.display();
	cout << endl;

	t.destroy_tree();

	cout << "Data Types" << endl;

	LinkedList list = LinkedList();

	for (int i = 0; i < 100; i++){
		cout << i << " ";
		list.Insert(ints[i]);
	}
	cout << list.Size() << endl;
	while (list.Size() > 0){
		cout << list.Pop() << " ";
	}
	cout << endl;
	dataTypes * dtp = new dataTypes(100);

	dataTypes dt= dataTypes(10);
	
	dt.PrintOut();


	functionByPointer(&dt);
	functionByPointer(dtp);
	functionByref(dt);

	delete dtp;

	char c;
	cin >> c;
}

bool randTrue(){
	int sec = rand() % 10 + 1;

	return !(sec > 7);
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