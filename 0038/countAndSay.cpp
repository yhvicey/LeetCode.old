#include<string>

using namespace std;

class Solution
{
	string* record = NULL;
public:
	string countAndSay(int n)
	{
		if (!record)
		{
			record = new string[n];
		}
		n--;
		if (record[n] != "")
		{
			return record[n];
		}
		if (n == 0)
		{
			record[n] = "1";
			return record[n];
		}
		string str = countAndSay(n);
		string result;

		int count = 0;
		char lastChar = str[0];
		int len = str.length();
		for (int i = 0; i < len; i++)
		{
			if (str[i] == lastChar)
			{
				count++;
			}
			else
			{
				result += (count + '0');
				result += lastChar;
				lastChar = str[i];
				count = 1;
			}
		}
		if (count != 0)
		{
			result += (count + '0');
			result += lastChar;
		}
		record[n] = result;
		return record[n];
	}
};

int main()
{
	auto var = Solution().countAndSay(2);
	return 0;
}