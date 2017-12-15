// LinkedStack.h

#ifndef LINKEDSTACK_H_
#define LINKEDSTACK_H_

#include <iostream>
#include "RuntimeException.h"
#include "TemplatedDoublyLinkedList.h"

template<typename T> class LinkedStack;

template<typename T>
std::ostream& operator<<(std::ostream& out, const LinkedStack<T>& stack);
    
template<typename T>
class LinkedStack
{
private:
  DoublyLinkedList<T> dll;
  
public:
   // user-defined exceptions
   class StackEmptyException : public RuntimeException {
   public:
     StackEmptyException() : RuntimeException("Stack is empty") {}
   };
   
    LinkedStack() { } // default constructor
	~LinkedStack() { dll.removeAll(); } // destructor
	LinkedStack(const LinkedStack& stack) : dll(stack.dll) {  } // copy constructor   // O(n)
	LinkedStack& operator=(const LinkedStack& stack); // assignment operator
	bool isEmpty() const { return dll.isEmpty(); }
	T size() const { return dll.size(); }  // O(1)
	string top() const throw(StackEmptyException);
	void push(const string elem) { dll.insertFirst(elem); }   // O(1)
	string pop() throw(StackEmptyException);
};

// O(n)
template<typename T> LinkedStack<T>& LinkedStack<T>::operator=(const LinkedStack& stack)
{
	LinkedStack<T> s(stack);
	LinkedStack<T> t;
	for(T i = 0; i < stack.size(); ++i)
		t.push(s.pop());
	for(T i = 0; i < stack.size(); ++i)
		push(t.pop());
	return *this;
}

// O(1)
template<typename T> string LinkedStack<T>::top() const throw(StackEmptyException)
{
	if(dll.isEmpty())
		throw StackEmptyException();
	return dll.first();
}

// O(1)
template<typename T> string LinkedStack<T>::pop() throw(StackEmptyException)
{
	if(dll.isEmpty())
		throw StackEmptyException();
	return dll.removeFirst();
}

//O(n)
template<typename T>
std::ostream& operator<<(std::ostream& out, const LinkedStack<T>& stack)
{
	if(stack.isEmpty())
		return out << "{}";
	LinkedStack<T> s(stack);
	out << '{';
	for(T i = 0; i < stack.size(); ++i) {
		if(i != 0)
			out << ' ';
		out << s.pop();
	}
	return out << '}';
}

#endif
