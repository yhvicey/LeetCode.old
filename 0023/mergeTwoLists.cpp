#include<vector>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* merge(vector<ListNode*>::iterator begin, vector<ListNode*>::iterator end);

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

ListNode* merge(vector<ListNode*>::iterator begin, vector<ListNode*>::iterator end)
{
	if (begin == end)
	{
		return NULL;
	}
	int len = end - begin;
	int half = len / 2;
	if (len == 1)
	{
		return *begin;
	}
	if (len == 2)
	{
		return mergeTwoLists(*begin, *(begin + 1));
	}
	return mergeTwoLists(merge(begin, begin + half), merge(begin + half, end));
}

ListNode* mergeKLists(vector<ListNode*>& lists)
{
	return merge(lists.begin(), lists.end());
}

int main()
{
	ListNode n1(-2);
	ListNode n2(-3);
	ListNode n3(-2);
	ListNode n4(1);
	n2.next = &n3;
	n3.next = &n4;
	auto var = mergeKLists(vector<ListNode*>{NULL, &n1, &n2});
	return 0;
}