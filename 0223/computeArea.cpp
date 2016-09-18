#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	int getOverlappedArea(int A, int B, int C, int D, int E, int F, int G, int H)
	{
		auto xDiff = abs(E + G - A - C) / 2;
		auto yDiff = abs(B + D - F - H) / 2;
		if (xDiff > (C - A + G - E) / 2 || yDiff > (D - B + H - F) / 2)
		{
			return 0;
		}
		vector<int> x{ A,C,E,G };
		vector<int> y{ B,D,F,H };
		sort(x.begin(), x.end());
		sort(y.begin(), y.end());
		return (x[2] - x[1])*(y[2] - y[1]);
	}

public:
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
	{
		auto area1 = (C - A)*(D - B);
		auto area2 = (G - E)*(H - F);
		return area1 + area2 - getOverlappedArea(A, B, C, D, E, F, G, H);
	}
};

int main()
{
	auto var = Solution().computeArea(0, 0, 0, 0, -1, -1, 1, 1);
	return 0;
}