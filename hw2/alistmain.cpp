#include "alistint.h"
#include <iostream>

using namespace std;

int main() 
{
  AListInt * list = new AListInt();

  // Check if the list is initially empty.
  if (list->empty()) {
    cout << "SUCCESS: List is empty initially." << endl;
  } else {
    cout << "FAIL: List is not empty initially when it should be." << endl;
  }

  // Insert an item at the head.
  list->insert(0, 3);
  list->insert(1, 4);
  list->insert(2, 5);
 

  // Check if the list is still empty.
  if (!list->empty()) {
    cout << "SUCCESS: List is not empty after one insertion." << endl;
  } else {
    cout << "FAIL: List is empty after one insertion." << endl;
  }

  if (list->size() == 3) {
    cout << "SUCCESS: List has size 3 after three insertions." << endl;
  } else {
    cout << "FAIL: List has size " << list->size() << " after one insertion.";
    cout << endl;
  }

  // Check if the value is correct.
  if (list->get(0) == 3) {
    cout << "SUCCESS: 3 is at the 0th index of the list." << endl;
  } else {
    cout << "FAIL: 3 is not at the 0th index of the list, " << list->get(0);
    cout << " is instead." << endl;
  }

  //check if the item at pos, loc, is removed from the list
  list->remove(0);
  if (list->size() == 2){
  		cout << "SUCCESS: List has size 2 after one removal." << endl;
  } else {
  	cout << "FAIL: List has size " << list->size() << " after one removal.";
  	cout << endl;
  }
  

  // Clean up memory.
  delete list;
}



