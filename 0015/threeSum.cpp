#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution 
{
	unordered_map<int, unordered_map<int, int>> _set;

	void twoSum(vector<int>& nums, int target, int front)
	{
		int back = nums.size();
		for (auto i = front + 1;i < back;i++)
		{
			for (auto j = i + 1;j < back;j++)
			{
				if (target + nums[i] + nums[j] == 0)
				{
					auto minNum = min(min(target, nums[i]), nums[j]);
					auto maxNum = max(max(target, nums[i]), nums[j]);
					auto midNum = target + nums[i] + nums[j] - maxNum - minNum;
					_set[minNum][midNum] = maxNum;
				}
			}
		}
	}

public:
	vector<vector<int>> threeSum(vector<int>& nums)
	{
		vector<vector<int>> result;

		int back = nums.size();
		for (auto i = 0;i < back - 2;i++)
		{
			twoSum(nums, nums[i], i);
		}

		for (auto pair1 : _set)
		{
			for (auto pair2 : pair1.second)
			{
				result.push_back(vector<int>{pair1.first, pair2.first, pair2.second});
			}
		}

		return result;
	}
};

int main()
{
	auto var = Solution().threeSum(vector<int>{7, -1, 14, -12, -8, 7, 2, -15, 8, 8, -8, -14, -4, -5, 7, 9, 11, -4, -15, -6, 1, -14, 4, 3, 10, -5, 2, 1, 6, 11, 2, -2, -5, -7, -6, 2, -15, 11, -6, 8, -4, 2, 1, -1, 4, -6, -15, 1, 5, -15, 10, 14, 9, -8, -6, 4, -6, 11, 12, -15, 7, -1, -9, 9, -1, 0, -4, -1, -12, -2, 14, -9, 7, 0, -3, -4, 1, -2, 12, 14, -10, 0, 5, 14, -1, 14, 3, 8, 10, -8, 8, -5, -2, 6, -11, 12, 13, -7, -12, 8, 6, -13, 14, -2, -5, -11, 1, 3, -6});
	return 0;
}