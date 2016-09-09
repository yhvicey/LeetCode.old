#define NULL 0 

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL)
	{
	}
};

class Solution
{
public:
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
	{
		if (!headA || !headB)
		{
			return NULL;
		}
		auto left = headA;
		auto right = headB;
		int leftLen = 0;
		int rightLen = 0;
		while (left)
		{
			leftLen++;
			left = left->next;
		}
		while (right)
		{
			rightLen++;
			right = right->next;
		}

		left = headA;
		right = headB;
		if (leftLen > rightLen)
		{
			int diff = leftLen - rightLen;
			while (diff--)
			{
				left = left->next;
			}
		}
		else
		{
			int diff = rightLen - leftLen;
			while (diff--)
			{
				right = right->next;
			}
		}

		while (left&&right)
		{
			if (left == right)
			{
				return left;
			}
			left = left->next;
			right = right->next;
		}
		return NULL;
	}
};

int main()
{
	return 0;
}