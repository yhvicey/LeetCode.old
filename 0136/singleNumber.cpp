#include <vector>
#include <map>

using namespace std;

class Solution
{
	map<int, int> _record;
public:
	int singleNumber(vector<int>& nums)
	{
		int len = nums.size();
		for (int i = 0; i < len; i++)
		{
			_record[nums[i]]++;
		}
		for (auto it = _record.begin(); it != _record.end(); it++)
		{
			if (it->second == 1)
			{
				return it->first;
			}
		}
		return -1;
	}
};

int main()
{
	return 0;
}