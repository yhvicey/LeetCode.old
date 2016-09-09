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
	vector<int> _tree;

	void traverse(TreeNode* root)
	{
		if (!root)
		{
			return;
		}
		traverse(root->left);
		traverse(root->right);
		_tree.push_back(root->val);
	}

public:
	vector<int> postorderTraversal(TreeNode* root)
	{
		traverse(root);
		return _tree;
	}
};

int main()
{
	return 0;
}