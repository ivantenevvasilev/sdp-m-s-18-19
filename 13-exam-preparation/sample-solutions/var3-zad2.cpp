
bool is_cool (List<int> list, int n) {
	list.iterStart();
	Node<int>* p = list.iterSucc();

	list.iterEnd();
	Node<int>* q = list.iterPred();


	for (int i = 0; i < n-1; ++i) {
		if (
			p->item > p->next->item
				|| q->item > q->prev->item
				|| p->item != q->item
		) {

			return false;
		}


		p = p->next;
		q = list.iterPred();
	}

	return true;
}
