#include "CharStack.h"

#include <iostream>

CharStack::CharStack() : index(0) {}

char CharStack::pop() {
   if(!is_empty()) {
     char top = stack[index];
     index--;
     return top;
   } else {
     std::cout << "The stack was empty" << std::endl;
     exit(1);
   }
}

void CharStack::push(const char c) {
  if(!is_full()) {
    index++;
    stack[index] = c;
  } else {
    std::cout << "The stack is full" << std::endl;
  }
}

char CharStack::top() const {
  return stack[index];
}

bool CharStack::is_empty() const {
  return index == 0;
}

bool CharStack::is_full() const {
  return index == 255;
}
