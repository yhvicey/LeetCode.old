#include <vector>
using namespace std;

void generate(int left, int right, string str, vector<string> &result)
{
	if (left == 0 && right == 0)
	{
		result.push_back(str);
	}
	if (left > 0)
	{
		generate(left - 1, right, str + '(', result);
	}
	if (right > 0 && left < right)
	{
		generate(left, right - 1, str + ')', result);
	}
}

vector<string> generateParenthesis(int n)
{
	vector<string> result;
	generate(n, n, "", result);
	return result;
}


int main()
{
	auto var = generateParenthesis(5);
	return 0;
}