#include<map>

using namespace std;

class Solution
{
	map<int, int> _map;
public:
	bool isHappy(int n)
	{
		if (n == 1)
		{
			return true;
		}
		if (!_map[n])
		{
			_map[n] = 1;
		}
		else
		{
			return false;
		}
		int result = 0;
		while (n != 0)
		{
			int temp = n % 10;
			n = n / 10;
			result += temp*temp;
		}
		return isHappy(result);
	}
};

int main()
{
	auto var = Solution().isHappy(19);
	return 0;
}
