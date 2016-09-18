#include <stack>

using namespace std;

class Queue
{
public:
	void push(int val)
	{
		stackIn.push(val);
	}

	void pop()
	{
		if (stackOut.empty())
		{
			while (!stackIn.empty())
			{
				stackOut.push(stackIn.top());
				stackIn.pop();
			}
		}
		auto var = stackOut.top();
		stackOut.pop();
	}

	int peek()
	{
		if (stackOut.empty())
		{
			while (!stackIn.empty())
			{
				stackOut.push(stackIn.top());
				stackIn.pop();
			}
		}
		return stackOut.top();
	}

	bool empty()
	{
		return stackIn.empty() && stackOut.empty();
	}

private:
	stack<int> stackIn;
	stack<int> stackOut;
};


int main()
{
	Queue queue;
	queue.push(1);
	queue.push(2);
	queue.push(6);
	queue.push(7);
	auto var1 = queue.peek();
	queue.pop();
	auto var2 = queue.peek();
	queue.pop();
	queue.push(3);
	queue.push(4);
	queue.push(5);
	auto var3 = queue.peek();
	queue.pop();
	auto var4 = queue.peek();
	queue.pop();
	auto var5 = queue.peek();
	queue.pop();
	auto var6 = queue.peek();
	queue.pop();
	auto var7 = queue.peek();
	queue.pop();

}