#ifndef CLASS_VECTOR
#define CLASS_VECTOR

typedef unsigned int uint;

#include<assert.h>

template <class TYPE>
class Vector
{
private:
	TYPE* vec = nullptr;
	uint capacity = 1;
	uint elements = 0;

public:
	
	Vector()
	{
		vec = new TYPE[capacity];
	}

	Vector(uint size)
	{
		capacity = size;
		vec = new TYPE[size];
	}

	Vector(const Vector& other)
	{
		elements = other.elements;
		capacity = other.capacity;
		vec = new TYPE[capacity];
		for (uint i = 0; i < elements; i++)
		{
			vec[i] = other.vec[i];
		}

	}
	~Vector()
	{
		delete[]vec;
	}
	
	TYPE& operator[](int i)const
	{
		assert(i < elements);
		return vec[i];
	}

	void PushBack(const TYPE object)
	{
		if (elements >= capacity)
		{
			TYPE* copy;
			capacity += 20;
			copy = new TYPE[capacity];
			for (int i = 0; i < elements; ++i)
			{
				copy[i] = vec[i];
			}
			delete[]vec;
			vec = copy;
		}

		vec[elements++] = object;

	}
	void PushFront(const TYPE object)
	{
		elements++;
		if (elements >= capacity)
		{
			TYPE* copy;
			capacity += 20;
			copy = new TYPE[capacity];
			for (int i = 0; i < elements; ++i)
			{
				copy[i] = vec[i];
			}
			delete[]vec;
			vec = copy;
		}

		for (int i = elements; i >0; --i)
		{
			vec[i - 1] = vec[i - 2];
		}

		vec[0] = object;

	}

	bool PopBack(TYPE& value)
	{
		if (elements > 0)
		{
			elements--;
		}
		value = vec[elements];
		return elements >= 0;
	}

	uint Size() const
	{
		return elements;
	}
	uint Capacity() const
	{
		return capacity;
	}
	bool Empty() const
	{
		return elements == 0;
	}
	void clear()
	{
		elements = 0;
	}

};

#endif