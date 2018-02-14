#include <iostream>
#include "LinkedList.h"
#include <string>
using namespace std;

int main(){
	string	firsts = "This";
	string seconds = "should";
	string thirds = "work";
	LinkedList tester;
	cout<<"Testing length, should be zero"<<endl<<tester.getLength()<<endl;
	cout<<"Testing isEmpty, should be true"<<endl<<tester.isEmpty()<<endl;
	cout<<"Testing append, should return true three times"<<endl;
	cout<<tester.append(firsts)<<endl;
	cout<<tester.append(seconds)<<endl;
	cout<<tester.append(thirds)<<endl;
	cout<<"Testing length, should be 3"<<endl<<tester.getLength()<<endl;
	cout<<"Testing isEmpty, should be false"<<endl<<tester.isEmpty()<<endl;
	return 0;
}

