#ifndef CLASS_LIST
#define CLASS_LIST

typedef unsigned int uint;

template<class TYPE>
class dList
{
public:

	struct dNode
	{
		TYPE data;
		dNode* next = nullptr;
		dNode* prev = nullptr;

		dNode(const TYPE& data) :data(data){}
		~dNode(){}
	};

	dNode* first = nullptr;

public:

	dList(){};
	~dList(){};

	bool empty() const
	{
		return first == nullptr;
	}

	uint size() const
	{
		uint elements = 0;
		dNode* temp = first;
		while (temp != nullptr)
		{
			temp = temp->next;
			elements++;
		}
		return elements;
	}

	dNode* end() const
	{
		dNode* temp = first;

		if (temp != nullptr)
		{
			while (temp->next != nullptr)
			{
				temp = temp->next;
			}
		}
		return temp;
	}

	void PushBack(const TYPE& data)
	{
		dNode* temp = first;
		dNode* new_node = new dNode(data);

		if (temp == nullptr)
		{
			first = new_node;
		}

		else
		{
			while (temp->next != nullptr)
			{
				temp = temp->next;
			}
			temp->next = new_node;
			new_node->prev = temp;
		}
	}

	void PushFront(const TYPE& data)
	{
		dNode* new_node = new dNode(data);

		if (first == nullptr)
		{
			first = new_node;
		}

		else
		{
			new_node->next = first;
			first->prev = new_node;
			first = new_node;
		}
	}

	bool PopBack()
	{
		if (first != nullptr) 
		{
			if (first->next != nullptr) 
			{
				dNode* temp = first;
				while (temp->next != nullptr)
				{
					temp = temp->next;
				}
				temp->prev->next = nullptr;
				delete temp;
			}
			else
			{
				dNode* temp = first;
				first = nullptr;
				delete temp;
			}
			return true;
		}
		return false;
	}

	bool PopFront()
	{
		if (first != nullptr) 
		{
			if (first->next != nullptr)
			{
				dNode* temp = first;
				first = temp->next;
				first->prev = nullptr;
				delete temp;
			}
			else
			{
				dNode* temp = first;
				first = nullptr;
				delete temp;
			}
			return true;
		}
		return false;
	}

	void erase(dNode* toerase)
	{
		if (size() > 1)
		{
			if (toerase->prev == nullptr)
			{
				first = toerase->next;
				first->prev = nullptr;
			}
			else if (toerase->next == nullptr)
			{
				toerase->prev->next = nullptr;
			}
			else
			{
				toerase->prev->next = toerase->next;
				toerase->next->prev = toerase->prev;
			}
			delete toerase;
		}
		else
		{
			first = nullptr;
			delete toerase;
		}
	}

	void insert(dNode* toinsert, const TYPE& data)
	{
		dNode* new_node = new dNode(data);
		if (first != nullptr)
		{
			if (toinsert->prev == nullptr)
			{
				new_node->next = toinsert;
				toinsert->prev = new_node;
				first = new_node;
			}

			else
			{
				new_node->next = toinsert;
				toinsert->prev->next = new_node;
				new_node->prev = toinsert->prev;
				toinsert->prev = new_node;
			}
		}

		else
		{
			first = new_node;
		}
	}

	void clear()
	{
		dNode* n = first;
		dNode* next;
		while (n != nullptr)
		{
			next = n->next;
			delete n;
			n = next;
		}
		first = nullptr;
	}

};

#endif