#include<string>
#include<vector>
#include<map>
using namespace std;

string longestCommonPrefix(vector<string>& strs)
{
	if (strs.empty())
	{
		return "";
	}
	int len = strs.size();
	if (len == 1)
	{
		return strs[0];
	}
	string first = strs[0];
	int matchLen = first.length();
	for (int i = 1; i < len && matchLen != 0; i++)
	{
		int j = 0;
		for (; j < matchLen; j++)
		{
			if (strs[i][j] != first[j])
			{
				break;
			}
		}
		matchLen = j;
	}
	return first.substr(0, matchLen);
}

int main()
{
	longestCommonPrefix(vector<string>{"c", "c"});
	return 0;
}