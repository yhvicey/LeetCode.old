#include<vector>
#include<algorithm>
#include<map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target)
{
	map<int, int> map;
	int len = nums.size();
	for (int i = 0; i < len; i++)
	{
		auto it = map.find(target - nums[i]);
		if (it == map.end())
		{
			map.insert(pair<int, int>(nums[i], i));
		}
		else
		{
			return vector<int>{it->second, i};
		}
	}
	return vector<int>{};
}

int main()
{
	twoSum(vector<int>{3,2,4}, 6);
	return 0;
}
