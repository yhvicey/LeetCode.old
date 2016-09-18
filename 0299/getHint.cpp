#include <string>
#include <sstream>

using namespace std;

class Solution
{
public:
	string getHint(string secret, string guess)
	{
		int record[10];
		auto bull = 0;
		auto cow = 0;
		memset(record, 0, sizeof(record));
		for (auto ch : secret)
		{
			record[ch - '0']++;
		}
		for (auto i = 0;i < secret.size();i++)
		{
			if (guess[i] == secret[i])
			{
				record[guess[i] - '0']--;
				bull++;
			}
		}
		for (auto i = 0;i < secret.size();i++)
		{
			if (guess[i] != secret[i])
			{
				if (record[guess[i] - '0'])
				{
					record[guess[i] - '0']--;
					cow++;
				}
			}
		}
		stringstream ss;
		ss << bull << "A" << cow << "B";
		return ss.str();
	}
};

int main()
{
	auto var = Solution().getHint("1122", "1222");
	return 0;
}