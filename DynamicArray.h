#pragma once


template <typename T>
class DynamicArray
{
private:
	T* elems;
	int size;
	int capacity;
	// Resize the current DynamicArray, multiplying its capacity by a given factor
	void resize(double factor = 2);

public:
	//constructor 
	DynamicArray(int capacity = 10);

	// copy constructor for DynamicArray
	DynamicArray(const DynamicArray& v);
	~DynamicArray();
	// assignment operator for DynamicArray
	DynamicArray& operator=(const DynamicArray& v);

	// overload minus operator - removes the given element
	DynamicArray& operator-(const T& e);
	//overloar + operator
	DynamicArray& operator+(const T& e);

	/*
		Overload the subscript operator
		Input: pos - a valid position within the vector
		Output: a reference to the element on position pos
	*/
	T& operator[](int pos);

	// Adds an element to the current DynamicArray
	void add(const T& e);

	// Deletes an element from the given position
	void remove(const int poz);

	// Updates the element from a given position
	void update(const int poz, const T& c);

	int getSize() const;
	void setSize(int s) { size = s; }
	// return all elements
	T* getAllElems() const;


};

///// ----------- IMPLEMENTATION ------------ ///

template <typename T>
DynamicArray<T>::DynamicArray(int capacity)
{
	this->size = 0;
	this->capacity = capacity;
	this->elems = new T[capacity];
}

template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& v)
{
	this->size = v.size;
	this->capacity = v.capacity;
	this->elems = new T[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = v.elems[i];
}

template <typename T>
DynamicArray<T>::~DynamicArray() {
	delete[] this->elems;
}

template <typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& v)
{
	if (this == &v)
		return *this;

	this->size = v.size;
	this->capacity = v.capacity;

	delete[] this->elems;
	this->elems = new T[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = this->elems[i];

	return *this;
}

template <typename T>
DynamicArray<T>& DynamicArray<T>::operator-(const T& e)
{
	bool found = false;
	int i = 0;
	while (found == false && i < size) {
		if (elems[i] == e)
			found = true;
		else
			i++;
	}
	remove(i);
	return *this;
}
template <typename T>
DynamicArray<T>& DynamicArray<T>:: operator+(const T& e)
{
	this->add(e);
	return *this;
}


template <typename T>
T& DynamicArray<T>::operator[](int pos)
{
	return this->elems[pos];
}

template <typename T>
void DynamicArray<T>::resize(double factor)
{
	this->capacity *= static_cast<int>(factor);

	T* els = new T[this->capacity];
	for (int i = 0; i < this->size; i++)
		els[i] = this->elems[i];

	delete[] this->elems;
	this->elems = els;
}

template <typename T>
void DynamicArray<T>::add(const T& e)
{
	if (this->size == this->capacity)
		this->resize();
	this->elems[this->size] = e;
	this->size++;
}

template <typename T>
void DynamicArray<T>::remove(const int poz)
{
	for (int i = poz; i < this->size-1; i++)
		this->elems[i] = this->elems[i + 1];
	this->size--;
}

template <typename T>
void DynamicArray<T>::update(const int poz, const T& e)
{
	this->elems[poz] = e;
}

template <typename T>
T* DynamicArray<T>::getAllElems() const
{
	return this->elems;
}

template <typename T>
int DynamicArray<T>::getSize() const
{
	return this->size;
}

