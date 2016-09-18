#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
	vector<int> searchRange(vector<int>& nums, int target)
	{
		int front = 0;
		int back = nums.size() - 1;
		int begin = 0;
		int end = 0;
		int mid = 0;
		if (front == back)
		{
			if (target == nums[0])
			{
				return vector<int>{0, 0};
			}
			else
			{
				return vector<int>{-1, -1};
			}
		}
		while (front <= back - 1)
		{
			if (front == back - 1)
			{
				if (nums[front] == target&&nums[back] == target)
				{
					return vector<int>{front, back};
				}
				if (nums[front] != target&&nums[back] == target)
				{
					return vector<int>{back, back};
				}
				if (nums[front] == target&&nums[back] != target)
				{
					return vector<int>{front, front};
				}
				if (nums[front] != target&&nums[back] != target)
				{
					return vector<int>{-1, -1};
				}
			}
			mid = (front + back) / 2;
			if (nums[mid] == target)
			{
				begin = end = mid;
				while (nums[begin] == target)
				{
					begin--;
					if (begin == -1)
					{
						break;
					}
				}
				while (nums[end] == target)
				{
					end++;
					if (end == nums.size())
					{
						break;
					}
				}
				return vector<int>{begin + 1, end - 1};
			}
			if (nums[mid] < target)
			{
				front = mid;
			}
			else
			{
				back = mid;
			}
		}
		return vector<int>{-1, -1};
	}
};

int main()
{
	Solution sln;
	auto var = sln.searchRange(vector<int>{1, 2, 2}, 2);
}