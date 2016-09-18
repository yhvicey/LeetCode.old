#include <string>

using namespace std;

class Solution
{
public:
	int titleToNumber(string s)
	{
		int result = 0;
		int len = s.length();
		for (int i = 0; i < len; i++)
		{
			result = result * 26 + (s[i] - 'A' + 1);
		}
		return result;
	}
};

int main()
{
	return 0;
}