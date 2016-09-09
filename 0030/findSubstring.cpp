#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

class Solution
{
public:
	map<string, int> _map;

	vector<int> _result;

	void check(string s, int index, int wordLen, int wordsCount)
	{
		auto temp = _map;
		int sLen = s.length();
		for (int i = 0; i < wordsCount; i++)
		{
			if (index + i*wordLen > sLen)
			{
				return;
			}
			string str = s.substr(index + i*wordLen, wordLen);
			if (--temp[str] < 0)
			{
				return;
			}
		}
		_result.push_back(index);
	}

	vector<int> findSubstring(string s, vector<string>& words)
	{
		int len = s.size();
		int wordsCount = words.size();
		if (wordsCount < 1)
		{
			return vector<int>{};
		}
		int wordLen = words[0].size();
		for (int i = 0; i < words.size(); i++)
		{
			_map[words[i]]++;
		}
		for (int i = 0; i < len - wordLen; i++)
		{
			check(s, i, wordLen, wordsCount);
		}
		return _result;
	}
};

int main()
{
	Solution sln;
	//auto var = sln.findSubstring();
	return 0;
}