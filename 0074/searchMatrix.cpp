#include<vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target)
{
	int m = matrix.size();
	if (m == 0)
	{
		return false;
	}
	int n = matrix[0].size();
	if (n == 0)
	{
		return false;
	}
	for (int i = 0; i < m; i++)
	{
		if (matrix[i][n - 1] >= target)
		{
			for (int j = n - 1; j >= 0; j--)
			{
				if (matrix[i][j] == target)
				{
					return true;
				}
				if (matrix[i][j] < target)
				{
					return false;
				}
			}
			return false;
		}
	}
	return false;
}

int main()
{
	searchMatrix(vector<vector<int>>{vector<int>{1}, vector<int>{3}}, 3);
	return 0;
}