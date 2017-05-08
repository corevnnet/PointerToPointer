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
	if (pNode == NULL)
	{
		cout << "Danh sach nay rong";
	}
	else
	{
		while (pNode != NULL)
		{
			cout << pNode->key<<"&#$";
			pNode = pNode->pNext;
		}
	}
}

void DeleteAll(Node* &pHead)
{
	Node* pNode = NULL;
	pNode = pHead;
	Node* pNodeNext = pNode->pNext;
	if (pNode -> pNext == NULL)
	{
		delete pHead;
	}
	else
	{
		while (pHead -> pNext!=NULL)
		{
			PrintList(pHead);
			cout << "\n";
			pNode = pHead;
			pNodeNext = pNode->pNext;
			while (pNodeNext -> pNext !=NULL)
			{
				pNode = pNode->pNext;
				pNodeNext = pNodeNext->pNext;

			}
			delete pNodeNext;
			pNode->pNext = NULL;
			

		}
		delete pNode;
		pHead = NULL;
	}
}
bool RemoveMiddle(Node* pHead, int key)
{
	Node* pCur = NULL;
	Node* pCurNext;
	pCur = pHead;
	
	if (pCur -> pNext == NULL)
	{
		return false;
	}
	else
	{
		pCurNext = pCur->pNext;
	}
	while (pCurNext -> key != key)
	{
		pCur = pCur->pNext;
		pCurNext = pCurNext->pNext;
		if (pCurNext -> key == key)
		{
			pCur->pNext = pCurNext->pNext;
			delete pCurNext;
			return true;
		}
	}
}
//bool RemoveHead(Node* &pHead)
//{
//	Node* pNode = NULL;
//	pNode = pHead;
//
//}
//void DnguocdS(Node* &pHead)
//{
//	Node* pNode = NULL;
//	Node* pNodeNext = NULL;
//	pNode = pHead;
//	pNodeNext = pNode->pNext;
//	Node* pHeadTmp;
//	while (pNode -> pNext != NULL)
//	{
//		pNode = pNode->pNext;
//		pno
//	}
//
//}



int main()
{
	Node *pRoot;
	pRoot = NULL;
	for (int i = 1; i < 77; i++)
	{
		AddHead(pRoot, i);
	}
	/*AddTail(pRoot, 3);
	AddHead(pRoot, 2);*/
	PrintList(pRoot);
	cout << "\n";
	//RemoveMiddle(pRoot, 5);
	DeleteAll(pRoot);
	cout << "Sau khi xoa \n";
	PrintList(pRoot);
	cout << "\n";
	/*DeleteTail(pRoot);
	PrintList(pRoot);
*/

	return 0;
}

