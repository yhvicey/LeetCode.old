#include <string>

using namespace std;

class Solution
{
public:
	string reverseString(string s)
	{
		int slow = 0;
		int fast = s.size() - 1;
		while (slow < fast)
		{
			char temp = s[slow];
			s[slow] = s[fast];
			s[fast] = temp;
			slow++;
			fast--;
		}
		return s;
	}
};

int main()
{
	return 0;
}