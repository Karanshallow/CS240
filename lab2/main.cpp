// program to test the behavior of the ItemToPurchase class
#include <iostream>
#include "ItemToPurchase.h"
using namespace std;

int main() {
   string name;
   double price;
   int quantity;
   double total;

   cout << "Item 1 " << endl;
   cout << "Enter the item name:" << endl;
   cin >> name;
     
   cout << "Enter the item price:" << endl;
   cin >> price;
     
   cout << "Enter the item quantity:" << endl;
   cin >> quantity;
   
   cout << endl;
   
   ItemToPurchase item1 (name, price, quantity);
   
   cout << "Item 2 " << endl;
   cout << "Enter the item name:" << endl;
   cin >> name;     
   cout << "Enter the item price:" << endl;
   cin >> price;
     
   cout << "Enter the item quantity:" << endl;
   cin >> quantity;
   cout << endl;
   
   ItemToPurchase item2;
   item2.SetName(name);
   item2.SetPrice(price);
   item2.SetQuantity(quantity);
   
   cout << "TOTAL COST" << endl;    
   cout << item1 << endl;
   cout << item2 << endl;
   
   total = (item1.GetPrice() * item1.GetQuantity()) + 
       (item2.GetPrice() * item2.GetQuantity());
          
   cout << endl;
   cout << "Total: $" << total << endl;
      
   
   return 0;
}

