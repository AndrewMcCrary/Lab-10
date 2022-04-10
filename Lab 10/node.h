#pragma once

template<class T>
struct node {
	T* value;
	bool deleted;

	bool operator==(const node& n) { return *(this->value) == *(n->value); }
};