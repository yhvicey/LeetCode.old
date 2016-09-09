#include<vector>
#include<algorithm>

using namespace std;

class Solution
{
	int len;

	int** record;

	int result;

	void rob(vector<int>& nums, int pos, int cash, int robbedJustNow)
	{
		if (pos >= len)
		{
			if (result < cash)
			{
				result = cash;
			}
			return;
		}
		if (record[pos][robbedJustNow] >= cash)
		{
			return;
		}
		else
		{
			record[pos][robbedJustNow] = cash;
		}
		if (robbedJustNow)
		{
			rob(nums, pos + 1, cash, 0);
		}
		else
		{
			rob(nums, pos + 1, cash + nums[pos], 1);
			rob(nums, pos + 1, cash, 0);
		}
	}

public:
	int rob(vector<int>& nums)
	{
		len = nums.size();
		result = 0;
		record = new int*[len];
		for (int i = 0; i < len; i++)
		{
			record[i] = new int[2];
			memset(record[i], -1, sizeof(int) * 2);
		}
		rob(nums, 0, 0, 0);
		return result;
	}
};

int main()
{
	auto var = Solution().rob(vector<int>{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0});
	return 0;
}