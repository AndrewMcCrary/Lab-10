#pragma once
#include <string>
#include "node.h"

template<class T>
class table
{
private:
	unsigned int length = 0;
	int hash(std::string str);
	unsigned int theNumberOfThings = 0;
	int currentSpot = 0;
	node<T>** itemArr;
public:
	table(unsigned int length = 100);
	~table();
	void addItem(T* item);
	T removeItem(T item);
	T* getItem(T item);
	unsigned int getLength() { return this->length; }
	unsigned int getTheNumberOfThingsForRicky() { return this->theNumberOfThings; }
	unsigned int getTheCurrentSpotForRicky() { return this->currentSpot; }
	void setTheCurrentSpotForRicky(unsigned int newVal) { currentSpot = newVal; }
	T* getTheCurrentItemForRicky() { return itemArr[currentSpot]->value; }
};

template<class T>
inline int table<T>::hash(std::string str)
{
	int i = 0;
	for (int i = 0; i < str.size(); i++)
		i += str[i];

	return i;
}

template<class T>
inline table<T>::table(unsigned int length) {
	this->itemArr = new node<T>*[length];
	this->length = length;
}

template<class T>
inline table<T>::~table() {
	delete this->itemArr;
}

template<class T>
inline void table<T>::addItem(T* item) {
	int index = hash(std::string(*item));

	node<T>* inval = new node<T>{
		item,
		false
	};

	if (itemArr[index] == nullptr) {
		itemArr[index] = inval;
	}
	else {
		while (itemArr[index] != nullptr) {
			index = (index++) % this->length;
		}
		itemArr[index] = inval;
	}
}

template<class T>
inline T table<T>::removeItem(T item)
{
	int spot = hash(item);
    while (itemArr[spot] != nullptr && *(itemArr[spot]->value) != item) {
		spot = (spot + 1) % this->length;
    }
        //check for not found
    itemArr[spot].deleted = true;
    return *(itemArr[spot]->value);
}

template<class T>
inline T* table<T>::getItem(T item)
{
	int spot = hash(item);
    while (itemArr[spot] != nullptr && *(itemArr[spot]->value) != item) {
        spot = (spot + 1) % this->length;
    }
	if (itemArr[spot] == nullptr)
		return nullptr;
	else return itemArr[spot]->value; //check for not found
}

