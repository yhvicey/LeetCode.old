#include<cstdint>
class Solution
{
public:
	int hammingWeight(uint32_t n)
	{
		if (n == 0)
		{
			return 0;
		}
		int count = 1;
		while (n = n&(n - 1))
		{
			count++;
		}
		return count;
	}
};

int main()
{
	return 0;
}