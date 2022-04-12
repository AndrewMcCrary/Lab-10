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
	void AddItem(T var);
	std::pair<T*, unsigned int> get(T var);
	bool IsInList(int sku);
	bool IsInList(T var);
	bool IsEmpty();
	int Size();
	T* SeeNext();
	T* SeePrev();
	T* SeeAt(int var);
	void Reset();
	T RemoveItem(T var);
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
		this->current = this->head->next;
		delete this->head;
		this->head = this->current;
	}
}

template<typename T>
inline void DoubleLL<T>::AddItem(T var)
{
	Node<T>* in = new Node<T>(var);
	if (this->IsEmpty())
		this->head = in;
	else if (this->head->operator>(*in)) {
		in->next = this->head;
		this->head->prev = in;
		this->head = in;
	}
	else {
		this->Reset();
		while (this->current->next && this->current->next->operator<(*in)) {
			this->current = this->current->next;
		}
		
		in->prev = current;
		if (current->next) {
			in->next = current->next;
			current->next->prev = in;
		}
		current->next = in;
	}

	this->Reset();
}

template<typename T>
inline std::pair<T*, unsigned int> DoubleLL<T>::get(T var)
{
	Node<T>* temp = this->head;
	int comparisons = 0;

	while (temp != nullptr) {
		comparisons++;
		if (*(temp->data) == var) {

			return { temp->data, comparisons };
		}
		temp = temp->next;
	}
	return {nullptr, 0};
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
	if (this->Size() <= var)
		return nullptr;

	Node<T>* temp = this->head;
	for (int i = 0; i < var; i++)
		temp = temp->next;

	return temp->data;
}

template<typename T>
inline void DoubleLL<T>::Reset() {
	this->current = this->head;
}

template<typename T>
inline T DoubleLL<T>::RemoveItem(T var) {
	Node<T>* temp = this->head;

	while (temp)
		if (*(temp->data) == var) {
			T ret = *(temp->data);
			delete temp;
			return ret;
		}
		else 
			temp = temp->next;

	return (T)NULL;
}
