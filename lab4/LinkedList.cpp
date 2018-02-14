#include "LinkedList.h"
#include <string>
#include <iostream>
using namespace std;

LinkedList::LinkedList(){
	head = nullptr;
	tail = nullptr;
	length =0;
}
bool LinkedList::isEmpty() const{
	return (head==nullptr) ;
}
int LinkedList::getLength() const{
	return length;
}
bool LinkedList::append(const ItemType & newEntry){
	node* p = new node;
	p->data = newEntry;
	if (head == nullptr){
		head = p;
		tail = p;
		p->next = nullptr;
	}else{
		tail->next = p;
		tail = p;
		p->next = nullptr;
	}
	length++;
	return true;
}
bool LinkedList::insert(int newPos,const ItemType & newEntry){
	node* copy = head;	
	if (newPos >length||newPos <1){
		return false;
	}
	node* a = new node;
	a->data = newEntry;
	if (newPos == length){
		return append(newEntry);
	}
	for(int i=0;i<newPos;i++){
		copy=copy->next;
	}
	a->next = copy->next;
	copy->next = a->next;
	length++;
	return true;
}
bool LinkedList::remove(int newPos){
	node* a = head;	
	if(newPos>length||newPos <1){
		return false;
	}
	for(int i=0;i<newPos-1;i++){
		a = a->next;
	}
	if(newPos == length){
		tail = head;
	}
	node* b = a->next;
	a->next = b->next;
	delete b;
	return true;
}
ItemType LinkedList::retrieve(int newPos) const{
	node* a = head;
	if(newPos>length||newPos <1){
		return "";
	}
	for(int i =1;i<newPos;i++){
		a = a->next;
	}
	return a->data;
}







	

