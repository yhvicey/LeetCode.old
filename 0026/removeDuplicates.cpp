#include<vector>
using namespace std;

class Solution
{
public:
	int removeDuplicates(vector<int>& nums)
	{
		int len = nums.size();
		if (len <= 1)
		{
			return len;
		}
		int last = 1;

		for (int i = 1; i < len; i++)
		{
			if (nums[i - 1] != nums[i])
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

}