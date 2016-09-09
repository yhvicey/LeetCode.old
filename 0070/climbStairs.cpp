#include<memory.h>

class Solution
{
public:
	int* record = 0;

	int climbStairs(int n)
	{
		if (!record)
		{
			record = new int[n];
			memset(record, 0, n * sizeof(int));
		}
		int x = n - 1;
		if (x < 0)
		{
			return 0;
		}
		if (record[x])
		{
			return record[x];
		}
		if (x == 0)
		{
			record[x] = 1;
			return record[x];
		}
		if (x == 1)
		{
			record[x] = 2;
			return record[x];
		}
		record[x] = climbStairs(n - 2) + climbStairs(n - 1);
		return record[x];
	}
};

int main()
{
	Solution s;
	auto var = s.climbStairs(44);
}