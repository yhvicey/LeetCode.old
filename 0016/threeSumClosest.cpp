#include <vector>

using namespace std;

class Solution {
	int twoSumClosest(vector<int>& nums, int target, int front)
	{
		auto back = nums.size();
		auto minDiff = INT_MAX;
		for (auto i = front + 1;i < back;i++)
		{
			for (auto j = i + 1;j < back;j++)
			{
				auto diff = target - nums[i] - nums[j];
				if (diff == 0)
				{
					return target;
				}
				if (abs(diff) < abs(minDiff))
				{
					minDiff = diff;
				}
			}
		}
		return target - minDiff;
	}

public:
	int threeSumClosest(vector<int>& nums, int target) {
		auto minDiff = INT_MAX;
		for (auto i = 0;i < nums.size() - 2;i++)
		{
			auto diff = target - nums[i] - twoSumClosest(nums, target - nums[i], i);
			if (diff == 0)
			{
				return target;
			}
			if (abs(diff) < abs(minDiff))
			{
				minDiff = diff;
			}
		}
		return target - minDiff;
	}
};

int main()
{
	auto var = Solution().threeSumClosest(vector<int>{1, 1, -1}, 0);
}
