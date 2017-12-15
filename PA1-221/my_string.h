//Leilani Horlander-Cruz
//CSCE 221-506
//2-1-17
//my_string.h

#include <iostream>

//using namespace std;

class my_string {
	private:
		char* ptr; //pointer to dynamic array of type char
		int sz; //number of characters in string
		int cap; //length in bytes of allocated memory pointed to by ptr
	public:
		my_string(); //default constructor creates an empty string without any memory allocation
		my_string(int n); //constructor with int argument n creates empty string with allocated memory of size n bytes
		my_string(const char* s); //constructor with C-string creates string with content taken from C-string
		my_string(const my_string &s); //copy constructor makes copy of argument string
		~my_string(); //destructor deallocates allocated memory and makes empty string
		int size() const; //returns number of characters of object s
		int capacity() const; //returns length in bites of allocated memory
		bool empty(); //returns true if string s is empty and false otherwise
		char& at(int i); //returns character at index i of s, with performing arrays bounds checking
//		my_string& insert(int i, my_string &s); //inserts string s before position i in s and returns a reference to the resulting string
		char& operator[](int i); //returns character at index i of s, without performing arrays bounds checking
		my_string& operator+=(const my_string &q); //appends string q to s
		my_string& operator+=(char c); //appends character c to s
		my_string& operator = (const my_string &s); //copy assignment assigns string to another string
	friend std::istream& operator >> (std::istream& is, my_string &s); //reads input to s
	friend std::ostream& operator << (std::ostream& os, my_string &s); //prints content of string
};