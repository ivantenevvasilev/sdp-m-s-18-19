#ifndef DEFINE_STACK
#define DEFINE_STACK

class CharStack {
  private:
    char stack[256];
    int index;
  public:
    CharStack();
    
    char top() const;
    void push(const char c);
    char pop();
    bool is_empty() const;
    bool is_full() const;
};

#endif
