#include <stdint.h>

class Solution
{
public:
	uint32_t reverseBits(uint32_t n)
	{
		uint32_t result = 0;
		int count = 32;
		while (count--)
		{
			result = result << 1;
			if (n & 1)
			{
				result += 1;
			}
			n = n >> 1;
		}
		return result;
	}
};

int main()
{
	Solution sln;
	auto var = sln.reverseBits(1);
}