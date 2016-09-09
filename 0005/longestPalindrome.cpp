#include<string>
using namespace std;

string longestPalindrome(string s)
{
	int len = s.length();
	if (len <= 1)
	{
		return s;
	}
	double index = 0;
	int halfLength = 0;
	for (double i = 0; i < len; i += 0.5)
	{
		if (i - (int)i > 0)
		{
			int length = 0;
			for (int j = 0; (i + 0.5 + j) < len && (i - 0.5 - j) >= 0; j++)
			{
				if (s.at((int)(i + 0.5 + j)) == s.at((int)(i - 0.5 - j)))
				{
					length++;
				}
				else
				{
					break;
				}
			}
			if (length > halfLength)
			{
				halfLength = length;
				index = i;
			}
		}
		else
		{
			int length = 0;
			for (int j = 1; (i + j) < len && (i - j) >= 0; j++)
			{
				if (s.at((int)(i + j)) == s.at((int)(i - j)))
				{
					length++;
				}
				else
				{
					break;
				}
			}
			if (length >= halfLength)
			{
				halfLength = length;
				index = i;
			}
		}
	}
	if (index - (int)index > 0)
	{
		return s.substr((index + 0.5 - halfLength), 2 * halfLength);
	}
	else
	{
		return s.substr((index - halfLength), 2 * halfLength + 1);
	}
}

int main()
{
	longestPalindrome("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabcaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
}