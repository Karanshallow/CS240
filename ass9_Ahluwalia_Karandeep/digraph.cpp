#include "digraph.h"



Digraph::Digraph(){
  vertices.reserve(20);
  edges.reserve(20);
  vsize =0;
  esize = 0;
}
//Destructor
Digraph::Digraph(const Digraph & mapped){

}
//Copy Constructor
bool Digraph::empty() const{
  return (vsize ==0);
}
//input: none
//output: returns true if the Map is empty; else false
//side effects: none

int Digraph::sizeVertex() const{
  return vsize;
}
//input: none
//output: returns the number of elements in the Map
//side effects: none
int Digraph::sizeEdge() const{
  return esize;
}
//input: none
//output: returns the number of elements in the Map
//side effects: none

bool Digraph::addVertex(string str){
  cout<<"Gets right here"<<endl;
  vertices.push_back(str);
  cout<<"Then fails"<<endl;
  return true;
}
//input: an element (key and its associated value)
//output: returns true if the key-value pair was 				     	//        added; else false(the key was found)
//side effects: Map has one more element (if addition      		     	//              done)
bool Digraph::addEdge(string name1,string name2){
  auto it = find(vertices.begin(),vertices.end(),name1);
  auto other = find(vertices.begin(),vertices.end(),name2);
  if ((it != vertices.end())&& (other !=vertices.end())){
    auto index = distance(vertices.begin(), it);
    auto sindex = distance(vertices.begin(), other);
    edges.at(index).push_back(sindex);
    esize++;
    return true;
  }else{
    return false;
  }
}
//input: an element (key and its associated value)
//output: returns true if the key-value pair was 				     	//        added; else false(the key was found)
//side effects: Map has one more element (if addition      		     	//              done)
bool Digraph::removeEdge(string& name1,string& name2){
  auto it = find(vertices.begin(),vertices.end(),name1);
  auto other = find(vertices.begin(),vertices.end(),name2);
  if ((it != vertices.end())&& (other !=vertices.end())){
    auto index = distance(vertices.begin(), it);
    auto sindex = distance(vertices.begin(), other);
    edges.at(index).remove(sindex);
    esize--;
    return true;
  }else{
    return false;
  }
}
//input: an element (key and its associated value)
//output: returns true if the key-value pair was 				     	//        added; else false(the key was found)
//side effects: Map has one more element (if addition      		     	//              done)

bool Digraph::findEdge(string& name1,string& name2) const{
  auto it = find(vertices.begin(),vertices.end(),name1);
  auto other = find(vertices.begin(),vertices.end(),name2);
  if ((it != vertices.end())&& (other !=vertices.end())){
    auto index = distance(vertices.begin(), it);
    auto sindex = distance(vertices.begin(), other);
    for (int element:edges.at(index)){
      if(element == sindex){
        return true;
      }
      }
      return false;
    }else{
      return false;
    }
    }


//input: a key
//output: return true is an element with this key was 			//        found; else false
//side effects: none
bool Digraph::findVertex(string& name1) const{
  auto it = find(vertices.begin(),vertices.end(),name1);
  if(it!=vertices.end()){
    return true;
  }else{
    return false;
  }
}
//input: a key
//output: return true is an element with this key was 			//        found; else false
//side effects: none

vector<string> Digraph::retrieveVertex() const{
  return vertices;
}
//input: a key
//output: returns the value associated with key (a 			//        null pointer if the key was not found)
//side effects: none

vector<string> Digraph::successors(string& str) const{
  assert(findVertex(str));
  vector<string> returner;
  auto it = find(vertices.begin(),vertices.end(),str);
  auto index = distance(vertices.begin(), it);
  for (int el:edges.at(index)){
    returner.push_back(vertices.at(el));
  }
  return returner;
  //No else on this. WOrk on this later
}



vector<string> Digraph::predcessors(string& str) const{
  vector<string> lister;
  auto it = find(vertices.begin(),vertices.end(),str);
  auto index = distance(vertices.begin(), it);
  int counter = 0;
  for (list<int> edge:edges){
    bool check = false;
    for(int element:edge){
      if (element == index){
        check = true;
      }
    }
    if(check){
      lister.push_back(vertices.at(counter));
    }
    counter++;
  }
  return lister;
}
