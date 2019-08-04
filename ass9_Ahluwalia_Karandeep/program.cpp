#include "circle.h"
#include "digraph.h"
#import <string>
#import <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <assert.h>
#include <ctime>
#include <cstdlib>
using namespace std;

void displayMenu(string& str);

void Choice1(Circle& circle);

void Choice2(Circle& circle);

void Choice3(Circle& circle);

void Choice4(Circle& circle);

void Choice5(Circle& circle);

void Choice6(Circle& circle);

void Choice7(Circle& circle);

void Choice8(Circle& circle);

void Choice9(Circle& circle);

void runProgram(Circle& circle);

void fillCircle(Circle& circle);

int main(){
  Circle circle;
  //cout<<"Reaches line 32"<<endl;
  fillCircle(circle);
  //cout<<"Reaches line 34"<<endl;
  //runProgram(circle);
  return 0;
}

void displayMenu(string& str){
  cout<<"Welcome to Karandeep's scocial network"<<endl;
  cout<<"Here is your options: Please enter the number 1 through 10 for choices of what you want to do. To exit enter q."<<endl;
  cout<<"1. Who are the members of the circle of friends?"<<endl;
  cout<<"2. Who are the members of the circle of friends?"<<endl;
  cout<<"3. How many friendships are part of the circle of friends?"<<endl;
  cout<<"4. Is name a member of the circle of friends?"<<endl;
  cout<<"5. Who has name designated as a friend?"<<endl;
  cout<<"6. Has name1 designated name2 as a friend?"<<endl;
  cout<<"7. Has name1 been designated by name2 as a friend?"<<endl;
  cout<<"8. Remove name1 as a designated friend of name2?"<<endl;
  cout<<"9. How many people have designated name as a friend?"<<endl;
  cout<<"10. Remove name as a member of the circle of friends"<<endl;
  cout<<"q to quit"<<endl;
  cout<<"What do you choose? Enter here:"<<endl;
  cin>>str;
}

void Choice1(Circle& circle){
  circle.listMembers();
}

void Choice2(Circle& circle){
  circle.numMembers();
}

void Choice3(Circle& circle){
  circle.numFriendships();
}

void Choice4(Circle& circle){
  string input;
  cin>>input;
  circle.nameExists(input);
}

void Choice5(Circle& circle){
  string input;
  cin>>input;
  circle.nameSucc(input);
}

void Choice6(Circle& circle){
  string input;
  string sinput;
  circle.isFriend(input,sinput);
}

void Choice7(Circle& circle){
  string input;
  string sinput;
  circle.isFriend(sinput,input);
}

void Choice8(Circle& circle){
  string input;
  string sinput;
  circle.removeFriend(input,sinput);
}

void Choice9(Circle& circle){
  string input;
  circle.namePred(input);
}
void runProgram(Circle& circle){
  string temp;
  displayMenu(temp);
  while(temp!="q"&&temp!="Q"){
    if (temp=="1"){
      Choice1(circle);
    }else if (temp=="2"){
      Choice2(circle);
    }else if (temp=="3"){
      Choice1(circle);
    }else if (temp=="4"){
      Choice1(circle);
    }else if (temp=="5"){
      Choice1(circle);
    }else if (temp=="6"){
      Choice1(circle);
    }else if (temp=="7"){
      Choice2(circle);
    }else if (temp=="8"){
      Choice1(circle);
    }else if (temp=="9"){
      Choice1(circle);
    }else{
      cout<<"Answer cannot be understood. Try again:"<<endl;
    }
    displayMenu(temp);
  }
  cout<<"Thanks for running the program"<<endl;
  }
void fillCircle(Circle& circle){
  srand(time(0));
  vector<string> names = {"John","Joe","Nate","Kim","Jane","Sally", "Jane", "Jim","Abby","Emily","Katie","Nate","Cass","Dani","Chris"};
  //cout<<"please good be this"<<endl;
  for (string el:names){
    //cout<<el<<endl;
    circle.addPerson(el);
    //cout<<"Fills circle"<<endl;
    for(string elem:names){
      if ((elem!=el)&&(rand()%3==1)){
        circle.addFriend(el,elem);
      }
    }
  }
}
