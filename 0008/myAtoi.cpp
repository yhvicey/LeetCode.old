#include <vector>
using namespace std;

int myAtoi(string str)
{
	int len = str.length();
	long long result = 0;
	bool isNegative = false;
	for (int i = 0; i < len; i++)
	{
		if (str[i] == 43 || str[i] == 45 || (str[i] >= 48 && str[i] <= 57))
		{
			if (str[i] == 43 || str[i] == 45)
			{
				isNegative = str[i] == '-';
				i++;
			}
			for (int j = i; j < len; j++)
			{
				if (str[j] >= 48 && str[j] <= 57)
				{
					result = result * 10 + (str[j] - 48);
					if (result > INT_MAX)
					{
						break;
					}
				}
				else
				{
					break;
				}
			}
			break;
		}
		if (str[i] != ' ')
		{
			break;
		}
	}
	result = isNegative ? -result : result;
	if (result > INT_MAX)
	{
		return INT_MAX;
	}
	if (result < INT_MIN)
	{
		return INT_MIN;
	}
	return result;
}

int main()
{
	myAtoi("18446744073709551617");
	return 0;
}