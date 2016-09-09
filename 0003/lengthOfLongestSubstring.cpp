#include<string>
using namespace std;

int lengthOfLongestSubstring(string s)
{
	int len = s.length();
	int lastPos[256];
	memset(lastPos, -1, sizeof(lastPos));
	int startPos = 0;
	int maxLen = 0;
	int tempLen = 0;
	for (int i = 0; i < len; i++)
	{
		tempLen++;
		if (lastPos[s[i]] >= startPos)
		{
			maxLen = tempLen - 1 > maxLen ? tempLen - 1 : maxLen;
			tempLen -= (lastPos[s[i]] - startPos + 1);
			startPos = lastPos[s[i]] + 1;
		}
		lastPos[s[i]] = i;
	}
	maxLen = tempLen > maxLen ? tempLen : maxLen;
	return maxLen;
}

int main()
{
	lengthOfLongestSubstring("eee");
	return 0;
}