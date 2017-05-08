// PointerToPointer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


struct Node
{
	int key;
	Node* pNext;
};

Node* CreateNode(int data)
{
	Node* p = new Node();
	if (p == NULL)
	{
		return NULL;
	}
	else
	{
		p->key = data;
		p->pNext = NULL;
		return p;
	}
}
bool AddHead(Node* &pHead, int data)
{
	Node* pNode = CreateNode(data);
	if (pNode == NULL)
	{
		return false;
	}
	else
	{
		if (pHead == NULL)
		{
			pHead = pNode;
		}
		else
		{
			pNode->pNext = pHead;
			pHead = pNode;
		}
		return true;
	}

}
bool AddTail(Node* pHead, int data)
{
	Node* pNode = CreateNode(data);
	if (pNode == NULL)
	{
		return false;
	}
	else
	{
		Node* pTail = NULL;
		pTail = pHead;

		if (pTail->pNext == NULL)
		{
			pTail->pNext = pNode;
		}
		else
		{
			while (pTail->pNext != NULL)
			{
				pTail = pTail->pNext;
				//if (pTail->pNext == NULL)
				//{
				//	pTail->pNext = pNode;
				//	//return true;
				//}

			}
			pTail->pNext = pNode;
		}

	}
}
void DeleteTail(Node* &pHead) 
{
	Node* pTail = NULL;
	pTail = pHead;
	Node* pTailNext = pTail->pNext;
	if (pTail -> pNext == NULL)
	{
		delete pHead;
	}
	else
	{
		while (pTailNext -> pNext != NULL)
		{
			pTail = pTail->pNext;
			pTailNext = pTailNext-> pNext;
		}
		delete pTailNext;
		pTail->pNext = NULL;
	}
}

void PrintList(Node* pHead)
{
	Node* pNode = pHead;
	while (pNode != NULL)
	{
		cout << pNode->key;
		pNode = pNode->pNext;
	}
}
//bool AddAfter(Node* &pHead, int data)
//{
//	Node* pNode = CreateNode(data);
//	
//}


int main()
{
	Node *pRoot;
	pRoot = NULL;
	for (int i = 1; i < 3; i++)
	{
		AddHead(pRoot, i);
	}
	AddTail(pRoot, 3);
	AddHead(pRoot, 2);
	PrintList(pRoot);
	cout << "\n";
	DeleteTail(pRoot);
	PrintList(pRoot);


	return 0;
}

