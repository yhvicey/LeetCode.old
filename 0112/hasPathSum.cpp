#define NULL 0

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
	bool hasPathSum(TreeNode* root, int sum)
	{
		if (!root)
		{
			return false;
		}
		if (!root->left && !root->right)
		{
			if (sum - root->val == 0)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
	}
};

int main()
{
	TreeNode root(1);
	root.left = new TreeNode(2);
	auto var = Solution().hasPathSum(&root, 1);
	return 0;
}