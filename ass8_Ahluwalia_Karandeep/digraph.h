#ifndef Digraph_
#define Digraph_

#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <string>
#include <fstream>
#include "assert.h"
using namespace std;
class Digraph{
public:
  Digraph();
  //Default constructor
  //Destructor
  Digraph(const Digraph & mapped);
  //Copy Constructor
  bool empty() const;
	//input: none
	//output: returns true if the Map is empty; else false
	//side effects: none

	int sizeVertex() const;
	//input: none
	//output: returns the number of elements in the Map
	//side effects: none
  int sizeEdge() const;
	//input: none
	//output: returns the number of elements in the Map
	//side effects: none

	bool addVertex(string str);
	//input: an element (key and its associated value)
	//output: returns true if the key-value pair was 				     	//        added; else false(the key was found)
	//side effects: Map has one more element (if addition      		     	//              done)
  bool addEdge(string name1,string name2);
	//input: an element (key and its associated value)
	//output: returns true if the key-value pair was 				     	//        added; else false(the key was found)
	//side effects: Map has one more element (if addition      		     	//              done)
  bool removeEdge(string& name1,string& name2);
	//input: an element (key and its associated value)
	//output: returns true if the key-value pair was 				     	//        added; else false(the key was found)
	//side effects: Map has one more element (if addition      		     	//              done)

	bool findEdge(string& name1,string& name2) const;
	//input: a key
	//output: return true is an element with this key was 			//        found; else false
	//side effects: none
  bool findVertex(string& name1) const;
	//input: a key
	//output: return true is an element with this key was 			//        found; else false
	//side effects: none

	vector<string> retrieveVertex() const;
	//input: a key
	//output: returns the value associated with key (a 			//        null pointer if the key was not found)
	//side effects: none

	vector<string> successors(string& str) const;



  vector<string> predcessors(string& str) const;

  bool removeVertex(string& str);



private:
  vector<string> vertices;
  vector< list<int> > edges;
  int vsize;
  int esize;

	};
#endif
