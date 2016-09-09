#include<vector>

using namespace std;

class NestedInteger
{
	bool _isInteger;

	int integer;

	vector<NestedInteger> list;

public:
	NestedInteger()
	{

	}

	~NestedInteger()
	{

	}

	bool isInteger() const
	{
		return _isInteger;
	}

	int getInteger() const
	{
		return integer;
	}

	const vector<NestedInteger> &getList() const
	{
		return list;
	}

};

class NestedIterator
{
	vector<int> _list;

	int _index;

	void preprocess(NestedInteger &nestedInteger, vector<int> &list)
	{
		if (nestedInteger.isInteger())
		{
			list.push_back(nestedInteger.getInteger());
		}
		else
		{
			auto nestedList = nestedInteger.getList();
			int len = nestedList.size();
			for (int i = 0; i < len; i++)
			{
				preprocess(nestedList[i], list);
			}
		}
	}

public:
	NestedIterator(vector<NestedInteger> &nestedList) :
		_index(0)
	{
		int len = nestedList.size();
		for (int i = 0; i < len; i++)
		{
			preprocess(nestedList[i], _list);
		}		
	}

	int next()
	{
		return _list[_index++];		
	}

	bool hasNext()
	{
		return _index < _list.size();
	}
};

int main()
{
	return 0;
}