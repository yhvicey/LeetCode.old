class Solution
{
public:
	int addDigits(int num)
	{
		int result = 0;
		while (num)
		{
			int temp = num % 10;
			result += temp;
			num = (num - temp) / 10;
		}
		if (result < 10)
		{
			return result;
		}
		else
		{
			return addDigits(result);
		}
	}
};

int main()
{
	return 0;
}