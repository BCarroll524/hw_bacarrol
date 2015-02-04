#include "llistdbl.h"
#include <cstdlib>

LListDbl::LListDbl()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

LListDbl::~LListDbl()
{
  clear();
}

bool LListDbl::empty() const
{
  return size_ == 0;
}

int LListDbl::size() const
{
  return size_;
}

/**
 * Complete the following function
 */
void LListDbl::insert(int loc, const double& val)
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
      size_++;
      return;
  } else if ( loc == 0 && head_ != NULL ){
      Item* temp = new Item();
      temp->val = val;
      temp->next = head_;
      temp->prev = NULL;
      head_->prev = temp;
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
void LListDbl::remove(int loc)
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

void LListDbl::set(int loc, const double& val)
{
  Item *temp = getNodeAt(loc);
  temp->val = val;
}

double& LListDbl::get(int loc)
{
  Item *temp = getNodeAt(loc);
  return temp->val;
}

double const & LListDbl::get(int loc) const
{
  Item *temp = getNodeAt(loc);
  return temp->val;
}

void LListDbl::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}


LListDbl::Item* LListDbl::getNodeAt(int loc) const
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
