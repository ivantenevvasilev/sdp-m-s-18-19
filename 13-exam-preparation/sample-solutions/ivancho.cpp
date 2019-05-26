






int main () {
	DLList<int> dll;


	for (int i = 0; i < 10; ++i) {
		int a;
		cin >> a;
		dll.toEnd(a);
	}

	dll.iterStart(); 
	Node<int>* s = dll.iterSucc();

	dll.iterEnd();
	Node<int>* e = dll.iterPred();


	while (true) {
		std::cout << s->item;
		s = s->next;

		if (s == e) {
			cout << e->item
			break;
		}

		std::cout << e->item;
		e = e->prev;


	}


	dll.iterSucc();
}
