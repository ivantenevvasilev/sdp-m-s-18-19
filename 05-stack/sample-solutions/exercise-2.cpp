#include <iostream>

#include "CharStack.h"

int f(int x, int y, int z) {
   return (x + 2 * y + 3 * z) % 10;
}

int g(int x, int y, int z) {
   return (2 * x + 3 * y + 7 * z) % 10;
}

char parse_expression(const char * line) {
   CharStack stack;
   while (*line != '\0') { 
     if ((*line >= '0' && *line <= '9') || *line == 'g' || *line == 'f') {
       stack.push(*line);
     }
     if (*line == ')') {
         char z = stack.pop();
         char y = stack.pop();
         char x = stack.pop();
         z -= '0';
         y -= '0';
         x -= '0';
         char op = stack.pop();
         char result;
         if (op == 'f') {
            result = f(x, y, z);
         } else if (op == 'g') {
            result = g(x, y, z);
         }
         result += '0';
         stack.push(result);
     }
     ++line;
   }
   return stack.top();
}

int main() {
  std::cout << parse_expression("9") << std::endl;
  std::cout << parse_expression("f(g(1,2,3),4,f(5,6,7))") << std::endl;
  std::cout << parse_expression("f(1,g(2,3,4),f(5,6,7))") << std::endl;

  return 0;
}
