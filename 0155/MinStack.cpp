#include <stack>

using namespace std;

class MinStack
{
	stack<int> _stack;

	stack<int> _minStack;

	int _currentMin;

public:
	MinStack() :
		_currentMin(INT_MAX)
	{

	}

	void push(int x)
	{
		_stack.push(x);
		_currentMin = x < _currentMin ? x : _currentMin;
		_minStack.push(_currentMin);
	}

	void pop()
	{
		_stack.pop();
		_minStack.pop();
		_currentMin = _minStack.empty() ? INT_MAX : _minStack.top();
	}

	int top()
	{
		return _stack.top();
	}

	int getMin()
	{
		return _currentMin;
	}
};

int main()
{
	MinStack stack;
	stack.push(214783646);
	stack.push(214783646);
	stack.push(214783647);
	stack.top();
	stack.pop();
	auto var = stack.getMin();
	stack.pop();
	var = stack.getMin();
	stack.pop();
	stack.push(214783646);
	stack.top();
	var = stack.getMin();
	stack.push(-214783648);
	stack.top();
	var = stack.getMin();
	stack.pop();
	var = stack.getMin();
	return 0;
}