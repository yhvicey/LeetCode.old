struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(0)
	{
	}
};

class Solution
{
public:
	bool hasCycle(ListNode *head)
	{
		auto slow = head;
		auto fast = head;
		for (;;)
		{
			if (fast)
			{
				fast = fast->next;
				if (fast)
				{
					fast = fast->next;
					slow = slow->next;
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
			if (fast == slow)
			{
				return true;
			}
		}
		return false;
	}
};

int main()
{
	return 0;
}