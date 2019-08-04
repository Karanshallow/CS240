#include "Stack.h"
#import <string>
#import <vector>
#import <iostream>
#import<ofstream>
using namespace std;


ifstream getFileInput();
//input: user input
//output: ifstream of file
void runFileCommands(ifstream& fileInput,vector& sarray,vector& darray);
//input: stream fileInput, Linked List class
//output: none
//side effects: responsible for managing updating cart as per requests
void updateVector(string& line,vector & sarray,vector& darray);

void outputfile(vector & sarray,vector& darray);

double evaluate(string line);

int main(){
  vector<string> stringArr;
  vector<double> doubleArr;
  ifstream myfile(getFileInput());
  runFileCommands(myfile,stringArr,doubleArr);
  return 0;
}
ifstream getFileInput(){
    cout<<"Enter file name: "<<endl;
    string test;
    getline(cin,test);
    ifstream myfile(test);
    return myfile;
}
void runFileCommands(ifstream& fileInput,vector& sarray,vector& darray){
  string line;
  if(myfile.is_open()){
    while(getline(myfile,line)){
      updateVector(line,sarray,darray)
    }
    outputfile(sarray,darray)
    }
  }
}
void updateVector(string& line,vector & sarray,vector& darray){
  sarray.pushback(line);
  darray.pushback(evaluate(line));
}

void outputfile(vector & sarray,vector& darray){
ofstream out;
out("output.txt");
for(int i =0;i<vector.size();i++){
    string words;
    istringstream iss(sarray.at(i));
    while(iss>>words){
      out<<words<<" ";
    }
    out<<"is "<<darray.at(i)<<endl;
  }
}

double evaluate(string line){
  Stack numbers;
  Stack operations;
  string subs;
  istringstream iss(line);
  while(iss>>subs){
    istringstream stream(subs);
    double dtemp =0.0;
    char ctemp = '.';
    if(stream>>dtemp){
      numbers.Push(dtemp);
    }else{
        operations.Push(ctemp);
    }
  }


}
