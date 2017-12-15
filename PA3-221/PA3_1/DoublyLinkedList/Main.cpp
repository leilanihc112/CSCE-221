// programming assignment 3

#include "DoublyLinkedList.h"
#include <iostream>

using namespace std;

int main ()
try {
  // Construct a linked list with header & trailer
  cout << "Create a new list" << endl;
  DoublyLinkedList dll;
  cout << "list: " << dll << endl << endl;
  
  // Insert 10 nodes at the end with value 10,20,30,..,100
  cout << "Insert 10 nodes at tail with value 10,20,30,..,100" << endl;
  for (int i=10;i<=100;i+=10) {
    dll.insertLast(i);
  }
  cout << "list: " << dll << endl << endl;

  // Insert 10 nodes at the beginninhg with value 10,20,30,..,100
  cout << "Insert 10 nodes at front with value 10,20,30,..,100" << endl;
  for (int i=10;i<=100;i+=10) {
    dll.insertFirst(i);
  }
  cout << "list: " << dll << endl << endl;
  
  // Copy to a new list
  cout << "Copy to a new list" << endl;
  DoublyLinkedList dll2(dll);
  cout << "list2: " << dll2 << endl << endl;
  
  // Assign to another new list
  cout << "Assign to another new list" << endl;
  DoublyLinkedList dll3;
  dll3=dll;
  cout << "list3: " << dll3 << endl << endl;
  
  // Delete the last 5 nodes
  cout << "Delete the last 5 nodes" << endl;
  for (int i=0; i < 5; i++) {
    dll.removeLast();
  }
  cout << "list: " << dll << endl << endl;
  
  // Delete the first 5 nodes
  cout << "Delete the first 5 nodes" << endl;
  for (int i=0; i<5; i++) {
    dll.removeFirst();
  }
  cout << "list: " << dll << endl << endl;
  
  // Check the other two lists
  cout << "Make sure the other two lists are not affected." << endl;
  cout << "list2: " << dll2 << endl;
  cout << "list3: " << dll3 << endl;
  
  return 0;
}
 catch (EmptyDLinkedListException& e) {
   cout << e.what() << endl;
 }
 catch (...) {
   cout << "uncaught exception...\n";
 }
