#define NULL 0
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	//��λ�ж�
	bool flag = false;

	//�����һ���ڵ�
	int firstNum = (l1 == NULL ? 0 : l1->val) + (l2 == NULL ? 0 : l2->val);
	if (firstNum >= 10)
	{
		firstNum -= 10;
		flag = true;
	}
	l1 = l1 == NULL ? NULL : l1->next;
	l2 = l2 == NULL ? NULL : l2->next;
	ListNode* head = new ListNode(firstNum);
	ListNode* temp = head;

	//ѭ����������ڵ�ֱ�������ڵ�Ϊ��
	while (l1 != NULL || l2 != NULL)
	{
		int num = (l1 == NULL ? 0 : l1->val) + (l2 == NULL ? 0 : l2->val) + (flag ? 1 : 0);
		if (num >= 10)
		{
			num -= 10;
			flag = true;
		}
		else
		{
			flag = false;
		}
		l1 = l1 == NULL ? NULL : l1->next;
		l2 = l2 == NULL ? NULL : l2->next;
		temp->next = new ListNode(num);
		temp = temp->next;
	}

	//�������һ���ڵ�
	if (flag)
	{
		temp->next = new ListNode(1);
	}

	//���ؽ��
	return head;
}

int main()
{
	ListNode* l1 = new ListNode(5);
	//l1->next = new ListNode(8);
	ListNode* l2 = new ListNode(5);
	addTwoNumbers(l1, l2);
	return 0;
}