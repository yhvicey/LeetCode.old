#include<queue>

using namespace std;

class Stack
{
	queue<int> queueLeft;

	queue<int> queueRight;

public:
	void push(int x)
	{
		if (queueLeft.empty())
		{
			queueRight.push(x);
		}
		else
		{
			queueLeft.push(x);
		}
	}

	void pop()
	{
		if (queueLeft.empty())
		{
			while (queueRight.size() != 1)
			{
				queueLeft.push(queueRight.front());
				queueRight.pop();
			}
			queueRight.pop();
		}
		else
		{
			while (queueLeft.size() != 1)
			{
				queueRight.push(queueLeft.front());
				queueLeft.pop();
			}
			queueLeft.pop();
		}
	}

	int top()
	{
		int result = 0;
		if (queueLeft.empty())
		{
			while (!queueRight.empty())
			{
				result = queueRight.front();
				queueLeft.push(result);
				queueRight.pop();
			}
			return result;
		}
		else
		{
			while (!queueLeft.empty())
			{
				result = queueLeft.front();
				queueRight.push(result);
				queueLeft.pop();
			}
			return result;
		}
	}

	bool empty()
	{
		return queueLeft.empty() && queueRight.empty();
	}
};

int main()
{
	return 0;
}