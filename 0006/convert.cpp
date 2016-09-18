#include <string>
using namespace std;

string convert(string s, int numRows)
{
	if (numRows < 2)
	{
		return s;
	}
	int len = s.length();
	int groupCount = len / (2 * numRows - 2);
	int leftLen = len - groupCount*(2 * numRows - 2);
	string result = "";

	//first element
	for (int i = 0; i < groupCount; i++)
	{
		result += s[i*(2 * numRows - 2)];
	}
	if (leftLen > 0)
	{
		result += s[groupCount*(2 * numRows - 2)];
	}
	
	//middle elements
	for (int j = 1; j < numRows - 1; j++)
	{
		for (int i = 0; i < groupCount; i++)
		{
			result += s[i*(2 * numRows - 2) + j];
			result += s[(i + 1)*(2 * numRows - 2) - j];
		}	
		if (leftLen > j)
		{
			result += s[groupCount*(2 * numRows - 2) + j];
		}
		if (leftLen > 2 * numRows - 2 - j)
		{
			result += s[(groupCount + 1)*(2 * numRows - 2) - j];
		}
	}
	
	//last element
	for (int i = 0; i < groupCount; i++)
	{
		result += s[i*(2 * numRows - 2) + numRows - 1];
	}
	if (leftLen > numRows - 1)
	{
		result += s[groupCount*(2 * numRows - 2) + numRows - 1];
	}

	return result;
}

int main()
{
	convert("ABC", 3);
}