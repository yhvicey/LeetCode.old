#include<queue>

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

class BSTIterator
{
	queue<int> _tree;

	void inorderTraversal(TreeNode* root)
	{
		if (!root)
		{
			return;
		}
		inorderTraversal(root->left);
		_tree.push(root->val);
		inorderTraversal(root->right);
	}

public:
	BSTIterator(TreeNode *root)
	{
		inorderTraversal(root);
	}

	bool hasNext()
	{
		return !_tree.empty();
	}

	int next()
	{
		int result = _tree.front();
		_tree.pop();
		return result;
	}
};

int main()
{
	TreeNode n1(1);
	TreeNode n2(2);
	TreeNode n3(3);
	TreeNode n4(4);
	TreeNode n5(5);
	TreeNode n6(6);
	TreeNode n7(7);
	TreeNode n8(8);
	TreeNode n9(9);

	n5.left = &n3;
	n5.right = &n7;
	n3.left = &n2;
	n3.right = &n4;
	n2.left = &n1;
	n7.left = &n6;
	n7.right = &n8;
	n8.right = &n9;

	//TreeNode root(1);
	//TreeNode right(2);
	//root.right = &right;

	BSTIterator i(&n5);
	return 0;
}