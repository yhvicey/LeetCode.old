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
	vector<string> _result;

	void traverse(TreeNode* root, string path)
	{
		if (!root)
		{
			return;
		}
		char buffer[1024];
		sprintf(buffer, "%d", root->val);
		path += ("->" + string(buffer));
		if (!root->left && !root->right)
		{
			if (path != "")
			{
				_result.push_back(path.substr(2));
			}
		}
		else
		{
			traverse(root->left, path);
			traverse(root->right, path);
		}
	}

public:
	vector<string> binaryTreePaths(TreeNode* root)
	{
		traverse(root, "");
		return _result;
	}
};

int main()
{
	TreeNode* root = new TreeNode(1);
	Solution sln;
	sln.binaryTreePaths(root);
}