#include<algorithm>

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
public:
	int maxDepth(TreeNode* root)
	{
		if (!root)
		{
			return 0;
		}
		return std::max(maxDepth(root->left) + 1, maxDepth(root->right) + 1);
	}
};

int main()
{
	return 0;
}