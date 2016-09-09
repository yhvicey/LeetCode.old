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
	ListNode* oddEvenList(ListNode* head)
	{
		if (!head)
		{
			return NULL;
		}
		auto oddEnd = head;
		auto evenBegin = head->next;
		auto odd = oddEnd;
		auto even = evenBegin;
		while (odd != NULL || even != NULL)
		{
			//odd exist if even exist
			if (even)
			{
				odd->next = even->next;
				odd = odd->next;
				if (odd)
				{
					even->next = odd->next;
					even = even->next;
					oddEnd = odd;
				}
				else
				{
					even->next = NULL;
					even = even->next;
				}
			}
			else
			{
				break;
			}
		}
		oddEnd->next = evenBegin;
		return head;
	}
};

int main()
{
	ListNode root(1);
	ListNode* cur = &root;

	cur->next = new ListNode(2);
	cur = cur->next;

	cur->next = new ListNode(3);
	cur = cur->next;

	cur->next = new ListNode(4);
	cur = cur->next;

	cur->next = new ListNode(5);
	cur = cur->next;

	cur->next = new ListNode(6);
	cur = cur->next;

	cur->next = new ListNode(7);
	cur = cur->next;

	cur->next = new ListNode(8);
	cur = cur->next;

	Solution sln;
	auto var = sln.oddEvenList(&root);
	return 0;
}