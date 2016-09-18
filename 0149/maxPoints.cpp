#include <vector>
#include <map>

using namespace std;

struct Point
{
	int x;
	int y;
	Point() : x(0), y(0)
	{
	}
	Point(int a, int b) : x(a), y(b)
	{
	}
};

class Solution
{
	map<double, int> _pointCount;

public:
	int maxPoints(vector<Point>& points)
	{
		int result = 0;
		int len = points.size();
		for (int i = 0; i < len; i++)
		{
			_pointCount.clear();
			int verticalCount = 0;
			int count = 1;
			int max = 0;
			for (int j = i + 1; j < len; j++)
			{
				//in same place
				if (points[i].x == points[j].x&&points[i].y == points[j].y)
				{
					count++;
					continue;
				}
				//k does not exist
				if (points[i].x == points[j].x)
				{
					verticalCount++;
					max = verticalCount > max ? verticalCount : max;
				}
				else
				{
					double k = (double)(points[i].y - points[j].y) / (double)(points[i].x - points[j].x);
					_pointCount[k]++;
					max = _pointCount[k] > max ? _pointCount[k] : max;
				}
			}
			result = result > (max + count) ? result : (max + count);
		}
		return result;
	}
};

int main()
{
	auto var = Solution().maxPoints(vector<Point>{Point{ 0, 0 }, Point{ 1, 1 }, Point{ 1, -1 }	});
	return 0;
}