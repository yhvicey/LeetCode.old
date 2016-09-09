class Solution
{
public:
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
	{
		if (A >= E&&C <= G&&B >= F&&D <= H)
		{
			return (G - E)*(H - F);
		}
		if (A <= E&&C >= G&&B <= F&&D >= H)
		{
			return (C - A)*(D - B);
		}
		int total = (C - A)*(D - B) + (G - E)*(H - F);
		if (A > G || B > H || C < E || D < F)
		{
			return total;
		}
		if (A > E)
		{
			if (F > B)
			{
				return total - (G - A)*(D - F);
			}
			else
			{
				return total - (G - A)*(H - B);
			}
		}
		else
		{
			if (F > B)
			{
				return total - (C - E)*(D - F);
			}
			else
			{
				return total - (C - E)*(H - B);
			}
		}
	}
};

int main()
{
	auto var = Solution().computeArea(-2, -2, 2, 2, 3, 3, 4, 4);
	return 0;
}