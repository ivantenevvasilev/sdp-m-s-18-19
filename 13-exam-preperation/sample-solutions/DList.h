#include <cassert>
#include <iostream>

using namespace std;

#ifndef DEFINE_DLIST_SUCCESS
#define DEFINE_DLIST_SUCCESS

template<class T>
struct DNode {
  DNode<T> * previous;
  DNode<T> * next;
  T item;
};

template <typename T = int>
class DLList
{ public:
// канонично представяне
DLList();
~DLList();
DLList(const DLList&);
DLList& operator=(const DLList&);
// основни функции
bool empty() const;
void iterStart(DNode<T>* = NULL);
void iterEnd (DNode<T>* = NULL);
DNode<T>* iterSucc();
DNode<T>* iterPred();;
void toEnd(const T&);
void toStart(const T&);
void deleteElem(DNode<T>*, T&);
void print() const;
void print_reverse() const;
int length() const;
private:
DNode<T> *start,
// указател към началото
*end,
// указател към края
*currentS,
// итератор към началото
*currentE;
// итератор към края
// помощни член-функции
void copyList(const DLList&);
void deleteList();
};

template <typename T>
DLList<T>::DLList()
{ start = end = NULL;
}

template <typename T>
DLList<T>::~DLList()
{ deleteList();
}

template <typename T>
DLList<T>::DLList(const DLList<T>& r)
{ copyList(r);
}

template <typename T>
DLList<T>& DLList<T>::operator=(const DLList<T>& r)
{ if (this != &r)
{ deleteList();
copyList(r);
}
return *this;
}

template <typename T>
void DLList<T>::copyList(const DLList<T>& r)
{ start = end = NULL;
DNode<T>* p = r.start;
while (p)
{ toEnd(p->item);
p = p->next;
}
}

template <typename T>
void DLList<T>::deleteList()
{ DNode<T>* p = start;
while (p)
{ start = start->next;
delete p;
p = start;
}
end = NULL;
}



template <typename T>
bool DLList<T>::empty() const
{ return start == NULL;
}


template <typename T>
void DLList<T>::iterStart(DNode<T>* p)
{ if (p) currentS = p;
else currentS = start;
}

template <typename T>
DNode<T>* DLList<T>::iterSucc()
{ DNode<T>* p = currentS;
if (currentS) currentS = currentS->next;
return p;
}

template <typename T>
void DLList<T>::iterEnd(DNode<T>* p)
{ if (p) currentE = p;
else currentE = end;
}


template <typename T>
DNode<T>* DLList<T>::iterPred()
{ DNode<T>* p = currentE;
if (currentE) currentE = currentE->previous;
return p;
}

template <typename T>
void DLList<T>::toEnd(const T& x)
{ DNode<T>* p = end;
end = new DNode<T>;
assert(end != NULL);
end->item = x;
end->next = NULL;
if (p) p->next = end;
else start = end;
end->previous = p;
}

template <typename T>
void DLList<T>::toStart(const T& x)
{ DNode<T>* p = start;
start = new DNode<T>;
assert(start != NULL);
start->item = x;
start->previous = NULL;
if (p) p->previous = start;
else end = start;
start->next = p;
}


template <typename T>
void DLList<T>::deleteElem(DNode<T>* p, T& x)
{ x = p->item;
if (start == end) start = end = NULL;
else
if (p == start)
{ start = start->next;
start->previous = NULL;
}else
if (p == end)
{ end = p->previous;
end->next = NULL;
}
else
{ p->previous->next = p->next;
p->next->previous = p->previous;
}
delete p;
}

template <typename T>
void DLList<T>::print() const
{ DNode<T>* p = start;
while (p)
{ cout << p->item << " ";
p = p->next;
}
cout << endl;
}

template <typename T>
void DLList<T>::print_reverse() const
{ DNode<T>* p = end;
while (p)
{ cout << p->item << " ";
p = p->previous;
}
cout << endl;
}

template <typename T>
int DLList<T>::length() const
{ int n = 0;
DNode<T>* p = start;
while (p)
{ n++;
p = p->next;
}
return n;
}

#endif
