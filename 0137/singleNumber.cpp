#include<vector>

using namespace std;

class Solution
{
public:
	int singleNumber(vector<int>& nums)
	{
		int bytes[32];
		memset(bytes, 0, sizeof(int) * 32);
		for (auto num : nums)
		{
			int pos = 0;
			while (pos < 32)
			{
				if (num & 1)
				{
					bytes[31 - pos]++;
				}
				num = num >> 1;
				pos++;
			}
		}
		int result = 0;
		for (int i = 0; i < 32; i++)
		{
			result = result * 2 + bytes[i] % 3;
		}
		return result;
	}
};

int main()
{
	auto var = Solution().singleNumber(vector<int>{1});
	return 0;
}