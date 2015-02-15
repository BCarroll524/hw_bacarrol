#include "setint.h"
#include <cstdlib>
#include <iostream>

using namespace std;



SetInt::SetInt()
{

}

SetInt::~SetInt()
{
	list_.clear();
}

/**
	copy constructor
*/

SetInt::SetInt(const SetInt& other)
{
	if( this != &other )
	{
		for( int j = 0; j < this->size(); j++)
		{
			this->remove( list_.get(j) );
		}
		int size = other.size();
		for( int i = 0; i < size; i++ )
		{
			this->insert( other.list_.get(i) );
		}
	}	

}

/**
   * Returns the current number of items in the list 
   */
int SetInt::size() const
{
	return list_.size();
}


  /**
   * Returns true if the list is empty, false otherwise
   */
bool SetInt::empty() const
{
	return list_.empty();
}


  /**
   * Inserts val so it appears at index, pos
   */
void SetInt::insert(const int& val)
{
	for( int i = 0; i < list_.size(); i++ ){
		if( list_.get(i) == val ){
			return;
		}
	}
	list_.push_back(val);

	/*if(iterator > 1)
	{
		iterator = 1;
	}*/
}


  /**
   * Removes the value at index, pos
   */
void SetInt::remove(const int& val)
{
	for( int i = 0; i < list_.size(); i++ ){
		if( list_.get(i) == val ){
			list_.remove(i);
		}
	}

	if(iterator > 1){
		iterator = 1;
	}
}


  /**
   * Returns true if the item is in the set
   */
bool SetInt::exists(const int& val) const
{
	for( int i = 0; i < list_.size(); i++ ){
		if( list_.get(i) == val ){
			return true;
		}
	}
	return false;
}


  /**
   * Return a pointer to the first item
   *  and support future calls to next()
   */
int const* SetInt::first()
{
	if( list_.empty() ){
		return NULL;

		
	}
	iterator = 1;
	return &(list_.get(iterator-1));

}

/**
   * Return a pointer to the next item
   *  after the previous call to next
   *  and NULL if you reach the end
   */
int const* SetInt::next()
{
	if( list_.size() == iterator ){
		return NULL;
	}
	iterator++;
	return &(list_.get(iterator-1));
}

  /**
   * Returns another (new) set that contains
   * the union of this set and "other"
   */
SetInt SetInt::setUnion(const SetInt& other) const
{
	SetInt tempSet;
	int size1 = this->size();
	int size2 = other.size();
	for(int i = 0; i < size1; i++)
	{
		tempSet.insert( this->list_.get(i) );
	}
	for (int i = 0; i < size2; i++)
	{
		
		tempSet.insert( other.list_.get(i));
	}

	return tempSet;
}

  /**
   * Returns another (new) set that contains
   * the intersection of this set and "other"
   */
SetInt SetInt::setIntersection(const SetInt& other) const
{
	SetInt tempSet;
	int size1 = this->size();
	int size2 = other.size();
	for(int i = 0; i < size1; i++)
	{
		int item = this->list_.get(i);

		for(int j = 0; j < size2; j++)
		{
			if( other.exists(item) )
			{
				tempSet.insert(item);
			}
		}
	}

	return tempSet;
}

SetInt SetInt::operator|(const SetInt& other) const
{
	SetInt tempSet;
	int size1 = this->size();
	int size2 = other.size();
	for(int i = 0; i < size1; i++)
	{
		int item = this->list_.get(i);

		for(int j = 0; j < size2; j++)
		{
			if( other.exists(item) )
			{
				tempSet.insert(item);
			}
		}
	}

	return tempSet;
}

SetInt SetInt::operator&(const SetInt& other) const
{
	SetInt tempSet;
	int size1 = this->size();
	int size2 = other.size();
	for(int i = 0; i < size1; i++)
	{
		tempSet.insert( this->list_.get(i) );
	}
	for (int i = 0; i < size2; i++)
	{
		
		tempSet.insert( other.list_.get(i));
	}

	return tempSet;
}


