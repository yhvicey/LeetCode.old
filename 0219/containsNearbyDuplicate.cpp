#include <vector>
#include <map>

using namespace std;

class Solution
{
	map<int, int> _record;

public:
	bool containsNearbyDuplicate(vector<int>& nums, int k)
	{
		int len = nums.size();
		if (len <= 1)
		{
			return false;
		}
		int firstValue = nums[0];
		for (int i = 1; i < len; i++)
		{
			auto index = _record[nums[i]];
			if (index || nums[i] == firstValue)
			{
				if (i - index <= k)
				{
					return true;
				}
			}
			_record[nums[i]] = i;
		}
		return false;
	}
};

int main()
{
	auto var = Solution().containsNearbyDuplicate(vector<int>{1, 2}, 2);
	return 0;
}