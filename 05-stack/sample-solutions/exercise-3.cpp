#include <iostream>

#include "CharStack.h"

bool is_letter(char c) {
  return  (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool is_valid_xml(const char * text) {
  CharStack stack;
  while (*text) {
     if (*text == '<' && is_letter(*(text + 1)) && *(text + 2) == '>') {
        stack.push(*(text + 1));
     }
     if(*text == '<' && *(text + 1) == '/' && *(text + 3) == '>') {
         if (stack.is_empty()) {
            return false;
         }
         char letter = *(text + 2);
         char last_tag_letter = stack.pop();
         if (letter != last_tag_letter) {
            return false;
         }
     }
     ++text;
  }
  return stack.is_empty();
}

int main() {
   std::cout << is_valid_xml("<a>    <b> <d>     whitespace doesn't matter       </d>    </b> but makes things more readable    <c>                             </a> -- <a> is closed before <c>, but <a> contains <c>    </c> ") << std::endl;
   std::cout << is_valid_xml("<a> <b> <d> whitespace doesn't matter </d> </b> but makes things more readable <c> </c> -- <a> is never closed") << std::endl;
   std::cout << is_valid_xml("<b></b></a>") << std::endl;
   std::cout << is_valid_xml("<a>   <b> <d>     whitespace doesn't matter       </d>   </b> but makes things more readable   <c>   </c>           </a>") << std::endl;
   return 0;
}
