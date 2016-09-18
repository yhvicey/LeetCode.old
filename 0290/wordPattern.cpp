#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
	unordered_map<char, string> leftToRight;

	unordered_map<string, char> rightToLeft;

	vector<string> Split(string source, char separator, bool removeEmptyEntries = false)
	{
		string temp = "";
		vector<string> result;
		int len = source.size();
		for (int i = 0; i < len; i++)
		{
			if (source[i] == separator)
			{
				if (removeEmptyEntries)
				{
					if (temp == "")
					{
						continue;
					}
				}
				result.push_back(temp);
				temp = "";
			}
			else
			{
				temp += source[i];
			}
		}
		result.push_back(temp);
		return result;
	}

public:
	bool wordPattern(string pattern, string str)
	{
		auto parts = Split(str, ' ', true);
		int len = pattern.size();

		if (len != parts.size())
		{
			return false;
		}
		for (int i = 0; i < len; i++)
		{
			string right = leftToRight[pattern[i]];
			if (right != "")
			{
				if (right == parts[i])
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
				char left = rightToLeft[parts[i]];
				if (left)
				{
					return false;
				}
				else
				{
					leftToRight[pattern[i]] = parts[i];
					rightToLeft[parts[i]] = pattern[i];
				}
			}
		}
		return true;
	}
};

int main()
{
	auto var = Solution().wordPattern("aaa", "aa aa aa aa");
	return 0;
}