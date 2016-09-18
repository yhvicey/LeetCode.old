#include <stack>

using namespace std;

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
	ListNode* reverse(ListNode* head)
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

public:
	bool isPalindrome(ListNode* head)
	{
		if (!head)
		{
			return true;
		}
		ListNode* slow = head;
		ListNode* fast = head;
		while (fast)
		{
			slow = slow->next;
			fast = fast->next;
			if (fast)
			{
				fast = fast->next;
			}
			else
			{
				break;
			}
		}
		slow = reverse(slow);
		while (slow&&head)
		{
			if (slow->val != head->val)
			{
				return false;
			}
			slow = slow->next;
			head = head->next;
		}
		return true;
	}
};

int main()
{
	ListNode l1(1);
	l1.next = new ListNode(2);
	auto var = Solution().isPalindrome(&l1);
	return 0;
}