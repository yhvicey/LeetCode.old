#include <vector>

using namespace std;

class Solution
{
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
	{
		int leftBack = m;
		int rightBack = n;
		int back = m + n;
		while (leftBack || rightBack)
		{
			if (leftBack && rightBack)
			{
				if (nums1[leftBack - 1] > nums2[rightBack - 1])
				{
					nums1[--back] = nums1[--leftBack];
				}
				else
				{
					nums1[--back] = nums2[--rightBack];
				}
			}
			else
			{
				if (leftBack)
				{
					nums1[--back] = nums1[--leftBack];
				}
				else
				{
					nums1[--back] = nums2[--rightBack];
				}
			}
		}
	}
};


int main()
{
	vector<int> nums1{ 0 };
	vector<int> nums2{ 1 };
	Solution().merge(nums1, 0, nums2, 1);
	return 0;
}