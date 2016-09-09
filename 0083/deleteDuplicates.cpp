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
	void deleteNode(ListNode* &target)
	{
		if (!target)
		{
			return;
		}
		if (!target->next)
		{
			target = NULL;
			return;
		}
		target->val = target->next->val;
		target->next = target->next->next;
	}
public:
	ListNode* deleteDuplicates(ListNode* head)
	{
		auto result = head;
		while (head)
		{
			if (head->next)
			{
				if (head->next->val == head->val)
				{
					deleteNode(head->next);
					continue;
				}
			}
			head = head->next;
		}
		return result;
	}
};

int main()
{
	ListNode root(1);
	root.next = new ListNode(1);
	auto var = Solution().deleteDuplicates(&root);
	return 0;
}