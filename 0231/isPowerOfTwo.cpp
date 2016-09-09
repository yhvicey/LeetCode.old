class Solution
{
	bool check(double n)
	{
		if (n == 2 || n == 1)
		{
			return true;
		}
		if (n >= 1)
		{
			return check(n / 2);
		}
		else
		{
			return false;
		}
	}

public:
	bool isPowerOfTwo(int n)
	{
		return check(n);
	}
};

int main()
{
	return 0;
}