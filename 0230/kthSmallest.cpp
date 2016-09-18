#include <vector>

using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution
{
	vector<int> _tree;

	void traverse(TreeNode* root)
	{
		if (!root)
		{
			return;
		}
		traverse(root->left);
		_tree.push_back(root->val);
		traverse(root->right);
	}

public:
	int kthSmallest(TreeNode* root, int k)
	{
		traverse(root);
		return _tree[k - 1];
	}
};

int main()
{
	return 0;
}