#include<vector>

using namespace std;

class Solution
{
	int hashMap[9];

	bool checkRow(int row, vector<vector<char>> &board)
	{
		for (int i = 0; i < 9; i++)
		{
			char value = board[i][row];
			if (value != '.')
			{
				if (hashMap[value - '0' - 1])
				{
					return false;
				}
				else
				{
					hashMap[value - '0' - 1] = 1;
				}
			}
		}
		memset(hashMap, 0, sizeof(int) * 9);
		return true;
	}

	bool checkLine(int line, vector<vector<char>> &board)
	{
		for (int i = 0; i < 9; i++)
		{
			char value = board[line][i];
			if (value != '.')
			{
				if (hashMap[value - '0' - 1])
				{
					return false;
				}
				else
				{
					hashMap[value - '0' - 1] = 1;
				}
			}
		}
		memset(hashMap, 0, sizeof(int) * 9);
		return true;
	}

	bool checkBlock(int x, int y, vector<vector<char>> &board)
	{
		for (int i = 3 * y; i < 3 * y + 3; i++)
		{
			for (int j = 3 * x; j < 3 * x + 3; j++)
			{
				char value = board[i][j];
				if (value != '.')
				{
					if (hashMap[value - '0' - 1])
					{
						return false;
					}
					else
					{
						hashMap[value - '0' - 1] = 1;
					}
				}
			}
		}
		memset(hashMap, 0, sizeof(int) * 9);
		return true;
	}

	bool checkAllRows(vector<vector<char>> &board)
	{
		for (int x = 0; x < 9; x++)
		{
			if (!checkRow(x, board))
			{
				return false;
			}
		}
		return true;
	}

	bool checkAllLines(vector<vector<char>> &board)
	{
		for (int x = 0; x < 9; x++)
		{
			if (!checkLine(x, board))
			{
				return false;
			}
		}
		return true;
	}

	bool checkAllBlocks(vector<vector<char>> &board)
	{
		for (int y = 0; y < 3; y++)
		{
			for (int x = 0; x < 3; x++)
			{
				if (!checkBlock(x, y, board))
				{
					return false;
				}
			}
		}
		return true;
	}

public:
	bool isValidSudoku(vector<vector<char>>& board)
	{
		memset(hashMap, 0, sizeof(int) * 9);
		return checkAllBlocks(board) && checkAllLines(board) && checkAllRows(board);
	}
};

int main()
{
	auto param = vector<vector<char>>{
		vector<char>{'.','8','7','6','5','4','3','2','1'},
		vector<char>{'2','.','.','.','.','.','.','.','.'},
		vector<char>{'3','.','.','.','.','.','.','.','.'},
		vector<char>{'4','.','.','.','.','.','.','.','.'},
		vector<char>{'5','.','.','.','.','.','.','.','.'},
		vector<char>{'6','.','.','.','.','.','.','.','.'},
		vector<char>{'7','.','.','.','.','.','.','.','.'},
		vector<char>{'8','.','.','.','.','.','.','.','.'},
		vector<char>{'9','.','.','.','.','.','.','.','.'},
	};
	auto var = Solution().isValidSudoku(param);
	return 0;
}