#ifndef TEMPLATED_DOUBLY_LINKED_LIST_H
#define TEMPLATED_DOUBLY_LINKED_LIST_H

#include <cstdlib>
#include <iostream>
#include <stdexcept>

using namespace std;

template <class T> class DoublyLinkedList; // class declaration

// list node
template <class T> class DListNode {
private:
  T obj;
  DListNode<T> *prev, *next;
  friend class DoublyLinkedList<T>;
public:
  DListNode(DListNode<T> *p = nullptr, DListNode<T> *n = nullptr)
    : prev(p), next(n) {}
  DListNode(T e, DListNode<T> *p = nullptr, DListNode<T> *n = nullptr)
    : obj(e), prev(p), next(n) {} 
  T getElem() const { return obj; }
  DListNode<T> * getNext() const { return next; }
  DListNode<T> * getPrev() const { return prev; }
};

// doubly linked list
template <class T> class DoublyLinkedList {
protected:
  DListNode<T> header, trailer;
public:
  DoublyLinkedList() : // constructor
    header(0), trailer(0) 
  { header.next = &trailer; trailer.prev = &header; }
  DoublyLinkedList(const DoublyLinkedList<T>& dll); // copy constructor //O(n)
  ~DoublyLinkedList(); // destructor
  DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>& dll); // assignment operator //O(n)
  // return the pointer to the first node
  DListNode<T> *getFirst() const { return header.next; }
  // return the pointer to the trailer
  const DListNode<T> *getAfterLast() const { return &trailer; }
  // check if the list is empty
  bool isEmpty() const { return header.next == &trailer; }
  T first() const; // return the first object //O(1)
  T last() const; // return the last object 
  void insertFirst(T newobj); // insert to the first of the list //O(1)
  T removeFirst(); // remove the first node //O(1)
  T removeAll();
  void insertLast(T newobj); // insert to the last of the list 
  T removeLast(); // remove the last node 
};
// output operator
template <class T> ostream& operator<<(ostream& out, const DoublyLinkedList<T>& dll); //O(n)

// extend range_error from <stdexcept>
struct EmptyDLinkedListException : std::range_error {
  explicit EmptyDLinkedListException(char const* msg=NULL): range_error(msg) {}
};

// copy constructor //O(n)
template <class T> DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& dll)
{
  // Initialize the list
  header.next = &trailer; // # operations: 1
  trailer.prev = &header; // # operations: 1
  
  // Copy from dll
  DListNode<T>* head = dll.getFirst(); // # operations: 2
  const DListNode<T>* tail = dll.getAfterLast(); // # operations: 2
  DListNode<T>* node = head; // # operations: 1
  while(node != tail) { // # total operations: 4n
	insertLast(node->obj); // # operations: 3n
	node = node->next; // # operations: n
  }
}

// assignment operator //O(n)
template <class T> DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& dll)
{
  DListNode<T>* head = dll.getFirst(); // # operations: 2
  const DListNode<T>* tail = dll.getAfterLast(); // # operations: 2
  DListNode<T>* node = head; // # operations: 1
  while(node != tail) { // # total operations: 4n
	insertLast(node->obj); // # operations: 3n
	node = node->next; // # operations: n
  }
  return *this; // # operations: 1
}

// insert the object to the first of the linked list //O(1)
template <class T> void DoublyLinkedList<T>::insertFirst(T newobj)
{ 
  DListNode<T> *newNode = new DListNode<T>(newobj, &header, header.next); // # operations: 2
  header.next->prev = newNode; // # operations: 1
  header.next = newNode; // # operations: 1
}

// insert the object to the last of the linked list 
template <class T> void DoublyLinkedList<T>::insertLast(T newobj)
{
  DListNode<T> *newNode = new DListNode<T>(newobj, trailer.prev,&trailer); 
  trailer.prev->next = newNode;
  trailer.prev = newNode;
}

// remove the first object of the list //O(1)
template <class T> T DoublyLinkedList<T>::removeFirst()
{ 
  if (isEmpty()) // # total operations: 1
    throw EmptyDLinkedListException("Empty Doubly Linked List"); // # operations: 1
  DListNode<T> *node = header.next; // # operations: 1
  node->next->prev = &header; // # operations: 1
  header.next = node->next; // # operations: 1
  T obj = node->obj; // # operations: 1
  delete node; // # operations: 1
  return obj; // # operations: 1
}

// remove the last object of the list 
template <class T> T DoublyLinkedList<T>::removeLast()
{
  if (isEmpty())
    throw EmptyDLinkedListException("Empty Doubly Linked List");
  DListNode<T> *node = trailer.prev;
  node->prev->next = &trailer;
  trailer.prev = node->prev;
  T obj = node->obj;
  delete node;
  return obj;
}

template <class T> T DoublyLinkedList<T>::removeAll()
{ 
	if(header.next == trailer.prev) {
		header.next = NULL;
		trailer.prev = NULL;
	}
	DListNode<T> *node;
	while(header.next != NULL) {
		node = header.next;
		header.next = header.next->next;
		delete node;
	}
	trailer.prev = NULL;
}

// destructor 
template <class T> DoublyLinkedList<T>::~DoublyLinkedList()
{
  DListNode<T> *prev_node, *node = header.next;
  while (node != &trailer) { 
    prev_node = node;
    node = node->next;
    delete prev_node;
  }
  header.next = &trailer;
  trailer.prev = &header;
}

// return the first object //O(1)
template <class T> T DoublyLinkedList<T>::first() const
{ 
  if (isEmpty()) // # total operations: 1
    throw EmptyDLinkedListException("Empty Doubly Linked List"); // # operations: 1
  
  return header.next->obj; // # operations: 1
}

// return the last object
template <class T> T DoublyLinkedList<T>::last() const
{
  if (isEmpty())
    throw EmptyDLinkedListException("Empty Doubly Linked List");
  
  return trailer.prev->obj;
}

// output operator //O(n)
template <class T> ostream& operator<<(ostream& out, const DoublyLinkedList<T>& dll)
{
  if(dll.getFirst() == NULL) // # total operations: 1
	  return out << "{}"; // # operations: 1
  DListNode<T> *node = dll.getFirst(); // # operations: 2
  out << "{"; // # operations: 1
  while(node != dll.getAfterLast()) { // # total operations: 5n
	  out << node->getElem(); // # operations: 2n
	  node = node->getNext(); // # operations: 2n
	  if(node != dll.getAfterLast()) // # total operations: n
		  out << " "; // # operations: n
  }
  out << "}"; // # operations: 1
  return out; // # operations: 1
}

#endif