#include <vector>
using namespace std;

int maxArea(vector<int>& height)
{
	int len = height.size();
	int maxS = 0;
	int front = 0;
	int back = len - 1;
	while (front < back)
	{
		int tempS = (height[front]>height[back] ? height[back] : height[front])*(back - front);
		maxS = (maxS > tempS ? maxS : tempS);
		if (height[front] > height[back])
		{
			back--;
		}
		else
		{
			front++;
		}
	}
	return maxS;
}

int main()
{
	return 0;
}