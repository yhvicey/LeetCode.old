class Solution
{
	bool check(double n)
	{
		if (n == 4 || n == 1)
		{
			return true;
		}
		if (n >= 1)
		{
			return check(n / 4);
		}
		else
		{
			return false;
		}
	}

public:
	bool isPowerOfFour(int n)
	{
		return check(n);
	}
};

int main()
{
	return 0;
}