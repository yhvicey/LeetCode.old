#include <vector>

using namespace std;

class Solution
{
public:
	vector<int> plusOne(vector<int>& digits)
	{
		bool flag = true;
		int len = digits.size();
		for (int i = len - 1; i >= 0; i--)
		{
			int val = digits[i] + (flag ? 1 : 0);
			if (val >= 10)
			{
				val -= 10;
				digits[i] = val;
				flag = true;
			}
			else
			{
				digits[i] = val;
				return digits;
			}
		}
		if (flag)
		{
			digits.insert(digits.begin(), 1);
		}
		return digits;
	}
};

int main()
{
	auto var = Solution().plusOne(vector<int>{8, 8});
	return 0;
}