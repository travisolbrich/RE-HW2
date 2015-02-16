#include "dataTypes.h"


void dataTypes::PrintOut(){
	cout << d << endl;
	for (int s = 0; s < size; s++){
		cout << _vArray[s] << " ";
	}
	cout << endl;
}
dataTypes::dataTypes(int s){
	_vArray = new int[s];
	size = s;
	for (int i = 0; i < s; i++){
		_vArray[i] = i*i;
	}
}

dataTypes::~dataTypes(){
	//delete [] _vArray;
}
