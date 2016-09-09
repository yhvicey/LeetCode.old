#include <cstddef>
#include <queue>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	deque<ListNode*> _deque;

public:
	void reorderList(ListNode* head) {
		while(head)
		{
			_deque.push_back(head);
			head = head->next;
		}

		ListNode* lastBack = NULL;

		while (!_deque.empty())
		{
			if (_deque.size() > 1)
			{
				auto front = _deque.front();
				auto back = _deque.back();
				if(lastBack)
				{
					lastBack->next = front;
				}
				front->next = back;
				lastBack = back;
				back->next = NULL;
				_deque.pop_front();
				_deque.pop_back();
			}
			else
			{
				auto back = _deque.back();
				if (lastBack)
				{
					lastBack->next = back;
				}
				back->next = NULL;
				_deque.pop_back();
			}
		}
	}
};

int main()
{
	auto head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	Solution().reorderList(head);
	return 0;
}