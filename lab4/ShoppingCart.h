#ifndef linked_List_
#define linked_List_

#include "LinkedList.h"
#include <string>
using namespace std;

class ShoppingCart {

public:
	ShoppingCart();
	bool add(ItemToPurchase newitem);
	bool add(ItemToPurchase newitem,int  position);
	bool remove(int position) ;
	void display(int position);
	void display();
	void displayCost(int position);
	void displayCost();
	void displayNumber();
private:
	LinkedList cart;
}

