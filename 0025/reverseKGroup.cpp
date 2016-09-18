#include <stack>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

class Solution
{
	ListNode* funcResult = NULL;

	stack<ListNode*> nodeStack;

	void reversePart(ListNode* head, ListNode* lastBack, int count)
	{
		while (head)
		{

		}
	}

public:
	ListNode* reverseKGroup(ListNode* head, int k)
	{
		reversePart(head, NULL, k);
		return funcResult;
	}
};

int main()
{
	ListNode n1(1);
	//ListNode n2(2);
	//ListNode n3(3);
	//ListNode n4(4);
	//ListNode n5(5);
	//n1.next = &n2;
	//n2.next = &n3;
	//n3.next = &n4;
	//n4.next = &n5;
	Solution().reverseKGroup(&n1, 1);
	return 0;
}