#pragma once
#include "table.h"


template<class T>
class table
{
private:
	unsigned int length = 0;
	int hash(std::string str);
	unsigned int theNumberOfThings = 0;
	int currentSpot = 0;
	node<T>* itemArr;
public:
	table(unsigned int length = 100);
	~table();
	void addItem(T* item);
	T* removeItem(T item);
	T* getItem(T item);
	unsigned int getLength() { return this->length; }
	unsigned int getTheNumberOfThingsForRicky() { return this->theNumberOfThings; }
	unsigned int getTheCurrentSpotForRicky() { return this->currentSpot; }
	unsigned int setTheCurrentSpotForRicky(unsigned int newVal) { currentSpot = newVal; }
};
