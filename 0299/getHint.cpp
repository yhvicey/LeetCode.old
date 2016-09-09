#include<string>

using namespace std;

class Solution
{
	int record[10];
	int bull = 0;
	int cow = 0;
public:
	string getHint(string secret, string guess)
	{
		memset(record, 0, sizeof(int) * 10);
		for (auto ch : secret)
		{
			record[ch - '0']++;
		}
		int len = guess.size();
		for (int i = 0; i < len; i++)
		{
			if (guess[i] == secret[i])
			{
				bull++;
			}
			else
			{
				if (record[guess[i] - '0']-- > 0)
				{
					cow++;
				}
			}
		}
		char buffer[5];
		sprintf(buffer, "%dA%dB", bull, cow);
		return buffer;
	}
};

int main()
{
	auto var = Solution().getHint("1122", "1222");
	return 0;
}