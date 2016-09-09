#include<limits>
class Solution
{
public:
	int divide(int dividend, int divisor)
	{
		if (divisor == 0)
		{
			return INT_MAX;
		}
		if (divisor > dividend)
		{
			return 0;
		}
		bool isNegative = (dividend < 0) ^ (divisor < 0);
		dividend = abs(dividend);
		divisor = abs(divisor);

		int result = 0;
		while (dividend)
		{
			int tdivisor = divisor;
			int count = 0;
			while (divisor < dividend)
			{
				divisor = divisor << 1;
			}
			divisor = divisor >> 1;
		}
		return isNegative ? -result : result;
	}
};

int main()
{
	Solution sln;
	sln.divide(9900, 10);
}