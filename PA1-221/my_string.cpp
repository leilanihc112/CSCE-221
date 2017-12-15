//Leilani Horlander-Cruz
//CSCE 221-506
//2-1-17
//my_string.cpp

#include "my_string.h"
#include <stdexcept>

using namespace std;

my_string::my_string() //default constructor creates an empty string without any memory allocation
{
	sz = 0;
	cap = 0;
	ptr = new char[1];
	*ptr = NULL;
}

my_string::my_string(int n) //constructor with int argument n creates empty string with allocated memory of size n bytes
{
	sz = n;	
	cap = n;
	ptr = new char[cap+1];
	for (int i = 0; i < sz; i++)
		ptr[i] = ' ';
}

my_string::my_string(const char* s) //constructor with C-string creates string with content taken from C-string
{
	if (sz != 0)
	{
		int d = 0;
		for (int i = 0; i < sizeof(s)-2; i++)
		{
			if (s[i] != NULL)
				d++;
			else
				d = d;
		}
		sz = d;
	}
	cap = sz;
	ptr = new char[cap+1];
	for (int i = 0; i <= sz-1; i++)
		ptr[i] = s[i];
}

my_string::my_string(const my_string &s) //copy constructor makes copy of argument string
{
	sz = s.size();
	cap = sz;
	ptr = new char[cap+1];
	for (int i = 0; i <= sz-1; i++)
		ptr[i] = s.ptr[i];
}

my_string::~my_string() //destructor deallocates allocated memory and makes empty string
{
	delete[] ptr;
	sz = 0;
	cap = sz;
}

int my_string::size() const //returns number of characters of object s
{
	return sz;
}

int my_string::capacity() const //returns length in bites of allocated memory
{
	if (cap >= sz)
		return cap;
	else;
}

bool my_string::empty() //returns true if string s is empty and false otherwise
{
	if (sz == 0 && cap == 0)
		return true;
	else
		return false;
}

char& my_string::at(int i) //returns character at index i of s, with performing arrays bounds checking
{
	if (i < 0 || (i > (sz-1)))
	{
		exit(0);
	}
	else
		return ptr[i];
}

//my_string my_string::insert(int i, my_string &s) //inserts string s before position i in s and returns a reference to the resulting string
//{
//}

char& my_string::operator[](int i) //returns character at index i of s, without performing arrays bounds checking
{
	return ptr[i];
}

my_string& my_string::operator+=(const my_string &q) //appends string q to s
{
	int new_sz = sz + q.sz;
	if (cap < new_sz)
	{	
		if (cap > 0)
			cap = cap*2;
		else 
			cap++;
	}
	if (cap < new_sz)
		cap = cap*2;
	char* new_ptr = new char[cap+1];
	if (sz > 0)
	{
		for (int i = 0; i <= sz-1; i++)
				new_ptr[i] = ptr[i];
	}
	else;
	int p = 0; 
	for (int i = sz; i <= new_sz-1; i++)
	{
		new_ptr[i] = q.ptr[p];
		p++;
	}
	delete[] ptr;
	ptr = new_ptr;
	sz = new_sz;
	return *this;
}

my_string& my_string::operator+=(char c) //appends character c to s
{
	char new_char[2];
	new_char[0] = c;
	new_char[1] = '\0';
	int new_sz = sz + 1;
	if (cap < new_sz)
	{	
		if (cap > 0)
			cap = cap*2;
		else 
			cap++;
	}
	if (cap < new_sz)
		cap = cap*2;
	char* new_ptr = new char[cap+1];
	if (sz > 0)
	{
		for (int i = 0; i <= sz-1; i++)
			new_ptr[i] = ptr[i];
	}
	else;
	int p = 0; 
	for (int i = sz; i <= new_sz-1; i++)
	{
		new_ptr[i] = new_char[p];
		p++;
	}
	delete[] ptr;
	ptr = new_ptr;
	sz = new_sz;
	return *this;
}

my_string& my_string::operator = (const my_string &s) //copy assignment assigns string to another string
{
	if (this == &s)
		return *this;
	delete[] ptr;
	sz = s.sz;
	cap = sz;
	ptr = new char[cap+1];
	for (int i = 0; i <= sz-1; i++)
		ptr[i] = s.ptr[i];
	return *this;
}

istream& operator >> (istream &is, my_string &s) //reads input to s
{
	char temp[1000];
	int size = 0;
	for (int i = 0; i < 1000; i++)
		temp[i] = NULL;
	is >> temp;
	s.sz = sizeof(temp) - 1;
	if (s.ptr != NULL)
		delete[] s.ptr;
	else
		delete s.ptr;
	s.ptr = new char[s.sz+1];
	for (int i = 0; i <= s.sz-1; i++)
	{
		if (temp[i] != NULL)
		{
			s.ptr[i] = temp[i];
			size++;
		}
	}
	s.sz = size;
	return is;
}

ostream& operator << (ostream& os, my_string &s) //prints content of string s
{
	os << s.ptr;
	return os;
}