#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution
{
	map<int, map<int, int>> _map;

	int len = 0;

	int judge(vector<int>& prices, int day, int count, int cash)
	{
		if (_map[day][count] > cash)
		{
			return _map[day][count];
		}
		if (count == 0)
		{
			if (day >= len)
			{
				return _map[day][count] = cash;
			}
			else
			{
				return _map[day][count] = judge(prices, day + 1, count + 1, cash - prices[day]);
			}
		}
		else
		{
			if (day >= len)
			{
				return _map[day][count] = cash + prices[day];
			}
			else
			{
				return _map[day][count] = max(judge(prices, day + 1, count + 1, cash - prices[day]), judge(prices, day + 1, count - 1, cash + prices[day]));
			}
		}
	}

public:
	int maxProfit(vector<int>& prices)
	{
		len = prices.size() - 1;
		return judge(prices, 0, 0, 10000) - 10000;
	}
};

int main()
{
	auto var = Solution().maxProfit(vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
	return 0;
}