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
//this insert method works by inserting values into the array in assending order
void LinkedList::Insert(int value){
	Count++;
	//if roots null, set root to new value
	if (Root == NULL){
		Root = new LinkNode(value);
	}
	// case if value greate then the value in root
	else if (Root->getValue() >= value)
	{
		LinkNode * Temp = new LinkNode(value, Root);
		Root = Temp;
	}else
	{
		LinkNode * temp = Root;
		// loop throught the while loop until a situation is found where prevouse node is less the current value and the next value is greater 
		while (temp->getNext() != NULL){
			if (temp->getValue() <= value && temp->getNext()->getValue() > value){
				LinkNode * tn = temp->getNext();
				// create the next node and set the next node value to temp prevouse next node
				temp->setNext(new LinkNode(value, tn));
				//Break out of function
				return;
			}
			else {
				//increment to the next node
				temp = temp->getNext();
			}
		}
		//append to the end
		temp->setNext(new LinkNode(value));
	}
}

//remove the current head
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
// return the size variable
int LinkedList::Size(){
	return Count;
}