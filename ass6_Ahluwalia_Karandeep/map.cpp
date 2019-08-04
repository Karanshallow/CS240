#include "map.h"
#include <string>
#include <iostream>
#include <assert.h>
using namespace std;


Map::Map(){
  cout<<"Default constructor is called"<<endl;
  head = nullptr;
	length =0;
}
bool Map::empty() const{
  return (length ==0);
}
//input: none
//output: returns true if the Map is empty; else false
//side effects: none
void Map:: operator=(const Map& mapped){
  cout<<"Calling equal operator"<<endl;
  deleteTree(head);
  length = 0;
  if (mapped.head!=nullptr){
    node *b = new node;
    head = b;
    copyHelper(b,mapped.head);
  }else{
    head = nullptr;
  }
  //cout<<"Tree got deleted"<<endl;
  //cout<<mapped.head->data.first<<endl;
  //cout<<"Operator does work"<<endl;
}

int Map::size() const{
  return length;
}
//input: none
//output: returns the number of elements in the Map
//side effects: none

bool Map::add(ElementType element){
  if(find(element.first)){
    return false;
  }else{
    node*p = new node;
    p->data = element;
    p->right = nullptr;
    p->left = nullptr;
  if (head==nullptr){
    head = p;
  }else{
    node* a = head;
    node* b;
    while(a!=nullptr){
      b = a;
      if(element.first<a->data.first){
        a = a->left;
      }else{
        a = a->right;
      }
    }
    if(element.first<=b->data.first){
      b->left = p;
    }else{
      b->right = p;
    }
  }
  length++;
  return true;
}
}
//input: an element (key and its associated value)
//output: returns true if the key-value pair was 				     	//        added; else false(the key was found)
//side effects: Map has one more element (if addition      		     	//              done)

bool Map::find(KeyType key) const{
  node *a = head;
  while(a != nullptr){
    if (key == a->data.first){
      return true;
    }else{
      if(key<a->data.first){
        a = a->left;
      }else{
        a = a->right;
      }
    }
  }
  return false;
}
ValueType Map::retrieve(KeyType key) const{
  node *a = head;
  while(a != nullptr){
    if (key == a->data.first){
      return a->data.second;
    }else{
      if(key<a->data.first){
        a = a->left;
      }else{
        a = a->right;
      }
    }
  }
  return NULL;
}

//input: a key
//output: returns the value associated with key (a 			//        null pointer if the key was not found)
//side effects: none

bool Map::remove(KeyType key){
//currently have it set to find not remove
if (find(key)){
  length--;
  node* a = head;
  bool left = false;
  node* b= nullptr;
  while(a != nullptr){
    if (key == a->data.first){
      if(a->left==nullptr && a->right==nullptr){
        if(left){
          b->left = nullptr;
        }else{
          b->right = nullptr;
        }
//       delete a->data.second;
        delete a;
        return true;
      }else if(a->left!=nullptr&&a->right !=nullptr){
        node* c =a->right;
        if(c->left!=nullptr){
          node *d = c->left;
          node* e = c;
          while(d->left!=nullptr){
            e = d;
            d = d->left;

          }
          e->left = d->right;
          if (left){
            b->left = d;
          }else{
            b->right = d;
          }
          d->right = c;
          d->left = a->left;
  //        delete a->data.second;
          delete a;
          return true;
        }else{
          if(left){
            b->left = c;
          }else{
            b->right = c;
          }
          c->left = a->left;
//          delete a->data.second;
          delete a;
          return true;
        }

      }else if(a->left!=nullptr){
        if(left){
          b->left = a->left;
        }else{
          b->right = a->left;
        }
//        delete a->data.second;
        delete a;
        return true;
      }else{
        if(left){
          b->left = a->right;
        }else{
          b->right = a->right;
        }
        delete a->data.second;
        delete a;
        return true;
      }
    }else{
      b = a;
      if(key<a->data.first){
        a = a->left;
        left = true;
      }else{
        left = false;
        a = a->right;
      }
    }
  }
}else{
  return false;
}
}
Map::Map(const Map & mapped){
  cout<<"Copy constructor is called"<<endl;
  length=0;
  if (mapped.head!=nullptr){
    node *b = new node;
    head = b;
    copyHelper(head,mapped.head);
  }else{
    head = nullptr;
  }

}
Map::~Map(){
  cout<<"Map destructor called"<<endl;
  length = 0;
  deleteTree(head);

}
void Map::displayAll() const{
  displayer(head);
}

void Map::deleteTree(node* p){
  if (p!= nullptr){
    deleteTree(p->left);
    deleteTree(p->right);
//    delete p->data.second;
    delete p;
  }
}
void Map::copyHelper(node* newhead,node* oldhead){
//  cout<<"Copy helper gets called"<<endl;
  //cout<<oldhead->data.first<<endl;
  newhead->data = oldhead->data;
  length++;
  //cout<<"Nothing here"<<endl;
//  cout<<newhead->data.first<<endl;
  if(oldhead->left!=nullptr){
      //cout<<"Going left"<<endl;
      node *p = new node;
      newhead->left = p;
      copyHelper(p,oldhead->left);
  }else{
    newhead->left = nullptr;
  }
  if(oldhead->right!=nullptr){
    //cout<<"Going right"<<endl;
      node *b = new node;
      newhead->right = b;
      copyHelper(b,oldhead->right);
  }else{
    newhead->right = nullptr;
  }
}
void Map::displayer(node* p) const{
  if (p!= nullptr){
    displayer(p->left);
    cout<<"This is the key: "<<p->data.first<<" This is the val: ";
    string* s =p->data.second;
    cout<<*s<<endl;
    displayer(p->right);
  }
}
  //input: a key
//output: returns true if item is removed;
//        else false (key not found)
//side effects: Map has one less element (if remove 			//              done)
//void map::displayAll() const;
  // write contents of the Map to cout
