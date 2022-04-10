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
	void addItem(T* item);
	T* removeItem(T item);
	T* getItem(T item);

private:
	DoubleLL itemArr;
};

template<class T>
chainedTable<T>::chainedTable() {

}

template<class T>
chainedTable<T>::~chainedTable() {
	delete this->itemArr;
}

template<class T>
inline void chainedTable<T>::addItem(T* item) {
	itemArr.AddItem(item);
}

template<class T>
inline T* chainedTable<T>::removeItem(T item) {
	return nullptr;
}

template<class T>
inline T* chainedTable<T>::getItem(T item) {
	return nullptr;
}


