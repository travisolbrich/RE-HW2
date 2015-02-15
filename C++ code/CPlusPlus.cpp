#include <iostream>
#include <stdlib.h>     
#include <time.h> 
#include <windows.h>
#include <tchar.h>
#include <strsafe.h>

#define Number 10

using namespace std;

int recursive(int num, int flag);

bool randTrue();

struct Node{
	Node *left;
	Node *right;
	int value;
};

class Tree{
	private:
		Node* Root;
	public:
		Tree();
		Tree(Node * root);
};

int main(int argc, char* args){

	srand(time(NULL));

	cout << "Test" << endl;
	int rec = recursive(4, 0);
	cout << "Rec Number: " << rec << endl;

	for (int i = 0; i < rec; i++){
		for (int j = 0; j < rec; j++){
			for (int n = 0; n < rec; n++){
				// cout << i*j*n << endl;
			}
		}
	}
	bool flag = true;
	int count = 0;
	while (flag){
		cout <<"Count: "<< count << endl;
		flag = randTrue();
		count++;
	}
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