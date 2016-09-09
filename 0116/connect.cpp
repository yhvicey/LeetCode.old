#include<queue>

using namespace std;

struct TreeLinkNode
{
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL)
	{
	}
};

class Solution
{
	queue<TreeLinkNode*> _tree;

	void traverse()
	{
		if (_tree.empty())
		{
			return;
		}
		TreeLinkNode* last = NULL;
		int len = _tree.size();
		for (int i = 0; i < len; i++)
		{
			if (last)
			{
				last->next = _tree.front();
			}
			if (_tree.front())
			{
				last = _tree.front();
				_tree.push(_tree.front()->left);
				_tree.push(_tree.front()->right);
			}
			_tree.pop();
		}
		traverse();
	}

public:
	void connect(TreeLinkNode* root)
	{
		_tree.push(root);
		traverse();
	}
};

int main()
{
	return 0;
}