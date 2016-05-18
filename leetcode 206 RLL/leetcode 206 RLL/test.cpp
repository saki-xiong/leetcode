#include"ListNode.h"


class Solution1 {
public:
	ListNode* reverseList(ListNode* head)
	{
		if (head == NULL) return NULL;
		ListNode *pre = head;
		ListNode *cur = head->next;
		while (cur != NULL)
		{
			pre->next = cur->next;
			cur->next = head;
			head = cur;
			cur = pre->next;
		}
		return head;
	}
};

class Solution2{
public:
	ListNode* reverseList(ListNode* head){
		
		if (head == NULL || head->next == NULL) 
		{
			cout << "beforereverse:  " << head->val << endl;
				return head;
			}
		cout << "out beforereverse:  " << head->val << endl;
		ListNode *newhead = reverseList(head->next);
		head->next->next = head;
		head->next = NULL;
		cout << "afterreverse  " <<"newhead: "<< newhead->val<<"  "<<"head: "<<head->val<< endl;
		return newhead;
		
	}
};

int main()
{
	ListNode *head = new ListNode(0);
	ListNode *cur = head;
	for (int i = 0; i < 2; i++)
	{
		ListNode *newnode = new ListNode(floor(rand() % 100));
		cur->next = newnode;
		cur = newnode;
		//cout <<i<<" "<< cur->val << " "<<endl;
		//cout << cur->next << " "<<endl;
		////delete newnode;
		////newnode = NULL;
	}
	//dropList(newnode);
	printList(head);
	//Solution1 s1;
	
	////ListNode* head1;

	//head1 = s1.reverseList(head);
	//printList(head1);
	//dropList(head1);

	Solution2 s2;
	////ListNode* head2 = new ListNode(0);
	head = s2.reverseList(head);
	printList(head);
	//dropList(head2);
	dropList(head);
}