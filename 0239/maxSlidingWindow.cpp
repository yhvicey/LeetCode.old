#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k)
	{
		if (nums.size() == 0)
		{
			return nums;
		}
		auto curMax = INT_MIN;
		auto curMaxIndex = 0;
		vector<int> result;
		for (auto i = 0; i < k; i++)
		{
			if (nums[i] > curMax)
			{
				curMax = nums[i];
				curMaxIndex = i;
			}
		}
		result.push_back(curMax);
		for (auto i = k; i < nums.size(); i++)
		{
			if (nums[i] > curMax)
			{
				curMax = nums[i];
				curMaxIndex = i;
				result.push_back(curMax);
				continue;
			}
			if (curMaxIndex <= i - k)
			{
				curMax = INT_MIN;
				for (auto j = curMaxIndex + 1; j <= i; j++)
				{
					if (nums[j] > curMax)
					{
						curMax = nums[j];
						curMaxIndex = j;
					}
				}
			}
			result.push_back(curMax);
		}
		return result;
	}
};

int main()
{
	auto var = Solution().maxSlidingWindow(vector<int>{1, 3, -1, -3, 5, 3, 6, 7}, 1);
	return 0;
}