#ifndef NODE_H
#define NODE_H

#include <iostream>

template <typename T>
struct Node {
	friend std::ostream &operator <<(std::ostream &os, const Node<T> &node) {
		os <<'[' <<"Prev: "<< node.prev << " Current: " << node.data <<" Next: " << node.next << ']';
		return os;
	}
	Node(const T &data=0, Node<T> *next=NULL, Node<T> *prev=NULL) : data(data), next(next), prev(prev) {}
	T data;
	Node<T> *next, *prev;
};

#endif

