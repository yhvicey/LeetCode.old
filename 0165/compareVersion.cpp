#include <string>
#include <sstream>

using namespace std;

class Solution
{
	stringstream ss;

	int readNumber(string &str, int &start)
	{
		auto len = str.size();
		auto count = 0;
		for (; start < len&&str[start] != '.'; start++)
		{
			ss << str[start];
			count++;
		}
		if (count == 0)
		{
			return 0;
		}
		int result;
		ss >> result;
		ss.str("");
		ss.clear();
		return result;
	}

public:
	int compareVersion(string version1, string version2)
	{
		auto leftLen = version1.size();
		auto rightLen = version2.size();
		auto leftIndex = 0;
		auto rightIndex = 0;
		while (leftIndex < leftLen || rightIndex < rightLen)
		{
			auto left = readNumber(version1, leftIndex);
			leftIndex++;
			auto right = readNumber(version2, rightIndex);
			rightIndex++;
			if (left > right)
			{
				return 1;
			}
			if (right > left)
			{
				return -1;
			}
		}
		return 0;
	}
};

int main()
{
	auto var = Solution().compareVersion("1", "1.1");
	return 0;
}