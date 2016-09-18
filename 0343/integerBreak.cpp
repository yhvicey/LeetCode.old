#include <math.h>

using namespace std;

class Solution
{
public:
	int integerBreak(int n)
	{
		if (n == 1)
		{
			return 0;
		}
		if (n == 2)
		{
			return 1;
		}
		if (n == 3)
		{
			return 2;
		}
		int time = n / 3;
		int mod = n % 3;
		if (mod == 2)
		{
			return pow(3, time)*mod;
		}
		else
		{
			return pow(3, time - 1)*(3 + mod);
		}
	}
};

int main()
{
	auto var = Solution().integerBreak(2);
	return 0;
}