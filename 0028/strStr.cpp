#include<string>
using namespace std;

class Solution
{
public:
	int strStr(string haystack, string needle)
	{
		int haystackLen = haystack.length();
		int needleLen = needle.length();
		if (needleLen == 0)
		{
			return 0;
		}
		for (int i = 0; i < haystackLen; i++)
		{
			if (haystack[i] != needle[0])
			{
				continue;
			}
			for (int j = 1; j < needleLen; j++)
			{
				if (i + j >= haystackLen)
				{
					return -1;
				}
				if (haystack[i + j] != needle[j])
				{
					goto tag;
				}
			}
			return i;
		tag:continue;
		}
		return -1;
	}
};

int main()
{
	Solution s;
	auto ans = s.strStr("mississippi", "issip");
}