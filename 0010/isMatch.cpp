#include <string>
#include <regex>
using namespace std;

class Solution
{
	bool match(const char* s, const char*  p)
	{
		if ((*s == '\0') && (*p == '\0'))
		{
			return true;
		}
		if ((*s == '\0') || (*p == '\0'))
		{
			return false;
		}
		if (*(p + 1) == '*')
		{
			if ((*p == *s) || ((*p == '.') && (*s != '\0')))
			{

				return match(s + 1, p + 2)		//move to next state
					|| match(s + 1, p)					//move to next char
					|| match(s, p + 2);					//ignore it
			}
			else
			{
				return match(s, p + 2);
			}
		}
		else
		{
			if ((*p == *s) || ((*p == '.') && (*s != '\0')))
			{
				return match(s + 1, p + 1);
			}
			else
			{
				return false;
			}
		}
	}
public:
	bool isMatch(string s, string p)
	{
		return match(s.c_str(), p.c_str());
	}
};

int main()
{
	auto var = Solution().isMatch("aaaaaaaaaaaaab", "a*a*a*a*a*a*a*a*a*a*a*a*c");
	return 0;
}