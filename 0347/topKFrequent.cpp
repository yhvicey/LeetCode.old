#include<queue>
#include<vector>
#include<map>

using namespace std;

struct Pair
{
	int Value;

	int Count;

	Pair(int value, int count) :
		Count(count),
		Value(value)
	{

	}

	friend bool operator <(const Pair &left, const Pair &right)
	{
		return left.Count < right.Count;
	}
};

class Solution
{
	map<int, int> table;

	priority_queue<Pair> heap;

	void preprocess(vector<int>& nums)
	{
		int len = nums.size();
		for (int i = 0; i < len; i++)
		{
			table[nums[i]] += 1;
		}

		for (auto it = table.begin(); it != table.end(); it++)
		{
			heap.push(Pair(it->first, it->second));
		}
	}

public:
	vector<int> topKFrequent(vector<int>& nums, int k)
	{
		preprocess(nums);
		vector<int> result;
		for (int i = 0; i < k; i++)
		{
			result.push_back(heap.top().Value);
			heap.pop();
		}
		return result;
	}
};

int main()
{
	auto var = Solution().topKFrequent(vector<int>{-1, -1}, 1);
	return 0;
}