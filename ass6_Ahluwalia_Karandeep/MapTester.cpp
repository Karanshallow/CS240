#include "map.h"
#include <string>
#include <iostream>
#include <assert.h>
using namespace std;


bool TestConstructor(string& str6);
//Used to Test copy constructor and default constructor
bool TestOperator(Map& map);
//Test Equal operator
bool TestAdd(Map& map, string*& temp,string& str1,string& str2,string& str3,string& str4);
//Tests add function
bool TestSameKey(Map& map,string& str5);
//Tests to see if program rejects a pair with same key
bool TestEmpty(Map& map);
//Tests if program is empty
int TestSize(Map& map);
//Checks size of the program
bool TestFind(Map& map);
//Tests find method of map
bool TestRemove(Map& map);
//Tests remove method of the map
void MethodOrganizer();
//Runs all the different tests
bool TestRetrieve(Map& map,string*& temp);
//Tests the retrieve method of the map
int main(){
  MethodOrganizer();
}

bool TestConstructor(string& str6){
  Map map;
  pair<int, string*> p6 = {7, &str6};
  map.add(p6);
  cout<<"Key in map being copied: 7  Value: "<<str6<<endl;
  Map newmap(map);
  newmap.displayAll();
  return true;
}

bool TestOperator(Map& map){
  Map newmap;
  map = newmap;
   return (map.size() ==0);
}

bool TestAdd(Map& map, string*& temp,string& str1,string& str2,string& str3,string& str4){
  temp = &str1;
  pair<int, string*> p1 = {0, &str1};
  pair<int, string*> p2 = {5, &str2};
  pair<int, string*> p3 = {2, &str3};
  pair<int, string*> p4 = {3, &str4};

  return (map.add(p1)&&map.add(p2)&&map.add(p3)&&map.add(p4));
}

bool TestSameKey(Map& map,string& str5){
pair<int, string*> p5 = {2, &str5};
  return !map.add(p5);
}

bool TestEmpty(Map& map){
  return map.empty();
}

int TestSize(Map& map){
  return map.size();
}

bool TestFind(Map& map){
  return map.find(3);
  }

bool TestRemove(Map& map){
  return map.remove(3);
}
bool TestRetrieve(Map& map,string*& temp){
  return (temp == map.retrieve(0));
}
void MethodOrganizer(){
  string* temp;
  string str1  = "Hope";
  string str2  = "that";
  string str3  = "this";
  string str4 = "works";
  string str5  = "Shouldnt add";
  string str6  = "Copy";
  cout<<"Testing copy constructor"<<endl;
  TestConstructor(str6);
  Map map;
  if (TestEmpty(map)){
    cout<<"The empty functions works on an empty map"<<endl;
    if (TestSize(map)==0){
      cout<<"The size functions works on an empty map"<<endl;
      cout<<"Displaying items before adding"<<endl;
      map.displayAll();
      if (TestAdd(map,temp,str1,str2,str3,str4)){
        cout<<"Adding three items"<<endl;
        map.displayAll();
        if(TestSameKey(map,str5)){
          cout<<"Rejected adding item with same key"<<endl;
          if(TestRetrieve(map,temp)){
            cout<<"Retrieve works"<<endl;

          }else{
            cout<<"Temp:"<<temp<<"     retrieve:"<<map.retrieve(0)<<endl;
          }
          if(TestFind(map)){
            cout<<"Find function works on item in list"<<endl;
            map.displayAll();
            if(TestRemove(map)){
              cout<<"Removing key 3"<<endl;
              map.displayAll();
              if(TestSize(map)==3){
                cout<<"Size function works on nonempty list"<<endl;
                if(TestEmpty(map)==false){
                  cout<<"Empty funciton works on nonempty list"<<endl;
                  map.displayAll();
                  cout<<"Removing key 3 which is not in map"<<endl;
                  if(TestRemove(map)==false){
                    map.displayAll();
                    if(TestFind(map)==false){
                      cout<<"Find function returned false for a key not in list"<<endl;
                      if(TestOperator(map)){
                        cout<<"Replacing map with new map"<<endl;
                        map.displayAll();
                        cout<<"Testing destructor"<<endl;
                      }else{
                        cout<<"Check operator"<<endl;
                      }
                    }else{
                      cout<<"Check find fucnction"<<endl;
                    }
                  }else{
                    cout<<"Check Remove"<<endl;
                  }
                }else{
                  cout<<"Empty has failed"<<endl;
                }
              }else{
                cout<<"Second Size has failed"<<map.size()<<endl;
              }
            }else{
              cout<<"Remove failed"<<endl;
            }
          }else{
            cout<<"Find has failed"<<endl;
          }
        }else{
          cout<<"Test SameKey has failed"<<endl;
        }
      }else{
        cout<<"Add has failed"<<endl;
      }
    }else{
      cout<<"First size has falied"<<endl;
    }
  }else{
    cout<<"Empty has falied"<<endl;
  }
}

//bool TestRetrieve(Map& map);
