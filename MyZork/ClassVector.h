#ifndef CLASS_VECTOR
#define CLASS_VECTOR

template <class TYPE>

class Vector
{
private:

	TYPE* vec;
	unsigned int capacity = 10;
	unsigned int elements = 0;

public:

	Vector();
	Vector(const Vector& vec);
	~Vector();

	void PushBack(TYPE object);
	void PushFront(TYPE object);
	void ShrinkToFit();
	
	void Clear();
	bool Empty()const;
	int Size()const;
	int Capacity()const;

	TYPE* operator[](int number)const;
};

#endif