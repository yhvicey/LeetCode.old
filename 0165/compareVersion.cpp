#include<string>

using namespace std;

class Solution
{
	int compareFromEnd(string left, string right)
	{
		int leftLen = left.size();
		int rightLen = right.size();
		while (leftLen > 0 && rightLen > 0)
		{
			if (left[leftLen - 1] == right[rightLen - 1])
			{
				leftLen--;
				rightLen--;
				continue;
			}
			if (left[leftLen - 1] >= right[rightLen - 1])
			{
				return 1;
			}
			else
			{
				return -1;
			}
		}
		if (leftLen)
		{
			while (leftLen--)
			{
				if (left[leftLen] - '0')
				{
					return 1;
				}
			}
			return 0;
		}
		else
		{
			while (rightLen--)
			{
				if (right[rightLen] - '0')
				{
					return -1;
				}
			}
			return 0;
		}
	}

public:
	int compareVersion(string version1, string version2)
	{
		int leftStart = 0;
		int rightStart = 0;
		int leftCount = 0;
		int rightCount = 0;
		int leftLen = version1.size();
		int rightLen = version2.size();

		while (leftStart + leftCount < leftLen && rightStart + rightCount < rightLen)
		{
			if (version1[leftStart + leftCount] == '.'&& version2[rightStart + rightCount] == '.')
			{
				int result = compareFromEnd(version1.substr(leftStart, leftCount), version2.substr(rightStart, rightCount));
				if (result)
				{
					return result;
				}
				leftStart += (leftCount + 1);
				rightStart += (rightCount + 1);
				leftCount = 0;
				rightCount = 0;
			}
			if (version1[leftLen - 1] != '.')
			{
				leftCount++;
			}
			if (version2[rightLen - 1] != '.')
			{
				rightCount++;
			}
		}
		return (leftLen > rightLen ? 1 : -1);
	}
};

int main()
{
	auto var = Solution().compareVersion("01", "1");
	return 0;
}