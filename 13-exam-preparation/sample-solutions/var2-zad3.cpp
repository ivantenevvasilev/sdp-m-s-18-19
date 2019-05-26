#include "List.h"
#include "DList.h"
#include <list>

template <class T>
void printList(List<T> list) {
	list.iterStart();
	Node<DLList<int>>* p = list.iter();
	while (p != NULL) {
		p->item.print();
		p = list.iter();
	}
}

void readIntoList(DLList<int>& dllist, int n) {
	for (int i = 0 ; i < n; ++i) {
		int a;
		cin >> a;
		dllist.toEnd(a);
	}
}

List<int> zad2(List<DLList<int>> golqmo_kuche) {
	List<int> result;

	//int i = 0;
	golqmo_kuche.iterStart();
	//elem_link1<DLList<int>>;
	Node<DLList<int>>* bulha = golqmo_kuche.iter();
	int counter = 0;
	while (bulha != nullptr) {
		++counter;
		DLList<int> malka_kotka = bulha->item;
		if (counter % 2 == 1) {
			malka_kotka.iterStart();
		} else {
			malka_kotka.iterEnd();
		}
		//elem_link2

		DNode<int>* mishka = (counter % 2 == 1 ? malka_kotka.iterSucc() : malka_kotka.iterPred());

		while (mishka != NULL) {
			result.toEnd(mishka->item);
			if (counter % 2 == 1) {
				mishka = malka_kotka.iterSucc();
			} else {
				mishka = malka_kotka.iterPred();
			}
		}

		// bulha = bulha->next;
		bulha = golqmo_kuche.iter();
	}


	return result;
}

int main () {
	List<DLList<int>> sharo;
	DLList<int> pisana;

	int* array;
	array = new int[4]{1, 3, 2, 4};
	sharo.toEnd(DLList<int>(array, 4));

	delete[] array;
	array = new int[5]{5, 2, 4, 9, 8};
	sharo.toEnd(DLList<int>(array, 5));

	delete[] array;
	array = new int[3]{2, 1, 5};
	sharo.toEnd(DLList<int>(array, 3));

	delete[] array;
	array = new int[4]{5, 3, 7, 8};
	sharo.toEnd(DLList<int>(array, 4));

	delete[] array;
	array = new int[3]{3, 5, 7};
	sharo.toEnd(DLList<int>(array, 3));

	//printList(sharo);

	zad2(sharo).print();

	return 0;
}