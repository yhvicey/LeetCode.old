#include <vector>
#include <unordered_map>

using namespace std;

class NumArray
{
private:
	unordered_map<int, int> _sums;

public:
	NumArray(vector<int> &nums)
	{
		if (nums.empty())
		{
			return;
		}
		_sums[0] = nums[0];
		for (auto i = 1; i < nums.size(); i++)
		{
			_sums[i] = _sums[i - 1] + nums[i];
		}
	}

	int sumRange(int i, int j)
	{
		return i == 0 ? _sums[j] : (_sums[j] - _sums[i - 1]);
	}
};

int main()
{
	auto array = vector<int>{ -2,0,3,-5,2,-1 };
	NumArray numArray(array);
	auto var = numArray.sumRange(2, 5);
	return 0;
}