#include<vector>

using namespace std;

class Solution
{
	int binarySearch(vector<int> &nums, int start, int end, int target)
	{
		if (start > end)
		{
			return start;
		}
		int mid = start + (end - start) / 2;
		if (nums[mid] == target)
		{
			return mid;
		}
		if (nums[mid] < target)
		{
			return binarySearch(nums, mid + 1, end, target);
		}
		else
		{
			return binarySearch(nums, start, mid - 1, target);
		}
		
	}

public:
	int searchInsert(vector<int>& nums, int target)
	{
		int start = 0;
		int end = nums.size() - 1;
		return binarySearch(nums, start, end, target);
	}
};

int main()
{
	auto var = Solution().searchInsert(vector<int>{1}, 2);
}