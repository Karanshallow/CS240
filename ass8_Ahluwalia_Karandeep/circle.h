#ifndef Circle__
#define Circle__

#include "digraph.h"
#import <string>
#import <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <assert.h>
#include <ctime>
#include <cstdlib>
class Circle{
public:
  Circle();
  void addFriend(string name1,string name2);
  void addPerson(string name1);
  void listMembers() const;
  void numMembers() const;
  void numFriendships() const;
  bool nameExists(string& str) const;
  void namePred(string& str) const;
  void isFriend(string& name1,string& str) const;
  void removeFriend(string& name1, string& name2);
  void nameSucc(string& str) const;
  void removePerson(string& str);
private:
  Digraph circle;
};

#endif
