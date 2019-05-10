#include <iostream>
#include <stack>

using namespace std;

template <typename T>
struct Node {
  T item;
  Node<T> * next;
};

// Принтиране на списък
template <typename T>
void print_node(Node<T> * start) {
  Node<T> * current = start;
  
  while (current != NULL) {
    cout << current->item << ' ';
    current = current->next;
  }
  cout << '\n';
}

// Задача 1
int sum_node(Node<int> * start) {
  Node<int> * current = start;
  int sum = 0;
  while (current != NULL) {
    sum += current->item;
    current = current->next;
  }
  return sum;
}

// Задача 2
template <typename T>
void replace(Node<T>* start, int n, T item) {
  for (int i = 0; i < n - 1; ++i) {
    if (start == NULL) {
      return;
    }
    start = start->next;
  }
  if (start == NULL) {
    return;
  }
  start->item = item;
}

// Рекурсивно триене на списък
template<typename T>
void delete_node_rec(Node<T> * start) {
  if (start == NULL) {
    return;
  }

  delete_node_rec(start->next);
  delete start;
}

// Итеративно триене на списък
template<typename T>
void delete_node_iter(Node<T> * start) {
  if (start == NULL) {
    return;
  }
  Node<T> * current = start;
  Node<T> * next = start->next;
 
  while (current != NULL) {
    next = current->next;
    delete current;
    current = next;
  }
}

// Триене на списък чрез стек
template<typename T>
void delete_node_stack(Node<T> * start) {
  stack<Node<T> *> st;
  while (start != NULL) {
    st.push(start);
    start = start->next;
  }
  while (!st.empty()) {
    start = st.top();
    st.pop();
    delete start;
  }
}

// Задача 2
template<typename T>
bool remove_first_occurance(Node<T> *& start, T item) {
	if (start == NULL) {
		return false;
	}
  if (start->item == item) { // Това значи че елементът е пъривят 
														 // и трябва да пренасочим да сочи към следващият
  													 // след като бъде изтрит
		Node<T> * temp = start;
    start = start->next;
    delete temp;
		return true;
	} else { // Значи не е първият, ако има такъв и можем нормално 
				   //да търсим елемент.
		Node<T> * current = start;
    Node<T> * next = start->next;
    while (next != NULL) {
			 if (next->item == item) {
					current->next = next->next;
          delete next;	
 				  return true;
			 }

       current = next;
       next = current->next; 	
    }	
	  return false;
  }
	
}


int main () {
  // Създаваме някакъв примерен списък - този е 5->3->4->NULL
  Node<int> * start = new Node<int>; 
  start->item = 5;
  start->next = new Node<int>;
  start->next->item = 3;
  start->next->next = new Node<int>;
  start->next->next->item = 4;
  start->next->next->next = NULL;
  print_node(start);

  replace(start, 2, 10);
   
  print_node(start);
  cout << sum_node(start) << '\n';
  delete_node_stack(start);
  return 0;
}
