#include "llistdbl.h"
#include <iostream>

using namespace std;

int main() {
  LListDbl * list = new LListDbl();

  // Check if the list is initially empty.
  if (list->empty()) {
    cout << "SUCCESS: List is empty initially." << endl;
  } else {
    cout << "FAIL: List is not empty initially when it should be." << endl;
  }

  // Insert an item at the head.
  list->insert(0, 3.3);
  list->insert(0, 2.5);
  list->insert(2, 1.7);
  list->insert(2, 1.8);
 

  // Check if the list is still empty.
  if (!list->empty()) {
    cout << "SUCCESS: List is not empty after one insertion." << endl;
  } else {
    cout << "FAIL: List is empty after one insertion." << endl;
  }

  if (list->size() == 4) {
    cout << "SUCCESS: List has size 4 after two insertions." << endl;
  } else {
    cout << "FAIL: List has size " << list->size() << " after one insertion.";
    cout << endl;
  }

  // Check if the value is correct.
  if (list->get(2) == 1.8) {
    cout << "SUCCESS: 1.8 is at the 2nd index of the list." << endl;
  } else {
    cout << "FAIL: 1.8 is not at the 2nd index of the list, " << list->get(2);
    cout << " is instead." << endl;
  }

  //check if the item at pos, loc, is removed from the list
  list->remove(1);
  if (list->size() == 3){
  		cout << "SUCCESS: List has size 3 after one removal." << endl;
  } else {
  	cout << "FAIL: List has size " << list->size() << " after one removal.";
  	cout << endl;
  }
  

  // Clean up memory.
  delete list;
}