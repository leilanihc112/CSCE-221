// programming assignment 3

#include "DoublyLinkedList.h"
#include <stdexcept>

// copy constructor // O(n) // n is number of nodes in linked list
DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& dll)
{
  // Initialize the list
  header.next = &trailer; // # operations: 1
  trailer.prev = &header; // # operations: 1
  
  // Copy from dll
  DListNode* head = dll.getFirst(); // # operations: 2
  const DListNode* tail = dll.getAfterLast(); // # operations: 2
  DListNode* node = head; // # operations: 1
  while(node != tail) { // # total operations: 4n
	insertLast(node->obj); // # operations: 3n
	node = node->next; // # operations: n
  }
}

// assignment operator // O(n)
DoublyLinkedList& DoublyLinkedList::operator=(const DoublyLinkedList& dll)
{
  DListNode* head = dll.getFirst(); // # operations: 2
  const DListNode* tail = dll.getAfterLast(); // # operations: 2
  DListNode* node = head; // # operations: 1
  while(node != tail) { // # total operations: 4n
	insertLast(node->obj); // # operations: 3n
	node = node->next; // # operations: n
  }
  return *this; // # operations: 1
}

// insert the object to the first of the linked list //O(1)
void DoublyLinkedList::insertFirst(int newobj)
{ 
  DListNode *newNode = new DListNode(newobj, &header, header.next); // # operations: 2
  header.next->prev = newNode; // # operations: 1
  header.next = newNode; // # operations: 1
}

// insert the object to the last of the linked list 
void DoublyLinkedList::insertLast(int newobj)
{
  DListNode *newNode = new DListNode(newobj, trailer.prev, &trailer);
  trailer.prev->next = newNode;
  trailer.prev = newNode;
}

// remove the first object of the list //O(1)
int DoublyLinkedList::removeFirst()
{ 
  if (isEmpty()) // # total operations: 1
    throw EmptyDLinkedListException("Empty Doubly Linked List"); // # operations: 1
  DListNode *node = header.next; // # operations: 1
  node->next->prev = &header; // # operations: 1
  header.next = node->next; // # operations: 1
  int obj = node->obj; // # operations: 1
  delete node; // # operations: 1
  return obj; // # operations: 1
}

// remove the last object of the list
int DoublyLinkedList::removeLast()
{
  if (isEmpty())
    throw EmptyDLinkedListException("Empty Doubly Linked List");
  DListNode *node = trailer.prev;
  node->prev->next = &trailer;
  trailer.prev = node->prev;
  int obj = node->obj;
  delete node;
  return obj;
}

// destructor
DoublyLinkedList::~DoublyLinkedList() 
{
  DListNode *prev_node, *node = header.next;
  while (node != &trailer) {
    prev_node = node;
    node = node->next;
    delete prev_node;
  }
  header.next = &trailer;
  trailer.prev = &header;
}

// return the first object
int DoublyLinkedList::first() const //O(1)
{ 
  if (isEmpty()) // # total operations: 1
    throw EmptyDLinkedListException("Empty Doubly Linked List"); // # operations: 1
  
  return header.next->obj; // # operations: 1
}

// return the last object 
int DoublyLinkedList::last() const
{
  if (isEmpty())
    throw EmptyDLinkedListException("Empty Doubly Linked List");
  
  return trailer.prev->obj;
}

// output operator //O(n)
ostream& operator<<(ostream& out, const DoublyLinkedList& dll)
{
  if(dll.getFirst() == NULL) // # total operations: 1
	  return out << "{}"; // # operations: 1
  DListNode *node = dll.getFirst(); // # operations: 2
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