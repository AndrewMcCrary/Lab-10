#pragma once

template <typename T>
class Node
{
public:
	Node(T _data);
	~Node();
	Node* next = nullptr;
	Node* prev = nullptr;
	T* data;
	bool operator==(const Node& n) { return *(this->data)== *(n.data); }
	bool operator>(const Node& n) { return *(this->data)> *(n.data); }
	bool operator<(const Node& n) { return *(this->data) < *(n.data); }
private:
};

template<typename T>
inline Node<T>::Node(T _data) {
	this->data = new T(_data);
}

template<typename T>
inline Node<T>::~Node()
{
	delete this->data;

	if (this->next)
		this->next->prev = this->prev;

	if (this->prev)
		this->prev->next = this->next;
}
