#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
	int longestValidParentheses(string s)
	{
		if(s.empty())
		{
			return 0;
		}
		unordered_map<int, int> dp;
		auto len = s.size();
		auto left = 0;
		auto right = 0;
		dp[0] = 0;
		if(s[0]=='(')
		{
			left++;
		}
		if (s[0] == ')')
		{
			right++;
		}
		for (auto i = 1; i < len; i++)
		{
		}
	}
};

int main()
{
	Solution sln;
	auto var = sln.longestValidParentheses("()(()");
	return 0;
}