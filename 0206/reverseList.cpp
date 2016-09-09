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
	ListNode* reverseList(ListNode* head)
	{
		if (!head)
		{
			return NULL;
		}
		ListNode* p = head;
		ListNode* pNext = head->next;
		p->next = NULL;
		while (pNext)
		{
			ListNode* temp = pNext->next;
			pNext->next = p;
			p = pNext;
			pNext = temp;
		}
		return p;
	}
};

int main()
{
	ListNode l1(1);
	ListNode l2(2);
	l1.next = &l2;
	Solution sln;
	sln.reverseList(&l1);
}