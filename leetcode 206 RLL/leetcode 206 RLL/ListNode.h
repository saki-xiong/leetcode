#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<list>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode *head)
{
	while (head != NULL)
	{
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}

void dropList(ListNode *head)
{
	if (head == NULL) return;
	ListNode *temp;
	while (head != NULL)
	{
		temp = head->next;
		delete head;
		head = NULL;
		head = temp;
	}
}
