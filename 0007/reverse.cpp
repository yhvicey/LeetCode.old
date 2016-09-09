#include<limits>
using namespace std;

int reverse(int x)
{
	long long result = 0;
	while (x != 0)
	{
		result = result * 10 + (x % 10);
		x = x / 10;
	}
	if (result > INT_MAX || result < INT_MIN)
	{
		return 0;
	}
	return (int)result;
}

int main()
{
	reverse(-2147483648);
	return 1;
}