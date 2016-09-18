#include <vector>

using namespace std;

class Solution
{
public:
	int majorityElement(vector<int>& nums)
	{
		int count = 1;
		int lastNum = nums[0];
		int len = nums.size();
		for (int i = 1; i < len; i++)
		{
			if (nums[i] != lastNum)
			{
				count--;
				if (!count)
				{
					lastNum = nums[i];
					count = 1;
				}
			}
			else
			{
				count++;
			}
		}
		return lastNum;
	}
};

int main()
{
	return 0;
}