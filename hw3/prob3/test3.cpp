#include <iostream>
// Here we assume Set.h includes Map.h
#include "setint.h"

using namespace std;

int main()
{

  SetInt list;
  SetInt list2;

  if( list.empty() )
  {
    cout << "SUCCESS: List is empty." << endl;
  }

  list.insert(1);
  list.insert(2);
  list.insert(3);
  list.insert(4);

  SetInt list3(list);
  cout << *(list3.first()) << endl;
  cout << *(list3.next()) << endl;
  cout << *(list3.next()) << endl;
  cout << *(list3.next()) << endl;


  list2.insert(5);
  list2.insert(1);
  list2.insert(7);
  list2.insert(8);

  //SetInt * copy = new SetInt(list);

  if( list.size() == 1 ){
    cout << "SUCCESS: List has one item." << endl;
  }  else {
    cout << "FAIL: List is empty." << endl;
  }

  if( list.exists(1) ){
    cout << "SUCCESS: The item is in the list." << endl;
  } else {
    cout << "FAIL: The item is not in the list." << endl;
  }

  //list->remove(1);

  if( list.empty() ){
    cout << "SUCCESS: List has removed one item." << endl;
  } else {
    cout << "FAIL: List still has " << list.size() << " item." << endl;
  }
  

 /* cout << *(list.first()) << endl;
  cout << *(list.next()) << endl;
  cout << *(list.next()) << endl;
  cout << *(list.next()) << endl;
*/
  //int first = *(list.first());
  //cout << first << endl;

 /*SetInt temp;
  temp = list.setIntersection(list2);

  cout << *(temp.first()) << endl;
  /*cout << *(temp.next()) << endl;
  cout << *(temp.next()) << endl;
  cout << *(temp.next()) << endl;
  cout << *(temp.next()) << endl;
  cout << *(temp.next()) << endl;
*/

  return 0;

}