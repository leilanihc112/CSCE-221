#ifndef EVALUATOR_H
#define EVALUATOR_H

#include "Parser.h"
#include "LinkedQueue.h"
#include "LinkedStack.h"
#include "RuntimeException.h"

class Evaluator {
public:
  class DivisionByZeroException : public RuntimeException {
    public:
      DivisionByZeroException() : RuntimeException("Division by zero") {}
  };
private:
  /* declare member variables;
    may include a string postfix queue and a double value stack */

  /* declare utility functions */

public:
  Evaluator(Parser& par) {} // constructor
  double getValue(); // returns the result of expression evaluation
};

#endif