#include<string>

using namespace std;

class Solution
{
	int exist[26];
public:
	bool isAnagram(string s, string t)
	{
		memset(exist, 0, sizeof(int) * 26);
		int sLen = s.length();
		int tLen = t.length();
		if (sLen != tLen)
		{
			return false;
		}
		for (int i = 0; i < sLen; i++)
		{
			exist[s[i] - 'a'] += 1;
		}
		for (int i = 0; i < tLen; i++)
		{
			if (exist[t[i] - 'a'])
			{
				exist[t[i] - 'a'] -= 1;
			}
			else
			{
				return false;
			}
		}
		for (int i = 0; i < 26; i++)
		{
			if (exist[i])
			{
				return false;
			}
		}
		return true;
	}
};

int main()
{
	return 0;
}