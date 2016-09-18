#include <vector>

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
	vector<int> inorderTraversal(TreeNode* root)
	{
		if (!root)
		{
			return vector<int>{};
		}

		vector<int> result{ inorderTraversal(root->left) };

		result.push_back(root->val);

		auto rightResult = inorderTraversal(root->right);
		int rightLen = rightResult.size();
		for (int i = 0; i < rightLen; i++)
		{
			result.push_back(rightResult[i]);
		}
		return result;
	}

public:
	bool isValidBST(TreeNode* root)
	{
		auto list = inorderTraversal(root);
		int len = list.size();
		if (len <= 1)
		{
			return true;
		}
		else
		{
			for (int i = 1; i < len; i++)
			{
				if (list[i] <= list[i - 1])
				{
					return false;
				}
			}
			return true;
		}
	}
};

int main()
{
	return 0;
}