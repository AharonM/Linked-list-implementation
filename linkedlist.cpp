#include "linkedlist.h"
#include <iostream>

using namespace std;

template <typename T>
ostream &operator<<(ostream &os,const LinkedList<T> &obj){
	os << "{";
	Node<T> *p = obj.head;
	p = p->next->next;
	while (p) {
		os << p->data << (p->next ? ", " : "");
		p = p->next;
	}
	os << "}";
	return os;
}


template <typename T>
LinkedList<T>::LinkedList(const LinkedList &other) {head = copyNodes(other.head);}

template <typename T>
LinkedList<T>::~LinkedList() {clear();}

template <typename T>
LinkedList<T> &LinkedList<T>::operator =(const LinkedList &rhs) {
	if (this == &rhs) return *this;
	clear();
	head = copyNodes(rhs.head);
	return *this;
}


template <typename T>
void LinkedList<T>::insert(Node<T> *&nodeP, const T &val) {
	if (!nodeP) throw LinkedListException("Attempting to insert after NULL");
	Node<T> *newNodeP = new Node<T>(val, nodeP->next, nodeP);
	Node<T> *p = new Node<T>(0, head->next);
	Node<T> *q = p;
	while (p != NULL && p->next != NULL) {
	       q = p;
	       p = p->next;
	}
	p->next = newNodeP;
	p->prev = q;
}



template <typename T>
T LinkedList<T>::remove(Node<T> *p){
	if (!p) throw LinkedListException("Attempting to remove after NULL");
	if (!p->next) throw LinkedListException("Attempting to remove nonexistent node");
	T data = p->data;
	if(head == p)
	head = p->next;

	Node<T> *prev = p->prev;
	Node<T> *next = p->next;
 
	prev->next = next;
	next->prev = prev;

	delete p;
	return data;
}



template <typename T>
bool LinkedList<T>::remove(const T &val){
	if(val == 0) throw "Data is invalid";
	Node<T> *p = head;
	Node<T> *q = new Node<T>(0);
	while(p->data != val && p != NULL ){
		q = p;
		p = p->next;
	}
	if (p == 0) return false;
	
	if (q == 0){
	Node<T> *hold = head;
	head = head->next;
	delete hold;
	return true;}
	else{
	Node<T> *hold = q->next;
	q->next = hold->next;
	if(q->next == NULL){
	q->next = head;
	}
	delete hold;
	return true;}
}



template <typename T>
void LinkedList<T>::clear(){
	while(!isEmpty()){
		Node<T> *p = head;
		head = head->next;
		delete p;
	}
	head = 0;
}


template <typename T>
Node<T> *LinkedList<T>::copyNodes(Node<T> *head) const {
	if (!head) return 0;
	return new Node<T>(head->data, copyNodes(head->next)); 
}


template <typename T>
int LinkedList<T>::size(){
	int count = 0;
	Node<T> *p = head->next->next;
	while(p != NULL){
	count++;
	p = p->next;
	}
	return count;
}
