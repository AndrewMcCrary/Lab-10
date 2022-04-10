#pragma once

template<class T>
struct node {
	~node();
	T* value;
	bool deleted;
};

template<class T>
inline node<T>::~node() {
	delete this->value;
}
