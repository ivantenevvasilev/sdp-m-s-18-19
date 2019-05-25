#include <iostream>
#include <cassert>
#include "Queue.h"
#include "List.h"
#include "DList.h"

using namespace std;

bool is_set(List<int>& list) {
	list.iterStart();
	if (list.length() <= 1) {
		return true;
	}

	for (Node<int> * i = list.iter(); i->next; i = i->next) {
		for (Node<int> * k = i->next; k; k = k->next) {
			if (i->item == k->item) {
				return false;
			}
		}
	}
	return true;
}


List<List<int>> get_sets(List<List<int>>& list) {
	 List<List<int>> result;
	list.iterStart();
	Node<List<int>> * current_list = list.iter();
	while (current_list != NULL)
	{
		// Check is set
		if (is_set(current_list->item)) {
			result.toEnd(current_list->item);
		}
		current_list = list.iter();
	}
	return result;
}

bool is_set_of_sets(List<List<int>>& list) {
	list.iterStart();
	Node<List<int>> * current_list = list.iter();
	while (current_list != NULL)
	{
		// Check is set
		if (!is_set(current_list->item)) {
			return false;
		}
		current_list = list.iter();
	}
	return true;
}

bool contains(int element, List<int>& list) {
	list.iterStart();
	Node<int> * start = list.iter();
	while (start != NULL) {
		if (start->item == element) {
			return true;
		}

		start = list.iter();
	}
	return false;
}

bool is_in_intersection(int element, List<List<int>>& M) {
	M.iterStart();
	Node<List<int>> * list_iterator = M.iter();
	while (list_iterator != NULL) {
		if (!contains(element, list_iterator->item)) {
			return false;
		}
		
		list_iterator = M.iter();
	}
	return true;
}

List<int> intersection(List<List<int>>& M) {
	List<int> result;

	M.iterStart();
	Node<List<int>> * start = M.iter();

	if (start == NULL) {
		return result;
	}

	List<int> current_list = start->item;
	current_list.iterStart();

	Node<int> * iterator = current_list.iter();

	
	while (iterator != NULL) {
		if (is_in_intersection(iterator->item, M)) {
			result.toEnd(iterator->item);
		}

		iterator = iterator->next;
	}
	return result;
}

template <class T>
bool contains(Queue<T> queue, T item) {
	T element;
	while (!queue.empty()) {
		queue.pop(element);
		if (element == item) {
			return true;
		}
	}
	return false;
}

bool contains_rec(Queue<int>& queue, int item) {
	if (queue.empty()) {
		return false;
	}
	int current;
	queue.pop(current);
	if (item == current) {
		return true;
	}
	return contains_rec(queue, item);
}


List<int> flatten(List<DLList<int>> D) {
	List<int> result;
	D.iterStart();
	int count = 0;
	Node<DLList<int>> * current_list = D.iter();
	while (current_list != NULL) {
		DLList<int>& dllist = current_list->item;
		if (count % 2 == 0) {
			dllist.iterStart();
			DNode<int> * current_element = dllist.iterSucc();
			while (current_element != NULL) {
				result.toEnd(current_element->item);
				current_element = dllist.iterSucc();
			}
		}
		else {
			dllist.iterEnd();
			DNode<int> * current_element = dllist.iterPred();
			while (current_element != NULL) {
				result.toEnd(current_element->item);
				current_element = dllist.iterPred();
			}
		}

		count++;
		current_list = D.iter();
	}
  return result;
}

int main()
{
	List<int> int_set;
	int_set.toEnd(1);
	int_set.toEnd(2);
	int_set.toEnd(4);
	List<int> int_set_2;
	int_set_2.toEnd(5);
	int_set_2.toEnd(2);
	int_set_2.toEnd(4);
	int_set_2.toEnd(1);


	List<List<int>> set;
	set.toEnd(int_set);
	set.toEnd(int_set_2);
	//std::cout << is_set_of_sets(set);


	List<List<int>> M = get_sets(set);

	Queue<int> queue;
	for (int i = 0; i < 10000; ++i) {
		queue.push(i);
	}
	
	cout << contains_rec(queue, 1000) << '\n';

	List<DLList<int>> D;

  DLList<int> first_normal_list;
  first_normal_list.toEnd(1);
  first_normal_list.toEnd(2);
  first_normal_list.toEnd(3);

  DLList<int> first_reversed_list; 
  first_reversed_list.toEnd(4);
  first_reversed_list.toEnd(5);
  first_reversed_list.toEnd(6);

  DLList<int> second_normal_list;
  second_normal_list.toEnd(7);
  second_normal_list.toEnd(8);
  second_normal_list.toEnd(9);

  DLList<int> second_reversed_list; 
  second_reversed_list.toEnd(10);
  second_reversed_list.toEnd(11);
  second_reversed_list.toEnd(12);

  D.toEnd(first_normal_list);
  D.toEnd(first_reversed_list);
  D.toEnd(second_normal_list);
  D.toEnd(second_reversed_list);

  List<int> flattened_list = flatten(D);

  flattened_list.print();
	return 0;
}

