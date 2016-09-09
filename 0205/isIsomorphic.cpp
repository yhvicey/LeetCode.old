#include<string>
#include<unordered_map>

using namespace std;

class Solution
{
	unordered_map<int, int> leftToRight;

	unordered_map<int, int> rightToLeft;

public:
	bool isIsomorphic(string s, string t)
	{
		int len = s.size();
		for (int i = 0; i < len; i++)
		{
			char right = leftToRight[s[i]];
			if (right)
			{
				if (right == t[i])
				{
					continue;
				}
				else
				{
					return false;
				}
			}
			else
			{
				char left = rightToLeft[t[i]];
				if (left)
				{
					return false;
				}
				else
				{
					leftToRight[s[i]] = t[i];
					rightToLeft[t[i]] = s[i];
				}
			}
		}
		return true;
	}
};

int main()
{
	auto var = Solution().isIsomorphic("ab", "aa");
	return 0;
}