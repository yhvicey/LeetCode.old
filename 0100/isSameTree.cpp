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
	bool compare(TreeNode* left, TreeNode* right)
	{
		if (left == NULL&&right == NULL)
		{
			return true;
		}
		if (left == NULL || right == NULL)
		{
			return false;
		}
		if (left->val == right->val)
		{
			return compare(left->left, right->left) && compare(left->right, right->right);
		}
		return false;
	}

	bool isSameTree(TreeNode* p, TreeNode* q)
	{
		if (p == NULL&&q == NULL)
		{
			return true;
		}
		if (p == NULL || q == NULL)
		{
			return false;
		}
		if (compare(p, q))
		{
			return true;
		}
		else
		{
			return compare(p->left, q) || compare(p->right, q);
		}
	}
};

int main()
{
	return 0;
}