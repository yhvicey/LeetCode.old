#include<vector>

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
	vector<int> _result;

	void traverse(vector<TreeNode*> list)
	{
		if (list.empty())
		{
			return;
		}
		vector<TreeNode*> next;
		_result.push_back(list.back()->val);
		int len = list.size();
		for (int i = 0; i < len; i++)
		{
			if (list[i]->left)
			{
				next.push_back(list[i]->left);
			}
			if (list[i]->right)
			{
				next.push_back(list[i]->right);
			}
		}
		traverse(next);
	}
public:
	vector<int> rightSideView(TreeNode* root)
	{
		if (!root)
		{
			return vector<int>{};
		}
		traverse(vector<TreeNode*>{root});
		return _result;
	}
};

int main()
{
	return 0;
}