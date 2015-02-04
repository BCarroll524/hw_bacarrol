#include "stackdbl.h"
#include <iostream>

using namespace std;

int main()
{
  
  StackDbl * list = new StackDbl();
  

  // Check if the list is initially empty.
  if (list->empty()) {
    cout << "SUCCESS: List is empty initially." << endl;
  } else {
    cout << "FAIL: List is not empty initially when it should be." << endl;
  }

  //insert an item into the list at the top
  list->push(10);
  list->push(20);
  list->push(30);
  list->push(40);


  // Check if the list is still empty.
  if (!list->empty()) {
    cout << "SUCCESS: List is not empty after one insertion." << endl;
  } else {
    cout << "FAIL: List is empty after one insertion." << endl;
  }

  // Check if the value is correct.
  if (list->top() == 10) {
    cout << "SUCCESS: 10 is at the top of the list." << endl;
  } else {
    cout << "FAIL: 10 is not at the top of the list, " << list->top();
    cout << " is instead." << endl;
  }

  //check if the value is correct
  if (list->top() == 40) {
    cout << "SUCCESS: 40 is at the top of the list." << endl;
  } else {
    cout << "FAIL: 40 is not at the top of the list, " << list->top();
    cout << " is instead." << endl;
  }

  list->pop();
  if (list->top() == 30){
  		cout << "SUCCESS: List has removed the top item." << endl;
  } else {
  	cout << "FAIL: List is did not remove the top item. " << list->top();
  	cout << " is at the top of the list" << endl;
  }


  delete list;

}