#include "LinkedList.h"

LinkNode::LinkNode(int val){
	Value = val;
	Next = NULL;
}

LinkNode::~LinkNode(){

}
void LinkNode::setNext(LinkNode* next){
	Next = next;
}
LinkNode * LinkNode::getNext(){
	return Next;
}
int LinkNode::getValue(){
	return Value;
}

LinkedList::LinkedList(){
	Root = NULL;
	Count = 0;
}
LinkedList::~LinkedList(){

}
void LinkedList::Insert(int value){
	Count++;
	if (Root == NULL){
		Root = new LinkNode(value);
	}
	else if (Root->getValue() <= value)
	{
		LinkNode * Temp = new LinkNode(value, Root);
		Root = Temp;
	}else
	{
		LinkNode * temp = Root;
		while (temp->getNext() != NULL){
			if (temp->getValue() >= value && temp->getNext()->getValue() < value){
				LinkNode * tn = temp->getNext();
				temp->setNext(new LinkNode(value, tn));
				//Break out of function
				return;
			}
			else {
				temp = temp->getNext();
			}
		}
		temp->setNext(new LinkNode(value));
	}
}

int LinkedList::Pop(){
	if (Root != NULL){
		Count--;
		LinkNode * temp = Root;
		Root = Root->getNext();
		return temp->getValue();
	}
	else {
		return NULL;
	}
}

int LinkedList::Size(){
	return Count;
}