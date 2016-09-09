#include<vector>
using namespace std;
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
	int sizex = nums1.size();
	int sizey = nums2.size();
	int posx = 0;
	int posy = 0;
	double size = (double)(sizex + sizey) / 2;
	if (size - (int)size > 0)
	{
		int result = 0;
		for (int i = 0; i < size; i++)
		{
			if (posx >= sizex)
			{
				result = nums2[posy];
				posy++;
				continue;
			}
			if (posy >= sizey)
			{
				result = nums1[posx];
				posx++;
				continue;
			}
			if (nums1[posx] > nums2[posy])
			{
				result = nums2[posy];
				posy++;
			}
			else
			{
				result = nums1[posx];
				posx++;
			}
		}
		return result;
	}
	else
	{
		int front = 0;
		int back = 0;
		for (int i = 0; i < size + 1; i++)
		{
			front = back;
			if (posx >= sizex)
			{
				back = nums2[posy];
				posy++;
				continue;
			}
			if (posy >= sizey)
			{
				back = nums1[posx];
				posx++;
				continue;
			}
			if (nums1[posx] > nums2[posy])
			{
				back = nums2[posy];
				posy++;
			}
			else
			{
				back = nums1[posx];
				posx++;
			}
		}
		return (double)(front + back) / 2;
	}
}

int main()
{
	findMedianSortedArrays(vector<int>{}, vector<int>{1});
	return 0;
}