#include "llistint.h"
#include <cstdlib>
#include <iostream>


LListInt::LListInt()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

LListInt::~LListInt()
{
  clear();
}

/**
   * Copy constructor
   */
LListInt::LListInt(const LListInt& other)
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;

  Item* temp = new Item();
  temp = other.head_;
  while( temp != NULL ){
    this->push_back(temp->val);
    temp = temp->next;
  }
}

/**
   * Assignment Operator
   */
LListInt& LListInt::operator=(const LListInt& other)
{
	Item* temp = new Item();
	temp = other.head_;
	while( temp != NULL ){
    	this->push_back(temp->val);
		temp = temp->next;
	}
	return *this;
}

/**
   * Adds an item to the back of the list in O(1) time
   */
void LListInt::push_back(const int& val)
{
  int last = size_;
  insert(size_, val);
}



bool LListInt::empty() const
{
  return size_ == 0;
}


int LListInt::size() const
{
  return size_;
}

/**
 * Complete the following function
 */
void LListInt::insert(int loc, const int& val)
{
  if( loc < 0 || loc > size_ ){
    return;
  }

  if( head_ == NULL ){
      Item* firstItem = new Item();
      head_ = firstItem;
      head_->val = val;
      head_->next = NULL;
      head_->prev = NULL;
      tail_ = head_;
      size_++;
      return;
  } else if ( loc == 0 && head_ != NULL ){
      Item* temp = new Item();
      temp->val = val;
      temp->next = head_;
      temp->prev = NULL;
      head_->prev = temp;
      tail_ = temp->next;
      head_ = temp;
      size_++;
      return;
  } else if ( size_ == 1 || (size_ == loc) ){
      Item* prevItem = getNodeAt(loc-1);
      Item* temp = new Item();
      temp->val = val;
      temp->next = NULL;
      temp->prev = prevItem;
      prevItem->next = temp;
      tail_ = temp;
      size_++;
      return;    
  } else {
      Item* prevItem = getNodeAt(loc-1);
      Item* nextItem = getNodeAt(loc);
      Item* temp = new Item();
      temp->val = val;
      temp->prev = prevItem;
      temp->next = nextItem;
      prevItem->next = temp;
      nextItem->prev = temp;
      nextItem->next = NULL;
      size_++;
    }


}

/**
   * Removes the value at index, pos
   */
void LListInt::remove(int loc)
{
  if( loc < 0 || loc >= size_ ){
    return;
  }

  if( loc == 0 ){
    Item* newHead = getNodeAt(loc+1);
    head_ = newHead;
    size_--;
    return;
  } else if( loc == (size_-1) ){
      Item* prevItem = getNodeAt(loc-1);
      prevItem->next = NULL;
      tail_ = prevItem;
      size_--;
      return;
  } else {
      Item* prevItem = getNodeAt(loc-1);
      Item* nextItem = getNodeAt(loc);
      prevItem->next = nextItem;
      nextItem->prev = prevItem;
      size_--;
      return;
    }
 

}

void LListInt::set(int loc, const int& val)
{
  Item *temp = getNodeAt(loc);
  temp->val = val;
}

int& LListInt::get(int loc)
{
  Item *temp = getNodeAt(loc);
  return temp->val;
}

int const & LListInt::get(int loc) const
{
  Item *temp = getNodeAt(loc);
  return temp->val;
}

void LListInt::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}


LListInt::Item* LListInt::getNodeAt(int loc) const
{
  Item *temp = head_;
  if(loc >= 0 && loc < size_){
    while(temp != NULL && loc > 0){
      temp = temp->next;
      loc--;
    }
    return temp;
  }
  else {
    //throw std::invalid_argument("bad location");
    return NULL;
  }
}