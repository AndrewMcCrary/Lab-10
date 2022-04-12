#pragma once
#include <string>

template<class T>
class table
{
private:
	unsigned int length = 0;
	unsigned int theNumberOfThings = 0;
	int currentSpot = 0;
	T* itemArr;
protected:
	int hash(std::string str);
	std::hash<std::string> hasher;
public:
	table(unsigned int length = 100);
	~table();
	void insert(T item);
	T remove(T item);
	T* get(T item);
	unsigned int getLength() { return this->length; }
	unsigned int getTheNumberOfThingsForRicky() { return this->theNumberOfThings; }
	unsigned int getTheCurrentSpotForRicky() { return this->currentSpot; }
	void setTheCurrentSpotForRicky(unsigned int newVal) { currentSpot = newVal; }
	T getTheCurrentItemForRicky() { return itemArr[currentSpot]; }
	unsigned int getTheNextSpotForRicky();
	unsigned int getThePrevSpotForRicky();
	int comparisons = 0;
};

template<class T>
inline int table<T>::hash(std::string str)
{
	std::hash<std::string> hasher;
	return (int)hasher(str);
}

template<class T>
inline table<T>::table(unsigned int length) {
	this->itemArr = new T[length];
	this->length = length;
	for (int i = 0; i < length; i++)
		this->itemArr[i] = (T)INT_MIN;
}

template<class T>
inline table<T>::~table() {
	delete[] this->itemArr;
}

template<class T>
inline void table<T>::insert(T item) {
	if (this->theNumberOfThings >= this->length)
		throw "The table is full.";

	int index = (unsigned int)this->hasher(item) % this->length;

	if (itemArr[index] == (T)INT_MIN) {
		itemArr[index] = item;
	}
	else {
		while (!(itemArr[index] == (T)INT_MIN))
			++index %= this->length;
		itemArr[index] = item;
	}
	this->theNumberOfThings++;
}

template<class T>
inline T table<T>::remove(T item)
{
	if (!this->theNumberOfThings)
		throw "The table is empty.";
	int spot = hash(item);
    while (!(this->itemArr[spot] == (T)INT_MIN) && !(this->itemArr[spot] == item))
		++spot %= this->length;
    
	this->theNumberOfThings--;
	T ret = this->itemArr[spot];
    itemArr[spot] = (T)INT_MIN;
	return ret;
}

template<class T>
inline T* table<T>::get(T item)
{
	int spot = ((unsigned int)this->hasher(item)) % this->length;
    while (!(itemArr[spot] == (T)INT_MIN) && !(itemArr[spot] == item)) {
		this->comparisons++;
		++spot %= this->length;
	}

	this->comparisons++;
	if (itemArr[spot] == (T)INT_MIN)
		return nullptr;
	else
		return &itemArr[spot]; //check for not found
}

template<class T>
inline unsigned int table<T>::getTheNextSpotForRicky()
{
	int spot = this->getTheCurrentSpotForRicky() + 1;
	while (itemArr[spot] == (T)INT_MIN)
		++spot %= this->length;
	return spot;
}

template<class T>
inline unsigned int table<T>::getThePrevSpotForRicky()
{
	int spot = this->getTheCurrentSpotForRicky() - 1;
	while (itemArr[spot] == (T)INT_MIN)
		--spot %= this->length;
	return spot;
}

