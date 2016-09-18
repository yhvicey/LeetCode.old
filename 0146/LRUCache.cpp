#include <map>

using namespace std;

struct Node
{
	Node* Front;
	Node* Next;
	int Key;
	int Value;
	Node(int key,int val):
		Key(key),
		Value(val),
		Front(NULL),
		Next(NULL)
	{

	}
};

class Queue
{
	Node* _head;

	Node* _back;

	int _size;

	int _maxSize;

public:
	Queue(int maxSize) :
		_head(NULL),
		_back(NULL),
		_size(0),
		_maxSize(maxSize)
	{

	}

	bool Empty()
	{
		return _size == 0;
	}

	Node* Pop()
	{
		if (_size == 0)
		{
			return NULL;
		}
		if (_size == 1)
		{
			auto result = _back;			
			_head = NULL;
			_back = NULL;

			result->Front = NULL;
			result->Next = NULL;

			_size--;
			return result;
		}
		else
		{
			auto result = _back;

			_back = _back->Front;
			_back->Next = NULL;

			result->Front = NULL;
			result->Next = NULL;

			_size--;
			return result;
		}
	}

	void Promote(Node* target)
	{
		if (target->Front == NULL)
		{
			return;
		}
		if (target->Next == NULL)
		{
			target->Front->Next = NULL;
			_back = target->Front;

			target->Next = _head;
			_head->Front = target;
			target->Front = NULL;
			_head = target;
		}
		else
		{
			target->Front->Next = target->Next;
			target->Next->Front = target->Front;

			target->Next = _head;
			_head->Front = target;
			target->Front = NULL;
			_head = target;
		}
	}

	Node* Push(Node* node)
	{
		if (_size == 0)
		{
			_head = node;
			_back = node;
			_size++;
			return NULL;
		}
		if (_size != _maxSize)
		{
			node->Next = _head;
			_head->Front = node;
			_head = node;
			node->Front = NULL;
			_size++;
			return NULL;
		}
		else
		{
			auto result = Pop();
			Push(node);
			return result;
		}
	}

	int Size()
	{
		return _size;
	}
};

class LRUCache
{
	map<int, Node*> _map;

	Queue _queue;

public:
	LRUCache(int capacity) :
		_queue(capacity)
	{

	}

	int get(int key)
	{
		auto it = _map.find(key);
		if (it == _map.end())
		{
			return -1;
		}
		else
		{
			_queue.Promote(it->second);
			return it->second->Value;
		}
	}

	void set(int key, int value)
	{
		auto it = _map.find(key);
		if (it == _map.end())
		{
			Node* temp = new Node(key, value);
			auto ptr = _queue.Push(temp);
			if (ptr != NULL)
			{
				_map.erase(ptr->Key);
			}
			_map[key] = temp;
		}
		else
		{
			it->second->Value = value;
			_queue.Promote(it->second);
		}
	}
};

int main()
{
	LRUCache cache(2);
	cache.set(2, 1);
	cache.set(2, 2);
	cache.get(2);
	cache.set(1, 1);
	cache.set(4, 1);
	cache.get(2);
}