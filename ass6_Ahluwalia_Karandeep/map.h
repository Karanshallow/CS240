#ifndef Map_
#define Map_

#include "mapInterface.h"

class Map : public mapInterface {

public:
  Map();
  //Default constructor
  ~Map();
  //Destructor
  Map(const Map & mapped);
  //Copy Constructor
  bool empty() const;
	//input: none
	//output: returns true if the Map is empty; else false
	//side effects: none

	int size() const;
	//input: none
	//output: returns the number of elements in the Map
	//side effects: none

	bool add(ElementType element);
	//input: an element (key and its associated value)
	//output: returns true if the key-value pair was 				     	//        added; else false(the key was found)
	//side effects: Map has one more element (if addition      		     	//              done)

	bool find(KeyType key) const;
	//input: a key
	//output: return true is an element with this key was 			//        found; else false
	//side effects: none

	ValueType retrieve(KeyType key) const;
	//input: a key
	//output: returns the value associated with key (a 			//        null pointer if the key was not found)
	//side effects: none

	bool remove(KeyType key);
	//input: a key
	//output: returns true if item is removed;
	//        else false (key not found)
	//side effects: Map has one less element (if remove 			//              done)
  void operator=(const Map& mapped);
  //Equal operator
  void displayAll() const;
  //input:none
  //output: none
  //side effects: Displays content of program


private:
  class node{
		public:
			node *right;
      node *left;
			ElementType data;
	};
  int length;
	node *head;
  void deleteTree(node* p);
  void copyHelper(node* newhead,node* oldhead);
  void displayer(node* p)const;
	};
#endif
