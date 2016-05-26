template <class TYPE>

struct Node
{
	TYPE data;
	Node <TYPE>* next = nullptr;

	Node(const TYPE& data) : data(data)
	{
	}
};

template <class TYPE>

struct List
{
	Node <TYPE>* first = nullptr;

	bool Empty()const
	{
		return first == nullptr;
	}

	unsigned int Size()const
	{
		Node <TYPE>* temp = first;
		unsigned int quantity = 0;

		while (temp != nullptr)
		{
			quantity++;
			temp = temp->next;
		}
		else return quantity;
	}

	Node <TYPE>* End()const
	{
		Node <TYPE>* temp = first;

		if (temp != nullptr)
		{
			while (temp->next != nullptr)
			{
				temp = temp->next;
			}
		}
		return temp;
	}

	//pushback

	void PushBack(const TYPE& data)
	{
		if (first != nullptr)
		{
			End()->next = new Node <TYPE>(data);
		}
		else
		{
			first = new Node <TYPE>(data);
		}
	}

	//pushfront

	void PushFront(const TYPE& data)
	{
		if (first == nullptr)
		{
			first = new Node <TYPE>(data);
		}
		else
		{
			Node <TYPE>* temp = first;
			first = new Node <TYPE>(data);
			first->next = temp;
		}

	}

	//popback

	void PopBack()
	{
		if (first != nullptr)
		{
			if (first->next == nullptr)
			{
				Node <TYPE>* temp = first;
				first = nullptr;
				delete temp;
			}
			else
			{
				Node <TYPE>* temp = first;
				while (temp->next->next != nullptr)
				{
					temp = temp->next;
				}
				delete temp->next->next;
				temp->next = nullptr;
			}
		}
	}

	//popfront

	void PopFront()
	{
		Node <TYPE>* temp = first;
		if (first != nullptr)
		{
			first = first->next;
			delete temp;
		}
	}

	//erase

	void Erase(Node<TYPE>* ToErase)
	{
		if (ToErase != nullptr)
		{
			if (ToErase != first)
			{
				Node <TYPE>* temp = first;
				while (temp->next != ToErase)
				{
					temp = temp->next;
				}
				temp->next = ToErase->next;
				delete ToErase;
			}
			else
			{
				first = first->next;
				delete ToErase;
			}

		}
	}

	//operator []

	Node <TYPE>* operator[](uint index)
	{
		Node <TYPE>* temp = first;

		if (temp != nullptr)
		{
			for (int i = 0; i < index; i++)
			{
				temp = temp->next;
			}
		}
		return temp;
	}

	//insert

	void Insert(Node<TYPE>* position, const TYPE& data)
	{
		Node <TYPE>* ToInsert = new Node<TYPE>(data);

		if (position != nullptr)
		{
			Node <TYPE>* temp = first;

			if (position != first)
			{
				while (temp->next != position)
				{
					temp = temp->next;
				}
				temp->next = ToInsert;
				ToInsert->next = position;
			}
			else
			{
				first = ToInsert;
			}
		}
	}

};