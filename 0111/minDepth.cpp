#include<algorithm>

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
public:
	int minDepth(TreeNode* root)
	{
		if (!root)
		{
			return 0;
		}
		if (root->left && !root->right)
		{
			return minDepth(root->left) + 1;
		}
		if (!root->left && root->right)
		{
			return minDepth(root->right) + 1;
		}
		if (!root->left && !root->right)
		{
			return 1;
		}
		return min(minDepth(root->left), minDepth(root->right)) + 1;
	}
};

int main()
{
	TreeNode root(0);
	root.left = new TreeNode(2);
	auto var = Solution().minDepth(&root);
	return 0;
}