#include<vector>

using namespace std;

class Solution
{
	vector<vector<int>> result;

	void build(int num)
	{
		if (num == 0)
		{
			result.push_back(vector<int>{1});
			return;
		}
		vector<int> temp{ 1 };
		for (int i = 1; i < num; i++)
		{
			temp.push_back(result[num - 1][i - 1] + result[num - 1][i]);
		}
		temp.push_back(1);
		result.push_back(temp);
	}

public:
	vector<int> getRow(int numRows)
	{
		for (int i = 0; i < numRows + 1; i++)
		{
			build(i);
		}
		return result.back();
	}
};

int main()
{
	auto var = Solution().getRow(5);
	return 0;
}