#include "List.h"
#include "Queue.h"

struct Student {
	char name[100];
	int fn;
	int course;
};

void printInfo(List<Student>& students) {
	students.iterStart();
	Node<Student>* it = students.iter();
	Queue<Student> queue2;
	Queue<Student> queue4;
	Stack<Student> stack1;
	Stack<Student> stack3;
	while (it != NULL) {
		Student gosho = it->item;
		switch (gosho.course) {
			case 1:
				stack1.push(gosho);
				break;
			case 2:
				queue2.push(gosho);
				break;
			case 3:
				stack3.push(gosho);
				break;
			case 4:
				queue4.push(gosho);
		}


		it = students.iter();
	}
	stack1.print();
	queue2.print();
	stack3.print();
	queue4.print();
}

int main () {
	List<Student> students;
	return 0;
}
