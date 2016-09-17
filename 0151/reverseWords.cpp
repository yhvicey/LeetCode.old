#include <string>
#include <sstream>

using namespace std;

class Solution
{
	static void preProcess(string &str)
	{
		int len = str.size();
		auto last = 0;
		for (auto i = 0; i < len; i++)
		{
			while (str[i] == ' '&&i < len)
			{
				i++;
			}
			while (str[i] != ' ')
			{
				str[last++] = str[i++];
				if (i >= len)
				{
					last++;
					break;
				}
			}
			if (i < len)
			{
				str[last++] = ' ';
			}
		}
		str = last == 0 ? "" : str.substr(0, last - 1);
	}

	static void reverse(string &str, int start, int end)
	{
		while (start < end)
		{
			auto t = str[end];
			str[end] = str[start];
			str[start] = t;
			start++;
			end--;
		}
	}

public:
	static void reverseWords(string &s)
	{
		preProcess(s);
		if (s == " ")
		{
			s = "";
		}
		reverse(s, 0, s.size() - 1);
		auto last = 0;
		for (auto i = 0; i < s.size(); i++)
		{
			if (s[i] == ' ')
			{
				reverse(s, last, i - 1);
				last = i + 1;
			}
		}
		if (last != s.size())
		{
			reverse(s, last, s.size() - 1);
		}
	}
};

int main()
{
	string str = "   a   ";
	Solution().reverseWords(str);
	return 0;
}