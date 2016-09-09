#include<vector>
#include<string>
using namespace std;

vector<vector<string>> map
{
	vector<string>{"a", "b", "c"},
	vector<string>{"d", "e", "f"},
	vector<string>{"g", "h", "i"},
	vector<string>{"j", "k", "l"},
	vector<string>{"m", "n", "o"},
	vector<string>{"p", "q", "r", "s"},
	vector<string>{"t", "u", "v"},
	vector<string>{"w", "x", "y", "z"}
};

vector<string> getLetters(char digit)
{
	return map[digit - 50];
}

vector<string> letterCombinations(string digits)
{
	vector<string> result;
	vector<string> letters;
	vector<string> temp;
	int len = digits.length();
	for (int i = 0; i < len; i++)
	{
		letters = getLetters(digits[i]);
		int resultLen = result.size();
		int lettersLen = letters.size();
		if (resultLen == 0)
		{
			result.insert(result.end(), letters.begin(), letters.end());
		}
		else
		{
			for (int j = 0; j < resultLen; j++)
			{
				for (int k = 0; k < lettersLen; k++)
				{
					temp.push_back(result[j] + letters[k]);
				}
			}
			result.clear();
			result.insert(result.begin(), temp.begin(), temp.end());
			temp.clear();
		}
	}
	return result;
}

int main()
{
	letterCombinations("22");
	return 0;
}