#include "circle.h"


Circle::Circle(){
  cout<<"Circle created"<<endl;
}

void Circle::addFriend(string name1,string name2){
  circle.addEdge(name1,name2);
}
void Circle::addPerson(string name1){
  //cout<<"Can get here"<<endl;
  circle.addVertex(name1);
}
void Circle::listMembers() const{
  int counter = 1;
  cout<<"Members:"<<endl;
  for (string el:circle.retrieveVertex()){
    cout<<counter<<".  "<<el<<endl;
    counter++;
  }
}
void Circle::numMembers() const{
  cout<<"Number of members is: "<<circle.sizeVertex()<<endl;
}
void Circle::numFriendships() const{
  cout<<"Number of friendships: "<<circle.sizeEdge()<<endl;
}
bool Circle::nameExists(string& str) const{
  if (circle.findVertex(str)){
    cout<<"Name does exists"<<endl;
    return true;
  }else{
    cout<<"Name does not exist"<<endl;
    return false;
  }
}
void Circle::namePred(string& str) const{
  int counter = 1;
  cout<<"Members that call "<<str<<" a friend are:"<<endl;
  for (string el:circle.predcessors(str)){
    cout<<counter<<".  "<<el<<endl;
    counter++;
  }
}
void Circle::isFriend(string& name1,string& name2) const{
  if(circle.findEdge(name1,name2)){
    cout<<"Yes there is a friendship from "<<name1<<" to "<<name2<<endl;
  }else{
    cout<<"No there is no friendship from "<<name1<<" to "<<name2<<endl;
  }
}
void Circle::removeFriend(string& name1, string& name2){
  if(circle.removeEdge(name1,name2)){
    cout<<"Friendship removed"<<endl;
  }else{
    cout<<"Names are invalid"<<endl;
  }
}
void Circle::nameSucc(string& str) const{
  int counter = 1;
  cout<<"Members that "<<str<<" calls a friend are:"<<endl;
  for (string el:circle.successors(str)){
    cout<<counter<<".  "<<el<<endl;
    counter++;
  }
}
void Circle::removePerson(string& str){
  if (circle.findVertex(str)){
    cout<<"Person removed"<<endl;
    circle.removeVertex(str);
  }else{
    cout<<"Cannot find person"<<endl;
  }
}
