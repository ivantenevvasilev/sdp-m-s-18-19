#include <iostream>
#include <cassert>

using namespace std;

template <typename T>
struct Node{
	T item;             // информационна част
	Node<T>* next;      // адресна част
};

template <typename T>
class List {
public:
	// канонично представяне
	List();
	~List();
	List(const List&);
	List& operator=(const List&);
	// основни функции
	bool empty() const;
	void iterStart(Node<T>* = NULL);
	Node<T>* iter();
	void toEnd(const T&);
	void insertAfter(Node<T>*, const T&);
	void insertBefore(Node<T>*, const T&);
	void deleteAfter(Node<T>*, T&);
	void deleteBefore(Node<T>*, T&);
	void deleteElem(Node<T>*, T&);
	void print() const;
	int length() const;
	void concat(const List&);
	void reverse();
private:
	Node<T> *start;		// указател към началото
	Node<T> *end;		// указател към края
	Node<T> *current;	// указател към текущ елемент

	// помощни функции
	void copyList(const List&);
	void deleteList();
};

template <typename T>
List<T>::List() {
	start = end = NULL;
}

template <typename T>
List<T>::~List() {
	deleteList();
}

template <typename T>
List<T>::List(const List<T>& r) {
	copyList(r);
}
template <typename T>
List<T>& List<T>::operator=(const List<T>& r) {
	if (this != &r) {
		deleteList();
		copyList(r);
	}
	return *this;
}

template <typename T>
void List<T>::copyList(const List<T>& r) {
	start = end = NULL;
	Node<T> *p = r.start;
	while (p) {
		toEnd(p->item);
		p = p->next;
	}
}

template <typename T>
void List<T>::deleteList() {
	Node<T> *p;
	while (start) {
		p = start;
		start = start->next;
		delete p;
	}
	end = NULL;
}

template <typename T>
void List<T>::iterStart(Node<T> *p) {
	if (p) current = p;
	else current = start;
}

template <typename T>
Node<T>* List<T>::iter() {
	Node<T> *p = current;
	if (current) current = current->next;

	return p;
}

template <typename T>
void List<T>::toEnd(const T& x) {
	Node<T>* p = end;
	end = new Node<T>;
	assert(end != NULL);
	end->item = x;
	end->next = NULL;
	if (p) p->next = end;
	else start = end;
}

template <typename T>
void List<T>::insertAfter(Node<T>* p, const T& x) {
	Node<T> *q = new Node<T>;
	assert(q != NULL);
	q->item = x;
	q->next = p->next;
	if (p == end) end = q;

	p->next = q;
}

template <typename T>
void List<T>::insertBefore(Node<T>* p, const T& x) {
	Node<T>* q = new Node<T>;
	assert(q != NULL);
	*q = *p;
	if (p == end) end = q;
	p->item = x;
	p->next = q;
}

template <typename T>
void List<T>::deleteAfter(Node<T>* p, T& x) {
	if (p->next) {
		Node<T>* q = p->next;
		x = q->item;
		p->next = q->next;
		if (q == end) end = p;
		delete q;
	}
	else {
		cout << "There is not an element after p.\n";
		exit(1);
	}
}

template <typename T>
void List<T>::deleteElem(Node<T>* p, T& x) {
	if (p == start) {
		x = p->item;
		if (start == end) {
			start = end = NULL;
		}
		else start = start->next;
		delete p;
	}
	else {
		Node<T>* q = start;
		while (q->next != p) q = q->next;

		deleteAfter(q, x);
	}
}

template <typename T>
void List<T>::deleteBefore(Node<T>* p, T& x) {
	if (p != start) {
		Node<T>* q = start;
		while (q->next != p) q = q->next;

		deleteElem(q, x);
	}
	else {
		cout << "There is no element before p.\n";
		exit(1);
	}
}

template <typename T>
bool List<T>::empty() const {
	return start == NULL;
}

template <typename T>
void List<T>::print() const {
	Node<T> *p = start;
	while (p) {
		cout << p->item << " ";
		p = p->next;
	}
	cout << endl;
}

template <typename T>
int List<T>::length() const {
	int n = 0;
	Node<T> *p = start;
	while (p) {
		n++;
		p = p->next;
	}
	return n;
}

template <typename T>
void List<T>::concat(const List<T>& r) {
	Node<T> *p = r.start;
	while (p) {
		toEnd(p->item);
		p = p->next;
	}
}

template <typename T>
void List<T>::reverse() {
	List<T> r;
	Node<T>* p = start;
	if (p) {
		r.toEnd(p->item);
		p = p->next;
		while (p) {
			r.insertBefore(r.start, p->item);
			p = p->next;
		}
	}
	*this = r;
}


template <typename T>
bool is_arithmetic_progression(List<T>& list) {
  list.iterStart(); // Позиционираме указателят current в началото
  Node<T> * first = list.iter();
  if (first == NULL) {
     return true;
  }
  Node<T> * second = list.iter();
  if (second == NULL) {
     return true;
  }
  
  T differance = second->item - first->item;

  while(second != NULL) {
    if (second->item - first->item != differance) { 
       return false;
    }
    first = second;
    second = list.iter();
  }

  return true;
}

// Задача 2
template <typename T>
bool is_geometric_progression(List<T>& list) {
  list.iterStart(); // Позиционираме указателят current в началото
  Node<T> * first = list.iter();
  if (first == NULL) {
     return true;
  }
  Node<T> * second = list.iter();
  if (second == NULL) {
     return true;
  }
  
  T differance = second->item / first->item;

  while(second != NULL) {
    if (second->item / first->item != differance) { 
       return false;
    }
    first = second;
    second = list.iter();
  }

  return true;
}

// Задача 3
template <typename T>
List<T> generate_arithmetic_progression(int n, T d, T a) {
  List<T> list;
  if (n == 0) {
    return list;
  }
  for (int i = 0; i < n; ++i) {
    list.toEnd(a);
    a += d;
  }
  return list;
}
// Задача 4
template <typename T>
List<T> generate_geometric_progression(int n, T q, T a) {
  List<T> list;
  if (n == 0) {
    return list;
  }
  for (int i = 0; i < n; ++i) {
    list.toEnd(a);
    a *= q;
  }
  return list;
}

// Задача 5
template <typename T>
List<T> merge_lists(List<T>& left, List<T>& right) {
  List<T> result;
  
  left.iterStart();
  right.iterStart();

  Node<T> * left_ptr = left.iter();
  Node<T> * right_ptr = right.iter();

  // Взимаме по-малкият елемент и местим съответният указател
  while (left_ptr != NULL && right_ptr != NULL) {
      if (left_ptr->item < right_ptr->item) {
          result.toEnd(left_ptr->item); 
          left_ptr = left.iter();
      }
      else {
          result.toEnd(right_ptr->item);
          right_ptr = right.iter();
      }
  }
  // На този етап знаем че поне един от двата списъка е свършил
  // Обаче кое от двете - не знаем
  // За това пробваме и двете
  while (left_ptr != NULL) {
     result.toEnd(left_ptr->item);
     left_ptr = left.iter();
  }
  while (right_ptr != NULL) {
     result.toEnd(right_ptr->item);
     right_ptr = right.iter();
  }
  return result;
}

int main() {
  List<double> list;
  list.toEnd(1);
  list.toEnd(3);
  list.toEnd(9);


  List<double> a = generate_arithmetic_progression(5, 5.0, 1.0); 
  
  list.print();
  cout << "\n";
  a.print();
  cout << "\n";
  return 0;
}
