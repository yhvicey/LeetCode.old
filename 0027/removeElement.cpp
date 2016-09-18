#include <vector>
using namespace std;

class Solution
{
public:
	int removeElement(vector<int>& nums, int val)
	{
		int last = 0;
		int len = nums.size();
		for (int i = 0; i < len; i++)
		{
			if (nums[i] == val)
			{
				continue;
			}
			else
			{
				nums[last] = nums[i];
				last++;
			}
		}
		return last;
	}
};

int main()
{
	return 0;
}