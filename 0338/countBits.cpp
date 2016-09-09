#include<vector>

using namespace std;

class Solution
{
public:
	int bitCount(int num)
	{
		if (num == 0)
		{
			return 0;
		}
		int count = 1;
		while (num = num&(num - 1))
		{
			count++;
		}
		return count;
	}

	vector<int> countBits(int num)
	{
		vector<int> result;
		for (int i = 0; i <= num; i++)
		{
			result.push_back(bitCount(i));
		}
		return result;
	}
};

int main()
{
	return 0;
}