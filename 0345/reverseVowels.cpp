#include<string>
#include<map>

using namespace std;

class Solution
{
	map<char, int> _map{
		pair<char,int>{'a',1},
		pair<char,int>{'e',1},
		pair<char,int>{'i',1},
		pair<char,int>{'o',1},
		pair<char,int>{'u',1},
		pair<char,int>{'A',1}, 
		pair<char,int>{'E',1}, 
		pair<char,int>{'I',1}, 
		pair<char,int>{'O',1}, 
		pair<char,int>{'U',1}, };

public:
	string reverseVowels(string s)
	{
		int slow = 0;
		int fast = s.size() - 1;
		while (slow < fast)
		{
			while (!_map[s[slow]] && slow < fast)
			{
				slow++;
			}
			while (!_map[s[fast]] && slow < fast)
			{
				fast--;
			}
			if (slow < fast)
			{
				char temp = s[slow];
				s[slow] = s[fast];
				s[fast] = temp;
				slow++;
				fast--;
			}
		}
		return s;
	}
};

int main()
{
	auto var = Solution().reverseVowels("leetcode");
	return 0;
}