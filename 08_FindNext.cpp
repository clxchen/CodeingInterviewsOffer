struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pParent;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;		
};

BinaryTreeNode *GetNext(BinaryTreeNode* pNode)
{
	if(nullptr == pNode)
		return nullptr;
		
	BinaryTreeNode *pNext = nullptr;
	if(pNode->m_pRight != nullptr)
	{
		BinaryTreeNode *pRight = pNode->m_pRight;
		while(pRight->m_pLeft != nullptr )
			pRight = pRight->m_pLeft;
		pNext = pRight;
	}
	else if(pNode->m_pParent != nullptr)
	{
		BinaryTreeNode *pParent = pNode->m_pParent;	
		BinaryTreeNode *pCurrent = pNode ;
		while(pParent != nullptr &&pParent->m_pRight == pCurrent)
		{
			pCurrent = pParent;
			pParent = pParent->m_pParent;
		}
		
		pNext = pParent;
	}	
	return pNext;
}
