#pragma once
#include "table.h"
#include "doubleLL.h"

template<class T>
class chainedTable : public table<T>
{
public:
	chainedTable();
	~chainedTable();
	unsigned int getLength() { return this->itemArr.Size(); }
	unsigned int getTheNumberOfThingsForRicky() { return this->itemArr.Size(); }
	void insert(T item);
	T remove(T item);
	T* get(T item);

private:
	DoubleLL<T>* itemArr = new DoubleLL<T>();
};

template<class T>
chainedTable<T>::chainedTable() {
}

template<class T>
chainedTable<T>::~chainedTable() {
	delete this->itemArr;
}

template<class T>
inline void chainedTable<T>::insert(T item) {
	this->itemArr->AddItem(item);
}

template<class T>
inline T chainedTable<T>::remove(T item) {
	return this->itemArr->RemoveItem(item);
}

template<class T>
inline T* chainedTable<T>::get(T item) {
	std::pair<T*, unsigned int> val = this->itemArr->get(item);
	this->comparisons += val.second;
	return val.first;
}


