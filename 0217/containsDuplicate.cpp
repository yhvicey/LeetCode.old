#include <vector>
#include <map>

using namespace std;

class Solution
{
	map<int,int> exist;
public:
	bool containsDuplicate(vector<int>& nums)
	{
		int len = nums.size();
		for (int i = 0; i < len; i++)
		{
			if (exist[nums[i]])
			{
				return true;
			}
			else
			{
				exist[nums[i]] = 1;
			}
		}
		return false;
	}
};

int main()
{
	return 0;
}