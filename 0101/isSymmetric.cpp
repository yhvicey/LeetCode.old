#include <list>

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
	bool traverse(list<TreeNode*> &leftHalf, list<TreeNode*> &rightHalf)
	{
		if (leftHalf.empty() && rightHalf.empty())
		{
			return true;
		}
		list<TreeNode*> nextLeftHalf;
		list<TreeNode*> nextRightHalf;
		int leftLen = leftHalf.size();
		int rightLen = rightHalf.size();
		if (leftLen != rightLen)
		{
			return false;
		}
		for (int i = 0; i < leftLen; i++)
		{
			auto left = leftHalf.front();
			auto right = rightHalf.back();
			if (left == NULL&&right == NULL)
			{
				leftHalf.pop_front();
				rightHalf.pop_back();
				continue;
			}
			if (left&&right)
			{
				if (leftHalf.front()->val != rightHalf.back()->val)
				{
					return false;
				}
				nextLeftHalf.push_back(leftHalf.front()->left);
				nextLeftHalf.push_back(leftHalf.front()->right);
				nextRightHalf.push_front(rightHalf.back()->right);
				nextRightHalf.push_front(rightHalf.back()->left);
				leftHalf.pop_front();
				rightHalf.pop_back();
				continue;
			}
			return false;
		}
		return traverse(nextLeftHalf, nextRightHalf);
	}

public:
	bool isSymmetric(TreeNode* root)
	{
		if (!root)
		{
			return true;
		}
		list<TreeNode*> left{ root->left };
		list<TreeNode*> right{ root->right };
		return traverse(left, right);
	}
};

int main()
{
	TreeNode root(2);
	TreeNode left(3);
	TreeNode right(3);
	root.left = &left;
	root.right = &right;
	left.left = new TreeNode(4);
	left.right = new TreeNode(5);
	right.right = new TreeNode(4);
	Solution sln;
	sln.isSymmetric(&root);
	return 0;
}