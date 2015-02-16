#pragma once
#include <windows.h>
class LinkNode
{
public:
	void setNext(LinkNode* next);
		LinkNode * getNext();
		int getValue();
		LinkNode(int value);
		LinkNode(int value, LinkNode* next){
			Next = next;
			Value = value;
		};
		LinkNode(){
			Next = NULL;
			Value = 0;
		};
		~LinkNode();
private:
	LinkNode * Next;
	int Value;

};
class LinkedList
{
private:
	LinkNode * Root;
	int Count;
public:
	LinkedList();
	~LinkedList();
	void Insert(int value);
	int Pop();
	int Size();

};

