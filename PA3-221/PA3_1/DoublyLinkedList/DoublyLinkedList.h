//programming assignment 3

#include <cstdlib>
#include <iostream>

using namespace std;

class DoublyLinkedList; // class declaration

// list node
class DListNode {
private:
  int obj;
  DListNode *prev, *next;
  friend class DoublyLinkedList;
public:
  DListNode(int e=0, DListNode *p = nullptr, DListNode *n = nullptr)
    : obj(e), prev(p), next(n) {}
  int getElem() const { return obj; }
  DListNode * getNext() const { return next; }
  DListNode * getPrev() const { return prev; }
};

// doubly linked list
class DoublyLinkedList {
protected:
  DListNode header, trailer;
public:
  DoublyLinkedList() : // constructor
    header(0), trailer(0) 
  { header.next = &trailer; trailer.prev = &header; }
  DoublyLinkedList(const DoublyLinkedList& dll); // copy constructor //O(n)
  ~DoublyLinkedList();
  DoublyLinkedList& operator=(const DoublyLinkedList& dll); // assignment operator //O(n)
  // return the pointer to the first node
  DListNode *getFirst() const { return header.next; } 
  // return the pointer to the trailer
  const DListNode *getAfterLast() const { return &trailer; } 
  // check if the list is empty
  bool isEmpty() const { return header.next == &trailer; } 
  int first() const; // return the first object //O(1)
  int last() const; // return the last object 
  void insertFirst(int newobj); // insert to the first of the list //O(1)
  int removeFirst(); // remove the first node //O(1)
  void insertLast(int newobj); // insert to the last of the list 
  int removeLast(); // remove the last node 
};
// output operator
ostream& operator<<(ostream& out, const DoublyLinkedList& dll); //O(n)

// extend range_error from <stdexcept>
struct EmptyDLinkedListException : std::range_error {
  explicit EmptyDLinkedListException(char const* msg=NULL): range_error(msg) {}
};