#include <vector>

using namespace std;

class Solution
{
	vector<int> frontToBack;
	vector<int> backToFront;
public:
	vector<int> productExceptSelf(vector<int>& nums)
	{
		int len = nums.size();
		if (len <= 1)
		{
			return nums;
		}
		int front = 1;
		for (int i = 0; i < len; i++)
		{
			front *= nums[i];
			frontToBack.push_back(front);
		}
		int back = 1;
		for (int i = len - 1; i >= 0; i--)
		{
			back *= nums[i];
			backToFront.push_back(back);
		}
		vector<int> result;
		result.push_back(backToFront[len - 2]);
		for (int i = 1; i < len - 1; i++)
		{
			result.push_back(frontToBack[i - 1] * backToFront[len - i - 2]);
		}
		result.push_back(frontToBack[len - 2]);
		return result;
	}
};

int main()
{
	auto var = Solution().productExceptSelf(vector<int>{1, 0});
	return 0;
}