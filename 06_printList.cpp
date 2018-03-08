struct ListNode 
{
	int m_nValue;
	ListNode * m_pNext;	
};

//向链表的末尾添加一个节点
bool AddToTail(ListNode **pHead,int value)
{
	if(nullptr == pHead)
		return false;
	
	ListNode *pNew = new ListNode();
	pNew->m_nValue = value;
	pNew->m_pNext = nullptr;
	
	if(*pHead == nullptr)
		*pHead = pNew;
	else
	{
		ListNode *pNode = *pHead;
		while(pNode->m_pNext != nullptr)
			pNode = p->m_pNext;
		p->m_pNext = pNew;	
	}
	return true;	
}

//在链表中删除元素
bool RemoveNode(ListNode **pHead, int value)
{
	if(nullptr == pHead || nullptr == *pHead)
		return false;
	ListNode *pToBeDeleted = nullptr;
	if((*pHead)->m_nValue == value)
	{
		pToBeDeleted = (*pHead)
		*pHead = (*pHead)->m_pNext; 		
	}
	
	
	ListNode *pNode = *pHead;
	
	while(pNode->m_pNext != null && pNode->m_pNext->m_nValue != value)
		pNode = pNode->m_pNext;
	
	if(pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue == value)
	{
		pToBeDeleted = pNode->m_pNext;
		//pNode = pNode->m_pNext;
		pNode->m_pNext = pNode->m_pNext->m_pNext;
	}
	
	if(pToBeDeleted != nullptr)
	{
		delete 	pToBeDeleted;
		pToBeDeleted = nullptr;
		return true;
	}
	
	return false;
}

#include <stack>
#include <cstdio>
//反向打印列表，使用栈结构实现
void PrintListReversingly_Iteratively(ListNode *pHead)
{
	std::stack<ListNode *> nodes;
	
	ListNode *pNode = pHead;
	while(pNode != nullptr)
	{
		nodes.push(pNode);
		pNode = pNode->m_pNext;	
	}	
	
	while(!nodes.empty())
	{
		pNode = nodes.top();
		printf("%d\t",pNode->m_nValue);
		nodes.pop();	
	}
}

//方向打印列表，使用递归
//链表较长可能栈溢出，鲁棒性较差
void PrintListReversingly_Recursively(ListNode *pHead)
{
	if(pHead != nullptr)
	{
		if(pHead->m_pNext != nullptr)
		{
				PrintListReversingly_Recursively(pHead->m_pNext);	
		}
		printf("%d\t",pNode->m_nValue);	
	}
}
