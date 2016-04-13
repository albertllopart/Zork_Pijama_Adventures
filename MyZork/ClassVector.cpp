#include "ClassVector.h"
#include <assert.h>

template <class TYPE>
Vector<TYPE>::Vector()
{
	vec = new TYPE[capacity];
}

template <class TYPE>
Vector<TYPE>::Vector(const Vector& vec)
{
	capacity = vec.capacity;
	elements = vec.elements;
	this->vec = new TYPE[capacity];
	for (unsigned int i = 0; i < elements; i++)
	{
		this->vec[i] = vec.vec[i];
	}
}

template <class TYPE>
void Vector<TYPE>::PushBack(TYPE object)
{
	if (num_elements >= capacity)
	{
		TYPE* temp;
		capacity += 20;
		temp = new TYPE[capacity];
		for (int i = 0; i < elements; ++i)
		{
			temp[i] = my_array[i];
		}
		delete[]my_array;
		vec = temp;
	}

	vec[elements++] = object;
}

template <class TYPE>
void Vector<TYPE>::PushFront(TYPE object)
{
	elements++;

	if (capacity == elements - 1)
	{
		capacity++;
		TYPE* copy = new TYPE[elements - 1];
		for (int i = 0; i < elements - 1; i++)
		{
			copy[i] = vec[i];
		}
		delete[]vec;
		vec = new TYPE[capacity];
		vec[0] = element;
		for (int i = 1; i < elements; i++)
		{
			vec[i] = copy[i - 1];
		}
	}
	for (int i = elements; i > 0; i--)
	{
		vec[i - 1] = vec[i - 2];
	}
	vec[0] = element;
}

template <class TYPE>
void Vector<TYPE>::ShrinkToFit()
{
	if (elements < capacity)
	{
		capacity = elements;
		TYPE* copy = new TYPE[elements];
		for (int i = 0; i < elements; i++)
		{
			copy[i] = vec[i];
		}
		delete[]vec;
		vec = new TYPE[capacity];
		for (int i = 0; i < elements; i++)
		{
			vec[i] = copy[i];
		}0
	}
}

template <class TYPE>
void Vector<TYPE>::Clear()
{
	elements = 0;
}

template <class TYPE>
bool Vector<TYPE>::Empty()const
{
	return (elements == 0);
}

template <class TYPE>
int Vector<TYPE>::Size()const
{
	return elements;
}

template <class TYPE>
int Vector<TYPE>::Capacity()const
{
	return capacity;
}

template <class TYPE>
TYPE* Vector<TYPE>::operator[](int number)const
{
	assert(number < elements);
	return vec[number];
}

template <class TYPE>
Vector<TYPE>::~Vector()
{
	delete[]vec;
}
