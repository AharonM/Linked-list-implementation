#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>

#include "node.h"
#include "linked_list_exception.h"

using namespace std;

template <typename T>
class LinkedList;

template <typename T>
ostream &operator<<(ostream &os,const LinkedList<T> &obj);


template <typename T>
class LinkedList{
 public:
	friend ostream &operator<< <>(ostream &os,const LinkedList<T> &obj);

	LinkedList() : head(new Node<T>(0, new Node<T>(0))) {} 
	LinkedList(const LinkedList &obj);
	LinkedList &operator=(const LinkedList &obj);
	~LinkedList();
	void insert(Node<T> *&nodeP, const T &val);
	T remove(Node<T> *p);
	bool remove(const T &val);
	int size();
	void clear();
	bool isEmpty(){if (size() == 0) return true; return false;}
 private:
 	Node<T> *copyNodes(Node<T> *head) const;
	Node<T> *head;
};

#endif
