#pragma once
#include <iostream>
using namespace std;

//This is a simple class meant to demo the template functionality of the C++ lang
template <class T>
class TemplateClass
{
	
public:
	T value;
	TemplateClass(T val){
		value = val;
	}
	void TempleClass(){
		value = NULL;
	}
	void display(){
		// just print out the object stored in the 
		cout << value << endl;
	}
	~TemplateClass(){};
};

//class template specialization
template <>
class TemplateClass<string>
{

public:
	string value;
	TemplateClass(string val){
		value = val;
	}
	// different method for a templated object of the string type
	void displaystr(){
		printf("%s\n", value.c_str());
	}
	~TemplateClass(){};
};
