#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution
{
public:
	int maxProfit(vector<int>& prices)
	{
		auto maxProfit = 0;
		auto len = prices.size();
		auto dp = new int[len];
		dp[0] = 0;
		for (auto i = 1;i < len;i++)
		{
			auto prevMin = prices[i - 1] - dp[i - 1];
			dp[i] = prices[i] - (prevMin > prices[i - 1] ? prices[i - 1] : prevMin);
			if (dp[i] > maxProfit)
			{
				maxProfit = dp[i];
			}
		}
		return maxProfit;
	}
};

int main()
{
	auto var = Solution().maxProfit(vector<int>{7, 1, 5, 3, 6, 4});
	return 0;
}