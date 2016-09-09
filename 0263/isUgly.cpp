class Solution
{
public:
	bool isUgly(int num)
	{
		if (num <= 0)
		{
			return false;
		}
		while (!(num % 2))
		{
			num = num / 2;
		}
		while (!(num % 3))
		{
			num = num / 3;
		}
		while (!(num % 5))
		{
			num = num / 5;
		}
		return num == 1;
	}
};

int main()
{
	auto var = Solution().isUgly(2);
}