// LinkedQueue.h

#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

#include <iostream> 
#include "RuntimeException.h"
#include "TemplatedDoublyLinkedList.h"

template<typename T> class LinkedQueue;

template<typename T>
std::ostream& operator<<(std::ostream& out, const LinkedQueue<T>& queue);

template<typename T>
class LinkedQueue {
private:
   DoublyLinkedList<T> dll;

public:
   // user-defined exceptions
  class QueueEmptyException : public RuntimeException {
   public:
     QueueEmptyException() : RuntimeException("Access to an empty queue") {}
   };

    LinkedQueue() {} //constructor
    ~LinkedQueue() {dll.removeAll();} //destructor
    LinkedQueue(const LinkedQueue<T>& queue) : dll(queue.dll) {} //copy constructor
    LinkedQueue<T>& operator=(const LinkedQueue<T>& queue); //assignment operator
	T size() const { return dll.size(); }
	bool isEmpty() const {  return dll.isEmpty(); }
	string first() const throw(QueueEmptyException);
	void enqueue(string elem) { dll.insertLast(elem); }
	string dequeue() throw(QueueEmptyException);
};

//assignment operator // O(n)
template <typename T> LinkedQueue<T>& LinkedQueue<T>::operator=(const LinkedQueue<T>& queue)
{
	LinkedQueue<T> q(queue);
	LinkedQueue<T> r;
	for(T i = 0; i < queue.size(); ++i)
		r.enqueue(q.dequeue());
	for(T i = 0; i < queue.size(); ++i)
		enqueue(r.dequeue());
	return *this;
}

// O(1)
template <typename T> string LinkedQueue<T>::first( ) const throw(QueueEmptyException)
{
	if(dll.isEmpty())
	   throw QueueEmptyException();
	return dll.first();
}

// O(1)
template <typename T> string LinkedQueue<T>::dequeue( ) throw(QueueEmptyException)
{
	if(dll.isEmpty())
	   throw QueueEmptyException();
	return dll.removeFirst();
}

// O(n)
template<typename T>
std::ostream& operator<<(std::ostream& out, const LinkedQueue<T>& queue)
{
  if(queue.isEmpty())
		return out << "{}";
	out << '{';
	LinkedQueue<T> q(queue);
	for(T i = 0; i < queue.size(); ++i) {
		if(i != 0)
			out << ' ';
		out << q.dequeue();
	}
	return out << '}';
}

#endif
