#ifndef INC_02__DATA_CENTER_PART_TWO_QUEUE_H
#define INC_02__DATA_CENTER_PART_TWO_QUEUE_H

#include <cstdlib>
#include <iostream>
#include <cassert>

using namespace std;

const int DEFAULT_SIZE = 100000024;

template <typename T>
class Queue {
public:
	// канонично представяне
	Queue(int size = DEFAULT_SIZE);
	~Queue();
	Queue(const Queue&);
	Queue& operator=(const Queue&);

	// основни функции
	bool empty() const;
	bool full() const;
	void push(const T&);
	void pop(T&);
	T& head();
	void print();

private:
	int front; 	// указател към началото на опашка
	int rear; 	// указател след края на опашка
	int queue_size;	// максимален размер на опашка
	int queue_len; 	// текущ размер на опашка
	T *arr; 	// носител на опашката

				// помощни функции
	void copyQueue(const Queue&);
	void deleteQueue();
};

// канонично представяне
template <typename T>
Queue<T>::Queue(int size) { // създава празна опашка
	if (size <= 0) {
		queue_size = DEFAULT_SIZE;
	}
	else {
		queue_size = size;
	}
	arr = new T[queue_size];
	assert(arr != NULL);
	front = 0;
	rear = 0;
	queue_len = 0;
}

template <typename T>
Queue<T>::~Queue() {
	deleteQueue();
}

template <typename T>
Queue<T>::Queue(const Queue<T>& r) {
	copyQueue(r);
}

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& r) {
	if (this != &r) {
		deleteQueue();
		copyQueue(r);
	}

	return *this;
}

template <typename T>
void Queue<T>::copyQueue(const Queue<T>& r) {
	queue_size = r.queue_size;
	arr = new T[queue_size];
	assert(arr != NULL);
	for (int i = 0; i < queue_size; i++) {
		arr[i] = r.arr[i];
	}
	queue_len = r.queue_len;
	front = r.front;
	rear = r.rear;
}

template <typename T>
void Queue<T>::deleteQueue() {
	delete[] arr;   // или delete [queue_size] arr;
}

// проверява дали неявната опашка е празна
template <typename T>
bool Queue<T>::empty() const {
	return queue_len == 0;
}

// проверява дали неявната опашка е пълна
template <typename T>
bool Queue<T>::full() const {
	return queue_len == queue_size;
}

// включва x в неявната опашка, ако последната не е пълна
template <typename T>
void Queue<T>::push(const T& x) {
	if (!full()) {
		arr[rear] = x;
		queue_len++;
		rear++;
		rear = rear % queue_size;
	}
	else {
		std::cout << "The Queue is full.\n";
		exit(1);
	}
}

// изключва елемент от неявната опашка, ако
// последната не е празна и го записва в x
template <typename T>
void Queue<T>::pop(T& x) {
	if (!empty()) {
		x = arr[front];
		queue_len--;
		front++;
		front = front % queue_size;
	}
	else {
		std::cout << "The queue is empty.\n";
		exit(1);
	}
}

// връщаме псевдоним, това позволява да редактираме елемента, който се съдържа в главата на опашката
template <typename T>
T& Queue<T>::head() {
	if (!empty()) {
		return arr[front];
	}
	else {
		std::cout << "The Queue is empty.\n";
		exit(1);
	}
}

// извежда на екрана елементите на
// неявната опашка като я разрушава
template <typename T>
void Queue<T>::print() {
	T x;
	while (!empty()) {
		pop(x);
		std::cout << x << " ";
	}
	std::cout << std::endl;
}

#endif // INC_02__DATA_CENTER_PART_TWO_QUEUE_H
