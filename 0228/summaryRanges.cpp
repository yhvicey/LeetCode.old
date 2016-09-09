#include <vector>
#include <sstream>
using namespace std;

class Solution {
	vector<int> _nums;

	vector<string> _result;

	int _front = 0;

	int _back = 0;

	void solve()
	{
		stringstream ss;

		while (_back <= _nums.size())
		{
			if (_back == _nums.size())
			{
				if (_back == _front + 1)
				{
					ss << _nums[_front];
					_result.push_back(ss.str());
				}
				if (_back > _front + 1)
				{
					ss << _nums[_front] << "->" << _nums[_back - 1];
					_result.push_back(ss.str());
				}
				return;
			}
			if (_back - _front != _nums[_back] - _nums[_front])
			{
				if (_back == _front + 1)
				{
					ss << _nums[_front];
					_front = _back;
				}
				else
				{
					ss << _nums[_front] << "->" << _nums[_back - 1];
					_front = _back;
				}
				_result.push_back(ss.str());
				ss.str("");
			}
			_back++;
		}
	}

public:
	vector<string> summaryRanges(vector<int>& nums) {
		_nums = nums;

		if (_nums.size() < 1)
		{
			return vector<string>{};
		}

		solve();

		return _result;
	}
};

int main()
{
	auto var = Solution().summaryRanges(vector<int> {0, 1, 2, 4, 5, 6,7,9});
}