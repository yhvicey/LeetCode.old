#include <cmath>

class Solution
{
public:
	int bulbSwitch(int n)
	{
		return ceil(sqrt(n + 1) - 1);
	}
};

int main()
{
	auto var = Solution().bulbSwitch(9999);
	return 0;
}