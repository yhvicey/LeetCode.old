#include <vector>

using namespace std;

class Solution
{
public:
	void moveZeroes(vector<int>& nums)
	{
		int slow = 0;
		int fast = 0;
		int len = nums.size();
		for (; fast < len; fast++)
		{
			if (nums[slow] == 0)
			{
				if (nums[fast] == 0)
				{
					continue;
				}
				else
				{
					nums[slow] = nums[fast];
					nums[fast] = 0;
					slow++;
				}
			}
			else
			{
				slow++;
			}
		}
	}
};

int main()
{
	Solution sln;
	sln.moveZeroes(vector<int>{0, 1, 0, 2, 12});
	return 0;
}