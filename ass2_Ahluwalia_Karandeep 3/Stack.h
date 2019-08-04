#ifndef Stack_
#define Stack_

#import <string>
using namespace std;

class LinkedList {
  public:
    Stack();
    bool isEmpty() const;
    int getLength() const;
    bool Push(const string & newEntry);
    string Pop();
    string Peek() const;
  private:
    class node{
      public:
        node *next;
        string data;
    };
    int length;
    node *head;
    node *tail;
}

#endif
