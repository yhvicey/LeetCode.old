#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
	{
		unordered_map<int, pair<int,int>> record;
		for (auto num : nums1)
		{
			record[num].first++;
			record[num].second++;
		}
		for (auto num : nums2)
		{
			if (record[num].first)
			{
				record[num].first--;
			}
		}
		vector<int> result;
		for (auto pair : record)
		{
			if (pair.second.second)
			{
				while (pair.second.first++ < pair.second.second)
				{
					result.push_back(pair.first);
				}
			}
		}
		return result;
	}
};

int main()
{
	Solution().intersect(vector<int>{1}, vector<int>{1,1});
	return 0;
}