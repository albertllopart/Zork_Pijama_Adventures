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

	void operator =(TYPE i)
	{
		vec = i;
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

	uint size() const
	{
		return elements;
	}
	uint mycapacity() const
	{
		return capacity;
	}
	bool empty() const
	{
		return elements == 0;
	}
	void clear()
	{
		elements = 0;
	}

};

#endif