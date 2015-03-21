#include <iostream>
#include "node.h"
#include "linkedlist.h"
#include "linkedlist.cpp"
#include "linked_list_exception.h"

using namespace std;

int main(){
	
	LinkedList<int> li;
	
	cout << "size: " << li.size() << endl;
	cout << "li.isEmpty: ";
	if(li.isEmpty() == true)
	cout<< "true" << endl;
	
	Node<int> *p = new Node<int>(0);
	li.insert(p,5);
	li.insert(p,10);
	li.insert(p,15);
	li.insert(p,20);
	li.insert(p,25);
	
	cout <<"li: "<< li <<endl;
	cout << "size: " << li.size() << endl;
	cout << "li.isEmpty: ";
		if(li.isEmpty() == true)
	cout<< "true" << endl;
	else
	cout<< "false" << endl;
	
	//li.remove(p);
	//cout <<"li: "<< li << endl;
	
	
	li.remove(15);
	cout <<"li: "<< li << endl;
	cout << "size: " << li.size() << endl;


	
	LinkedList<int> liG = li;
	cout << "After liG = li: " << endl;
	cout << "li: " << li << endl;
	
	LinkedList<int> liK;
	cout << "After LinkedList<int> liK: " << endl;
	cout << "liK: " << liK << endl;

}
