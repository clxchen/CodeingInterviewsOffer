struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode *m_pLeft;
	BinaryTreeNode *m_pRight;		
};

BinaryTreeNode *TreeConstruct(int *preOrder,int *inOrder,int length)
{
	if(nullptr == preOrder || nullptr == inOrder || length <= 0)
		return nullptr;		
	return ConstructCore(preOrder,preOrder + length - 1,inOrder,inOrder + length - 1);
}

BinaryTreeNode *ConstructCore(int *pPreOrderStart,int *pPreOrderEnd,int *pInOrderStart,int *pInOrderEnd)
{
	int rootValue = startPreOrder[0];
	BinaryTreeNode *root = new BinaryTreeNode();
	root->m_nValue = rootValue;
	root->m_pLeft = root->m_pRight = nullptr;
	
	if(pPreOrderStart == pPreOrderEnd)
	{
		if(pInOrderStart == pInOrderEnd && (*pPreOrderStart) == (*pPreOrderEnd))
			return root;
		else
			throw std::exception("invalid input");	
	}
	
	//在中序遍历中找到根节点位置
	int *rootInOrder = pInOrderStart;
	while(rootInOrder <= pInOrderEnd && (*rootInOrder) != rootValue)
		++rootInOrder;
	
	if(rootInOrder == pInOrderEnd && *rootInOrder != rootValue)
		throw std::exception("invalid input");
	
	int leftLength = rootInOrder - pInOrderStart;
	int *leftPreOrderEnd =  pPreOrderStart + leftLength;
	if(leftLength > 0)
	{
		//构建左子树
		root->m_pLeft = 	ConstructCore(pPreOrderStart + 1,leftPreOrderEnd,pInOrderStart,rootInOrder - 1);
	}
	if(leftLength < pPreOrderEnd - pPreOrderStart)
	{
		//构建右子树
		root->m_pRight = 	ConstructCore(leftPreOrderEnd + 1,pPreOrderEnd,rootInOrder + 1,pInOrderEnd);		
	}
	return root;
}
