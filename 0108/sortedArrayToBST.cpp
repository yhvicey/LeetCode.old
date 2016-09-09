#include<vector>

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
public:
	TreeNode* sortedArrayToBST(vector<int>& nums)
	{
		int len = nums.size();
		if (len == 0)
		{
			return NULL;
		}
		if (len == 1)
		{
			return new TreeNode(nums[0]);
		}
		int halfLen = len / 2;
		auto begin = nums.begin();
		auto mid = begin + halfLen;
		TreeNode* root = new TreeNode(*mid);
		auto leftHalf = vector<int>{ begin, mid };
		auto rightHalf = vector<int>{ mid + 1, nums.end() };
		root->left = sortedArrayToBST(leftHalf);
		root->right = sortedArrayToBST(rightHalf);
		return root;
	}
};

int main()
{
	Solution sln;
	auto var = sln.sortedArrayToBST(vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9});
	return 0;
}