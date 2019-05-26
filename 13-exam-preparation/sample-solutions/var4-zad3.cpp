#include "List.h"


template <class T>
T get_kth (List<T> list, int k) {
	list.iterStart();
	Node<T>* it = list.iter();
	int counter = 0;

	T result;
	while (it != NULL) {
		if (counter == k) {
			 result = it->item;
			 break;
		}
		counter++;
		it = list.iter();
	}

	return result;
}

bool checkRowAndColumn (List<List<int>> M, int k) {
	List<int> row = get_kth(M, k);

	M.iterStart();
	Node<T>* it = M.iter();
	int counter = 0;

	while (it != NULL) {
		if (counter == k) {
			row = it->item;
		}
		counter++;
		it = M.iter();
	}

	M.iterStart();
	Node<List<int>>* it = M.iter();
	row.iterStart();
	Node<int>* rowIt = row.iter();

	while (it != NULL && rowIt != NULL) {
		int col_num = get_kth(it->item, k);

	Vj
		wejkawkejkh
		it = cur.iter();
		counter = 0;
		while (it != NULL) {
			if (counter == k) {
				row = it->item;
			}
			counter++;
			it = M.iter();
		}

		int row_num = rowIt->item;
		if (col_num != row_num) {
			return false;
		}

		rowIt = row.iter();
		it = M.iter();
	}

	return true;
}

int main () {
	List<List<int>> M;



	return 0;
}
