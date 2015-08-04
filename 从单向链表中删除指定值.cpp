#include <iostream>
using namespace std;
typedef struct node
{
	int number;
	struct node *next;
}Node;
void ListNew(Node *head, int mynumber)
{
	Node *nextnode = (Node *)malloc(sizeof(Node));
	nextnode->next = NULL;//考虑容错	
	nextnode->number = mynumber;
	if (head->next != NULL)
	{
		nextnode->next = head->next;
		head->next = nextnode;
	}
	else//头节点的后继指针NULL，直接添加即可
	{
		head->next = nextnode;
	}
}
Node *Delete(Node *head, int key)
{
	Node *node1 = head;
	Node *node2 = NULL;
	if (head == NULL)
	{
		return NULL;
	}
	else
	{
		if (node1->number == key)
		{
			head = head->next;
			free(node1);
			return head;
		}
		else
		{
			while (node1 != NULL)
			{
				node2 = node1;
				node2 = node2->next;
				if (node2->number == key)
				{
					node1->next = node2->next;
					free(node2);
					break;
				}
				node1 = node1->next;
			}
			return head;
		}
	}
}
int main()
{
	Node *head = (Node*)malloc(sizeof(Node));
	Node *p, *q, *q1;
	int key;
	p = (Node*)malloc(sizeof(Node));
	q1 = q = head;
	int nodenum;
	cin >> nodenum;//待输入的节点数量
	getchar();
	cin >> head->number;//头节点的值
	head->next = NULL;
	int h, t;
	for (int i = 1; i<nodenum; i++)
	{
		cin >> t >> h;
		//先进行查找，输入格式中的头节点的位置
		while (q != NULL)
		{
			if (q->number != h)
			{
				q = q->next;
			}
			else if (q->number == h)//直接在首位
			{
				ListNew(q, t);
				q = head;
				break;
			}
		}//还需要增加容错
	}

	cin >> key;
	p = Delete(q, key);
	/*cout<<"删除一个"<<key<<"之后的链表数据： "<<endl;  */
	while (p != NULL)
	{
		cout << p->number << " ";
		p = p->next;
	}
	//cout<<endl;  
	free(p);
	free(head);
	return 0;
}
