#include "llistint.h"
#include <iostream>

using namespace std;

int main() {
  LListInt * copy = new LListInt();

 

  // Insert an item at the head.
 
  for(int i = 0; i < 5; i++){
    copy->push_back(i);
  }

  

 LListInt * list = copy;

  // Check if the list is initially empty.

  if (copy->empty()) {
    cout << "SUCCESS: List is empty initially." << endl;
  } else {
    cout << "FAIL: List is not empty initially when it should be." << endl;
  }

  for(int i = 0; i < list->size(); i++)
  {
    cout << "index " << i << " = " << list->get(i) << endl;
  }
 

  // Check if the list is still empty.
  if (!list->empty()) {
    cout << "SUCCESS: List is not empty after one insertion." << endl;
  } else {
    cout << "FAIL: List is empty after one insertion." << endl;
  }

  if (list->size() == 5) {
    cout << "SUCCESS: List has size 5 after five insertions." << endl;
  } else {
    cout << "FAIL: List has size " << list->size() << " after five insertions.";
    cout << endl;
  }

  // Check if the value is correct.
  if (list->get(0) == 0) {
    cout << "SUCCESS: 6 is at the 0th index of the list." << endl;
  } else {
    cout << "FAIL: 6 is not at the 0th index of the list, " << list->get(0);
    cout << " is instead." << endl;
  }

  //check if the item at pos, loc, is removed from the list
  list->remove(1);
  if (list->size() == 4){
  		cout << "SUCCESS: List has size 4 after one removal." << endl;
  } else {
  	cout << "FAIL: List has size " << list->size() << " after one removal.";
  	cout << endl;
  }
  

  // Clean up memory.
  delete list;
}