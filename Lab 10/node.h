#pragma once

template<class T>
struct node {
	~node();
	T* value;
	bool deleted;

	bool operator==(const node& n) { return *(this->value) == *(n->value); }
};

template<class T>
inline node<T>::~node() {
	delete this->value;
}
