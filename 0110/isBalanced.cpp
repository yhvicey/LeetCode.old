#include <algorithm>

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


	int maxDepth(TreeNode* root)
	{
		if (!root)
		{
			return 0;
		}
		return max(maxDepth(root->left) + 1, maxDepth(root->right) + 1);
	}

public:
	bool isBalanced(TreeNode* root)
	{
		if (!root)
		{
			return true;
		}
		return (abs(maxDepth(root->left) - maxDepth(root->right)) <= 1) && (isBalanced(root->left)) && (isBalanced(root->right));
	}
};

int main()
{
	return 0;
}