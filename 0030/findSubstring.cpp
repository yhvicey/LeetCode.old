#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
	vector<int> findSubstring(string s, vector<string>& words)
	{
		auto len = words.size();
		auto result = vector<int>();
		if (len == 0)
		{
			return result;
		}
		auto slow = 0;
		auto flags = new int[len];
		memset(flags, 0, sizeof(flags));
		for (auto fast = 0;fast < len;fast++)
		{

		}
	}
};

int main()
{
	Solution sln;
	//auto var = sln.findSubstring();
	return 0;
}