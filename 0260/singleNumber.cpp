#include<vector>

using namespace std;

class Solution
{
public:
	vector<int> singleNumber(vector<int>& nums)
	{
		int result = 0;
		for (auto num : nums)
		{
			result = result^num;
		}
		int mask = result&(~(result - 1));
		int a = 0;
		int b = 0;
		for (auto num : nums)
		{
			if (num&mask)
			{
				a = a^num;
			}
			else
			{
				b = b^num;
			}
		}
		return vector<int>{a, b};
	}
};

int main()
{
	auto var = Solution().singleNumber(vector<int>{1, 2, 1, 3, 2, 5});
	return 0;
}