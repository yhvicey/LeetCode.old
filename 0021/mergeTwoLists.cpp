#define NULL 0

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
	ListNode* root = new ListNode(0);
	ListNode* temp = root;
	while (l1 != NULL || l2 != NULL)
	{
		if (!l1)
		{
			temp->next = l2;
			temp = temp->next;
			l2 = l2->next;
			break;
		}
		if (!l2)
		{
			temp->next = l1;
			temp = temp->next;
			l1 = l1->next;
			break;
		}
		if (l1->val < l2->val)
		{
			temp->next = l1;
			temp = temp->next;
			l1 = l1->next;
			continue;
		}
		else
		{
			temp->next = l2;
			temp = temp->next;
			l2 = l2->next;
			continue;
		}
	}
	return root->next;
}

int main()
{
	return 0;
}