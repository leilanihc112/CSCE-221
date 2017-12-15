#include "RuntimeException.h"
#include "Evaluator.h" 

#include<iostream>
#include<stack>
#include<string>
#include<math.h>

using namespace std;

// Function to verify whether a character is english letter or numeric digit.
// We are assuming in this solution that operand will be a single character
bool IsOperand(char c)
{
	if(c >= '0' && c <= '9') return true;
	if(c >= 'a' && c <= 'z') return true;
	if(c >= 'A' && c <= 'Z') return true;
	return false;
}

// Function to verify whether a character is operator symbol or not.
bool IsOperator(char c)
{
	if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
		return true;

	return false;
}

// Function to verify whether an operator is right associative or not.
int IsRightAssociative(char op)
{
	if(op == '^') return true;
	return false;
}

// Function to get weight of an operator. An operator with higher weight will have higher precedence.
int GetOperatorWeight(char op)
{
	int weight = -1;
	switch(op)
	{
	case '+':
	case '-':
		weight = 1;
	case '*':
	case '/':
		weight = 2;
	case '^':
		weight = 3;
	}
	return weight;
}

// Function to perform an operation and return output.
int HasHigherPrecedence(char op1, char op2)
{
	int op1Weight = GetOperatorWeight(op1);
	int op2Weight = GetOperatorWeight(op2);

	// If operators have equal precedence, return true if they are left associative.
	// return false, if right associative.
	// if operator is left-associative, left one should be given priority.
	if(op1Weight == op2Weight)
	{
		if(IsRightAssociative(op1)) return false;
		else return true;
	}
	return op1Weight > op2Weight ?  true: false;
}

// Function to evaluate Postfix expression and return output
string InfixToPostfix(string expression)
{
	// Declaring a Stack from Standard template library in C++.
	stack<char> s;
	string postfix = ""; // Initialize postfix as empty string.
	for(int i = 0; i< expression.length(); i++) {

		// Scanning each character from left.
		// If character is a delimitter, move on.
		if(expression[i] == ' ' || expression[i] == ',') continue;

		// If character is operator, pop two elements from stack, perform operation and push the result back.
		else if(IsOperator(expression[i]))
		{
			while(!s.empty() && s.top() != '(' && HasHigherPrecedence(s.top(),expression[i]))
			{
				postfix+= s.top();
				s.pop();
			}
			s.push(expression[i]);
		}
		// Else if character is an operand
		else if(IsOperand(expression[i]))
		{
			postfix +=expression[i];
		}

		else if (expression[i] == '(')
		{
			s.push(expression[i]);
		}

		else if(expression[i] == ')')
		{
			while(!s.empty() && s.top() !=  '(') {
				postfix += s.top();
				s.pop();
			}
			s.pop();
		}
	}

	while(!s.empty()) {
		postfix += s.top();
		s.pop();
	}

	return postfix;
}

// Function to verify whether a character is numeric digit. 
bool IsNumericDigit(char C) 
{
	if(C >= '0' && C <= '9') return true;
	return false;
}

// Function to perform an operation and return output. 
int PerformOperation(char operation, int operand1, int operand2)
{
	if(operation == '^') return pow(operand1,operand2);
	else if(operation == '*') return operand1 * operand2;
	else if(operation == '/') return operand1 / operand2;
	else if(operation == '+') return operand1 + operand2;
	else if(operation == '-') return operand1 - operand2;

	else cout<<"Unexpected Error \n";
	return -1; 
}

// Function to evaluate Postfix expression and return output
int EvaluatePostfix(string expression)
{
	// Declaring a Stack from Standard template library in C++. 
	stack<int> s;
	char ch;
	int result;
	stack<char> ops;

	for(int i = 0; i < expression.length(); i++) {
		// Scanning each character from left. 
		// If character is a delimiter, move on. 
		if(expression[i] == ' ' || expression[i] == ',') continue; 

		// If character is operator, pop two elements from stack, perform operation and push the result back. 
		else if(IsOperator(expression[i])) {
			ops.push(expression[i]);
		}
		else if(IsNumericDigit(expression[i])){
			// Extract the numeric operand from the string
			// Keep incrementing i as long as you are getting a numeric digit. 
		int operand = 0; 
		//while(i<expression.length() && IsNumericDigit(expression[i])) {
				// For a number with more than one digits, as we are scanning from left to right. 
				// Everytime , we get a digit towards right, we can multiply current total in operand by 10 
				// and add the new digit. 
				operand = expression[i] - '0'; 
				//i++;
		//}
			// Finally, you will come out of while loop with i set to a non-numeric character or end of string
			// decrement i because it will be incremented in increment section of loop once again. 
			// We do not want to skip the non-numeric character by incrementing i twice. 
		//i--;

			// Push operand on stack. 
			s.push(operand);
		}
		while (!ops.empty() && s.size() >= 2)
		{
			// Pop two operands.
			int operand2 = s.top(); 
			s.pop();
			int operand1 = s.top(); 
			s.pop();
			char op = ops.top(); ops.pop();
			// Apply operator on top of 'ops' to top two elements in values stack
			result = PerformOperation(op, operand1, operand2);
			//Push back result of operation on stack.
			s.push(result);
		}
	}
	return(result);
}

int main()
{
	string expression;
	cout << "Enter Infix Expression: ";
	getline(cin,expression);
	string postfix = InfixToPostfix(expression);
	cout << "Postfix: " << postfix << "\n";
	int result = EvaluatePostfix(postfix);
	cout<< "Evaluation: " << result << "\n";
}