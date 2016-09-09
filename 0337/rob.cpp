#include<queue>
#include<map>

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
	priority_queue<int> result;
	map<TreeNode*, int> trueRecord;
	map<TreeNode*, int> falseRecord;
public:
	void visit(TreeNode* node, bool robbedJustNow, int total)
	{
		if (!node)
		{
			result.push(total);
			return;
		}
		if (robbedJustNow)
		{
			if (total < trueRecord[node])
			{
				return;
			}
			trueRecord[node] = total;
			visit(node->left, false, total);
			visit(node->right, false, total);
		}
		else
		{
			if (total < falseRecord[node])
			{
				return;
			}
			falseRecord[node] = total;
			visit(node->left, false, total);
			visit(node->right, false, total);
			visit(node->left, true, total + node->val);
			visit(node->right, true, total + node->val);
		}	
		return;
	}

	int rob(TreeNode* root)
	{
		visit(root, false, 0);
		return result.top();
	}
};

int main()
{
	TreeNode root(3);
	root.left = new TreeNode(2);
	root.right = new TreeNode(3);
	root.left->right = new TreeNode(3);
	root.right->right = new TreeNode(1);
	Solution sln;
	auto var = sln.rob(&root);
}