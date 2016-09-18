#include <map>

using namespace std;

class Solution
{
private:
	int* _record;
public:
	int numTrees(int n)
	{
		if (!_record)
		{
			_record = new int[n];
			memset(_record, 0, n * sizeof(int));
		}
		int x = n - 1;
		if (_record[x])
		{
			return _record[x];
		}
		if (x == 0)
		{
			_record[x] = 1;
			return _record[x];
		}

	}
};

int main()
{
	return 0;
}