#pragma once
#include "Part.h"
#include "LLNode.h"

template <typename T>
class DoubleLL
{
public:
	DoubleLL() {};
	DoubleLL(Node<T>* start);
	~DoubleLL();
	void AddItem(T* var);
	T* GetItem(T var);
	Part* GetItem(int SKU);
	bool IsInList(int sku);
	bool IsInList(T var);
	bool IsEmpty();
	int Size();
	T* SeeNext();
	T* SeePrev();
	T* SeeAt(int var);
	void Reset();
private:
	Node<T>* current = nullptr;
	Node<T>* head = nullptr;
};

template<typename T>
inline DoubleLL<T>::DoubleLL(Node<T>* head)
{
	this->head = head;
	this->Reset();
}

template<typename T>
inline DoubleLL<T>::~DoubleLL()
{
	while (this->head != nullptr) {
		this->current = this->head->Next;
		delete this->head;
		this->head = this->current;
	}
}

template<typename T>
inline void DoubleLL<T>::AddItem(T* var)
{
	if (this->IsEmpty())
		this->head = new Node<T>(var);
	else if (this->head->data > var->data) {
		this->head->Prev = var;
		var->Next = this->head;
		this->head = var;
	}
	else {
		Node<T>* temp = this->head;
		while (temp != nullptr) {
			if (temp->getValue() > var->getValue()) {
				var->Prev = temp->Prev;
				var->Next = temp;
				temp->Prev->Next = var;
				temp->Prev = var;
				return;
			}

			temp = temp->Next;
		}
	}
}

template<typename T>
inline T* DoubleLL<T>::GetItem(T var)
{
	Node<T>* temp = this->head;
	while (temp != nullptr) {
		if (*(temp->data) == var)
			return temp->data;
		temp = temp->Next;
	}
	return nullptr;
}

inline Part* DoubleLL<Part>::GetItem(int SKU)
{
	Node<Part>* temp = this->head;
	while (temp != nullptr) {
		if (temp->data->getSKU() == SKU)
			return temp->data;
		temp = temp->next;
	}
	return nullptr;
}

template<typename T>
inline bool DoubleLL<T>::IsInList(T var)
{
	Node<T>* temp = this->head;
	while (temp != nullptr) {
		if (temp->data == var)
			return true;
		temp = temp->Next;
	}
	return false;
}

inline bool DoubleLL<Part>::IsInList(int sku)
{
	Node<Part>* temp = this->head;
	while (temp != nullptr) {
		if (temp->data->getSKU() == sku)
			return true;
		temp = temp->next;
	}
	return false;
}

template<typename T>
inline bool DoubleLL<T>::IsEmpty()
{
	return this->head == nullptr;
}

template<typename T>
inline int DoubleLL<T>::Size()
{
	Node<T>* temp = this->head;
	int i = 0;
	while (temp != nullptr) {
		i++;
		temp = temp->next;
	}
	return i;
}

template<typename T>
inline T* DoubleLL<T>::SeeNext()
{
	this->current = this->current->next;
	return current->data;
}

template<typename T>
inline T* DoubleLL<T>::SeePrev()
{
	this->current = this->current->prev;
	return this->current->data;
}

template<typename T>
inline T* DoubleLL<T>::SeeAt(int var)
{
	if (this->Size() >= var)
		return nullptr;

	Node<T>* temp = this->head;
	for (int i = 0; i < var; i++)
		temp = temp->next;

	return temp->data;
}

template<typename T>
inline void DoubleLL<T>::Reset()
{
	this->current = this->head;
}
