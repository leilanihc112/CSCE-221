#ifndef PARSER_H
#define PARSER_H

#include "LinkedStack.h"
#include "LinkedQueue.h"
#include "RuntimeException.h"
#include<iostream>
#include<cstdlib>
#include<string>

class Precedence{
	public: int input, stack;
	Precedence(int i = 0, int s = 0) : input(i), stack(s){};
};

class Parser {
	private:
		enum enumTokens{END, VALUE, LPAREN, RPAREN, EXP, MULT, DIV, PLUS, MINUS};
		static const char* delimiter;
		LinkedStack<string> opStack;
		LinkedQueue<string> postfix;
		char Value;
		const char *tokens;
		static const Precedence precTable[];
		static const char opTable[];

	private:
		enumTokens getToken(int c, enumTokens prevToken = VALUE);
	public:

	// constructor
	Parser(std::string s) : opStack(), postfix() {
		tokens = s.c_str();
		//opStack.push(END);
	}

	// accessor method
	// ? getPostfix() { }

	// operations
	void printInfix() { }
	void printPostfix() { }
};

#endif