#include <unordered_map>

using namespace std;

class Solution
{
private:
	unordered_map<int, unordered_map<int, int>> _record;

	int build(int min, int max)
	{
		if (_record[min][max])
		{
			return _record[min][max];
		}
		if (min == max)
		{
			_record[min][max] = 1;
			return _record[min][max];
		}
		auto result = 0;
		result += build(min + 1, max);
		for (auto i = min + 1;i < max;i++)
		{
			result += build(min, i - 1)*build(i + 1, max);
		}
		result += build(min, max - 1);
		_record[min][max] = result;
		return _record[min][max];
	}

public:
	int numTrees(int n)
	{
		return build(1, n);
	}
};

int main()
{
	auto var = Solution().numTrees(3);
	return 0;
}