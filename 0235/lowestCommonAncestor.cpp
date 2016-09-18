#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution
{
public:
	vector<TreeNode*> recordPath(TreeNode* root, TreeNode* target)
	{
		vector<TreeNode*> path;
		while (root)
		{
			path.push_back(root);
			if (root->val == target->val)
			{
				break;
			}
			if (root->val > target->val)
			{
				root = root->left;
			}
			else
			{
				root = root->right;
			}
		}
		return path;
	}

	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		auto firstPath = recordPath(root, p);
		auto secondPath = recordPath(root, q);
		int len = min(firstPath.size(), secondPath.size());
		for (int i = 0; i < len; i++)
		{
			if (firstPath[i] != secondPath[i])
			{
				return (i == 0) ? root : firstPath[i - 1];
			}
		}
		return firstPath[len - 1];
	}
};

int main()
{
	TreeNode* root = new TreeNode(2);
	root->left = new TreeNode(1);
	Solution sln;
	auto var = sln.lowestCommonAncestor(root, &TreeNode(2), &TreeNode(1));
	return 0;
}