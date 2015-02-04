#include "stackdbl.h"
#include <cstdlib>

StackDbl::StackDbl()
{
	
}

StackDbl::~StackDbl()
{
	list_.clear();
}

/**
   * Returns true if the stack is empty, false otherwise
   */
bool StackDbl::empty() const
{
	return list_.empty();
}

/**
   * Pushes a new value, val, onto the top of the stack
   */
void StackDbl::push (const double& val)
{
	list_.insert(0, val);
}

/**
   * Returns the top value on the stack
   */
double const & StackDbl::top() const
{
	return list_.get(0);
}

/**
   * Removes the top element on the stack
   */
void StackDbl::pop()
{
	list_.remove(0);
}