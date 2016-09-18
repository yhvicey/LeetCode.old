#include <string>
#include <stack>
using namespace std;

bool isValid(string s)
{
	stack<char> stack;
	int len = s.length();
	for (int i = 0; i < len; i++)
	{
		char back = s[i];
		if ((back == ')') || (back == '}') || (back == ']'))
		{
			if (stack.empty())
			{
				return false;
			}
			char front = stack.top();
			if (!((front == '('&&back == ')') || (front == '['&&back == ']') || (front == '{'&&back == '}')))
			{
				return false;
			}
			stack.pop();
		}
		else
		{
			stack.push(s[i]);
		}
	}
	return stack.empty();
}

int main()
{
	isValid("()");
	return 0;
}