#ifndef INC_02__DATA_CENTER_PART_ONE_DYNAMICARRAY_H
#define INC_02__DATA_CENTER_PART_ONE_DYNAMICARRAY_H

const unsigned int INITIAL_CAPACITY = 8;

template <class T>
class DynamicArray {
	T* data;
	unsigned int size;
	unsigned int capacity;

public:
	/* канонично представяне */
	DynamicArray ();
	DynamicArray (const DynamicArray& other);
	~DynamicArray ();
	DynamicArray& operator= (const DynamicArray& other);

	/* член-функции от условието */
	void pushBack (const T& element);
	void popBack ();
	T& operator[] (unsigned int index);
	const T& operator[] (unsigned int index) const;

	/* помощни член-функции */
private:
	void reserve (unsigned int newCapacity);
public:
	unsigned int getSize() const;
	bool operator== (const DynamicArray<T>& other) const;
};

template <class T>
DynamicArray<T>::DynamicArray () {
	data = new T[INITIAL_CAPACITY];
	size = 0;
	capacity = INITIAL_CAPACITY;
}

template <class T>
DynamicArray<T>::DynamicArray (const DynamicArray& other) {
	size = other.size;
	capacity = other.capacity;
	data = new T[capacity];

	for (unsigned int i = 0; i < size; ++i) {
		data[i] = other.data[i];
	}
}

template <class T>
DynamicArray<T>::~DynamicArray () {
	delete[] data;
}

template <class T>
DynamicArray<T>& DynamicArray<T>::operator= (const DynamicArray& other) {
	size = other.size;
	capacity = other.capacity;

	delete[] data;
	data = new T[capacity];

	for (unsigned int i = 0; i < size; ++i) {
		data[i] = other.data[i];
	}

	return *this;
}

template <class T>
void DynamicArray<T>::pushBack (const T& element) {
	reserve(size + 1);
	data[size] = element;
	++size;
}

template <class T>
void DynamicArray<T>::popBack () {
	--size;
}

template <class T>
T& DynamicArray<T>::operator[] (unsigned int index) {
	return data[index];
}

template <class T>
const T& DynamicArray<T>::operator[] (unsigned int index) const {
	return data[index];
}

template <class T>
void DynamicArray<T>::reserve (unsigned int newCapacity) {
	if (newCapacity > capacity) {
		T* elements = data;
		capacity = newCapacity;
		data = new T[capacity];

		for (unsigned int i = 0; i < size; ++i) {
			data[i] = elements[i];
		}

		delete[] elements;
	}
}

template <class T>
unsigned int DynamicArray<T>::getSize () const {
	return size;
}

template <class T>
bool DynamicArray<T>::operator== (const DynamicArray<T>& other) const {
	if (size != other.size) {
		return false;
	}

	for (unsigned int i = 0; i < size; ++i) {
		if (data[i] != other.data[i]) {
			return false;
		}
	}

	return true;
}


#endif //INC_02__DATA_CENTER_PART_ONE_DYNAMICARRAY_H
