#include <vector>

using namespace std;

class Iterator
{
	struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums)
	{

	}

	Iterator(const Iterator& iter)
	{

	}

	virtual ~Iterator()
	{

	}

	int next()
	{
		return 0;
	}

	bool hasNext() const
	{
		return true;
	}
};


class PeekingIterator : public Iterator
{
	bool _isPeeking;

	int _value;

public:
	PeekingIterator(const vector<int>& nums) :
		Iterator(nums),
		_isPeeking(false)
	{

	}

	int peek()
	{
		if (_isPeeking)
		{
			return _value;
		}
		else
		{
			_isPeeking = true;
			return _value = Iterator::next();
		}
	}

	int next()
	{
		if (_isPeeking)
		{
			_isPeeking = false;
			return _value;
		}
		else
		{
			return Iterator::next();
		}
	}

	bool hasNext()
	{
		if (_isPeeking)
		{
			return true;
		}
		else
		{
			return Iterator::hasNext();
		}
	}
};

int main()
{
	PeekingIterator it(vector<int>{1, 2, 3, 4});
	auto var = it.hasNext();
	auto var1 = it.peek();
	auto var2 = it.peek();
	auto var3 = it.next();
	auto var4 = it.next();
	auto var5 = it.peek();
	auto var6 = it.peek();
	auto var7 = it.next();
	auto var8 = it.hasNext();
	auto var9 = it.peek();
	auto var0 = it.hasNext();
	auto var11 = it.next();
	auto var12 = it.hasNext();
	return 0;
}