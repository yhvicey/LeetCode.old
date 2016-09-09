#include<vector>
#include<stack>
#include<queue>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL)
	{
	}
};

class Solution
{
	queue<TreeNode*> _queue;

	vector<vector<int>> _result;

public:
	vector<vector<int>> levelOrder(TreeNode* root)
	{
		if (!root)
		{
			return vector<vector<int>>{};
		}
		_queue.push(root);
		while (!_queue.empty())
		{
			vector<int> temp;
			int len = _queue.size();
			for (int i = 0; i < len; i++)
			{
				auto node = _queue.front();
				temp.push_back(node->val);
				if (node->left)
				{
					_queue.push(node->left);
				}
				if (node->right)
				{
					_queue.push(node->right);
				}
				_queue.pop();
			}
			_result.push_back(temp);
		}
		return _result;
	}
};

int main()
{
	TreeNode root(1);
	auto var = Solution().levelOrder(&root);
	return 0;
}