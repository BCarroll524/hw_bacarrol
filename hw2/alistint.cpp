#include "alistint.h"
#include <cstdlib>


/**
   * Default constructor - default to a list of capacity = 10
   */
AListInt::AListInt()
{
	int size_ = 0;
	int capacity_ = 10;
	data_ = new int[10];
}

/**
   * Another constructor - default to a list to the indicated capacity
   */
AListInt::AListInt(int cap)
{
	data_ = new int[cap];
	int size_ = 0;
	int capacity_ = cap;
}

/**
   * Destructor
   */
AListInt::~AListInt()
{

}

/**
   * Returns the current number of items in the list 
   */
int AListInt::size() const
{
	return size_;
}

int AListInt::capacity() const
{
	return capacity_;
}

 /**
  * Returns true if the list is empty, false otherwise
   */
bool AListInt::empty() const
{
	return size_ == 0;
}

/**
   * Inserts val so it appears at index, pos
   */
void AListInt::insert (int pos, const int& val)
{
	if( pos < 0 && pos > capacity_ ){
		return;
	}
	if( size_-1 == capacity_ ){
		resize();
	}
	if( (size_ == 0) || (pos == capacity_) ){
		data_[pos] = val;
		size_++;
	} else {
		for(int i = size_; i > pos; i--){
			data_[i] = data_[i-1];
		}
		data_[pos] = val;
		size_++;
	}
}

  /**
   * Removes the value at index, pos
   */
void AListInt::remove (int pos)
{
	if( pos < 0 || pos > capacity_ ){
		return;
	}
	if( pos == (size_-1) ){
		data_[pos] = data_[pos+1];
		size_--;
	} else {
		for(int i = pos; i < size_; i++){
			data_[i] = data_[i+1];
			size_--;
			return;
		}
	}
}

  /**
   * Overwrites the old value at index, pos, with val
   */
void AListInt::set (int position, const int& val)
{
	data_[position] = val;
}

/**
   * Returns the value at index, pos
   */
int& AListInt::get (int position)
{
	return data_[position];
}

int const & AListInt::get (int position) const
{
	return data_[position];
}

/**
   * Should double the size of the list maintaining its contents
   */
void AListInt::resize()
{
	capacity_ = capacity_*2;
	int* temp = new int[capacity_];
	for(int i = 0; i < size_; i ++){
		temp[i] = data_[i];
	}
	data_ = temp;

}