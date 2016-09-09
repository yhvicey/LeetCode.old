#include<memory>

class Solution
{
	int* bulbs;

	int count;

	int len;

	void change(int base)
	{
		int time = len / base;
		for (int i = 1; i <= time; i++)
		{
			if (bulbs[i*base - 1])
			{
				bulbs[i*base - 1] = 0;
				count--;
			}
			else
			{
				bulbs[i*base - 1] = 1;
				count++;
			}
		}
	}

public:
	int bulbSwitch(int n)
	{
		len = n;
		bulbs = new int[len];
		memset(bulbs, 0, sizeof(int)*len);
		count = 0;
		for (int i = 1; i <= len; i++)
		{
			change(i);
		}
		return count;
	}
};

int main()
{
	auto var = Solution().bulbSwitch(9999999);
	return 0;
}