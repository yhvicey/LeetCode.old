class Solution
{
	bool check(double n)
	{
		if (n == 3 || n == 1)
		{
			return true;
		}
		if (n >= 1)
		{
			return check(n / 3);
		}
		else
		{
			return false;
		}
	}

public:
	bool isPowerOfThree(int n)
	{
		return check(n);
	}
};

int main()
{
	return 0;
}