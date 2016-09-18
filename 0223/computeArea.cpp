#include <cmath>

class Solution
{
public:
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
	{
		auto width = (C - A + G - E - abs(E + G - A - C)) / 2;
		auto height = (D - B + H - F - abs(F + H - B - D)) / 2;
		auto area1 = (C - A)*(D - B);
		auto area2 = (G - E)*(H - F);
		auto area3 = width*height;
		if (width > 0 && height > 0)
		{
			return area3;
		}
		return area1 + area2;
	}
};

int main()
{
	auto var = Solution().computeArea(0, 0, 0, 0, -1, -1, 1, 1);
	return 0;
}