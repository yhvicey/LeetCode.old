#include <algorithm>
#include <unordered_map>

using namespace std;

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
	unordered_map<TreeNode*, unordered_map<bool,int>> record;

	int visit(TreeNode* node, bool rob)
	{
		if(record[node][rob])
		{
			return record[node][rob];
		}
		if (node == NULL)
		{
			return 0;
		}
		if (rob)
		{
			record[node][rob] = node->val + visit(node->left, false) + visit(node->right, false);
			return record[node][rob];
		}
		record[node][rob] = max(visit(node->left, true), visit(node->left, false)) + max(visit(node->right, true), visit(node->right, false));
		return record[node][rob];
	}

public:
	int rob(TreeNode* root)
	{
		if (root == NULL)
		{
			return 0;
		}
		return max(visit(root, true), visit(root, false));
	}
};

int main()
{
	TreeNode root(3);
	root.left = new TreeNode(2);
	root.right = new TreeNode(3);
	root.left->right = new TreeNode(3);
	root.right->right = new TreeNode(1);
	auto var = Solution().rob(&root);
}