#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
	{
		unordered_map<int, int> record;
		for (auto num : nums1)
		{
			record[num] = 1;
		}
		for (auto num : nums2)
		{
			if (record[num])
			{
				record[num] = 2;
			}
		}
		vector<int> result;
		for (auto pair : record)
		{
			if (pair.second == 2)
			{
				result.push_back(pair.first);
			}
		}
		return result;
	}
};

int main()
{
	return 0;
}