#define NULL 0

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* swapPairs(ListNode* head)
{
	ListNode* lastBack = NULL;
	ListNode* front = head;
	ListNode* back = (front ? front->next : NULL);
	ListNode* result = (back ? back : front);
	while (front && back)
	{
		if (lastBack)
		{
			lastBack->next = back;
		}
		front->next = back->next;
		back->next = front;
		lastBack = front;
		front = front->next;
		back = (front ? front->next : NULL);
	}
	return result;
}

int main()
{
	ListNode n1(1);
	ListNode n2(2);
	n1.next = &n2;
	swapPairs(&n1);
	return 0;
}