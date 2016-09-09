#define NULL 0

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};

ListNode* removeNthFromEnd(ListNode* head, int n)
{
	ListNode* front = NULL;
	ListNode* target = head;
	ListNode* temp = target;
	for (int i = 0; i < n; i++)
	{
		temp = temp->next;
	}
	while (temp)
	{
		temp = temp->next;
		front = target;
		target = target->next;
	}
	if (front)
	{
		front->next = target->next;
		return head;
	}
	else
	{
		return head->next;
	}
}

int main()
{
	ListNode n1(0);
	ListNode n2(1);
	ListNode n3(2);
	ListNode n4(3);
	ListNode n5(4);
	ListNode n6(5);
	ListNode n7(6);
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;
	n5.next = &n6;
	n6.next = &n7;
	removeNthFromEnd(&n1, 3);
	return 0;
}