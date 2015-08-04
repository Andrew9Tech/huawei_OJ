#include <iostream>
using namespace std;
typedef int ElemType;
struct ListNode
{
	ListNode *next;
	ElemType data;
};

int FindKthToTail(ListNode* pListHead, unsigned int k)
{
	ListNode *pAhead = pListHead;
	ListNode *pBehind = NULL;

	for (unsigned int i = 0; i < k; i++)
	{
		pAhead = pAhead->next;
	}

	pBehind = pListHead;

	while (pAhead->next != NULL)
	{
		pAhead = pAhead->next;
		pBehind = pBehind->next;
	}
	return pBehind->data;
}

void main()
{
	ListNode *pListNode, *PListNode, *qListNode;
	int num, count = 0, k;
	pListNode = PListNode = new ListNode;
	cin >> num;
	for (int i = 0; i<num; i++)
	{
		qListNode = new ListNode;
		cin >> qListNode->data;
		pListNode->next = qListNode;
		pListNode = qListNode;
	}
	pListNode->next = NULL;
	cin >> k;    //输入要输出的位置
	ListNode *head = PListNode->next;

	cout << FindKthToTail(head, k) << endl;
}
