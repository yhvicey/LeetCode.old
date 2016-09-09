#include<string>
using namespace std;

class Solution
{
public:
	int longestValidParentheses(string s)
	{
		int slow = 0;
		int fast = 0;
		int leftCount = 0;
		int rightCount = 0;
		int maxLength = 0;
		bool moveSlow = false;
		int len = s.size();
		for (; fast<len;)
		{
			if (moveSlow)
			{
				if (s[slow] == '(')
				{
					leftCount--;
				}
				else
				{
					rightCount--;
				}
				slow++;

				if (slow == fast)
				{
					moveSlow = false;
					continue;
				}

				if (leftCount < rightCount)
				{
					continue;
				}
				else if (leftCount == rightCount)
				{
					maxLength = maxLength > (fast - slow) ? maxLength : (fast - slow);
				}
				else
				{
					moveSlow = false;
				}
			}
			else
			{
				if (s[fast] == '(')
				{
					leftCount++;
				}
				else
				{
					rightCount++;
				}
				fast++;

				if (leftCount < rightCount)
				{
					moveSlow = true;
				}
				else if (leftCount == rightCount)
				{
					maxLength = maxLength >(fast - slow) ? maxLength : (fast - slow);
				}
				else
				{
					continue;
				}
			}
		}
		if (leftCount != rightCount)
		{
			while ((slow <= fast) && (leftCount != rightCount))
			{
				if (s[slow] == '(')
				{
					leftCount--;
				}
				else
				{
					rightCount--;
				}
				slow++;
			}
		}
		if (leftCount == rightCount)
		{
			maxLength = maxLength > (fast - slow) ? maxLength : (fast - slow);
		}
		return maxLength;
	}
};

int main()
{
	Solution sln;
	auto var = sln.longestValidParentheses("()(()");
	return 0;
}