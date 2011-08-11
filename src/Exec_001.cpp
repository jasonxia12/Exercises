#include <iostream>

using namespace std;

struct BSTreeNode
{
	int m_nValue;
	BSTreeNode *m_pLeft;
	BSTreeNode *m_pRight;
};

BSTreeNode *header = NULL;
BSTreeNode *tail = NULL;

void Visit(BSTreeNode *node)
{
	if (header == NULL)
		header = node;
	if (tail != NULL)
		tail->m_pRight = node;
	node->m_pRight = NULL;
	
	node->m_pLeft = tail;
	tail = node;
	cout << "current Node is : " << node->m_nValue << endl;
}

void InnerOrder(BSTreeNode *root)
{
	if (root == NULL) return;

	BSTreeNode *right = root->m_pRight;

	InnerOrder(root->m_pLeft);
	Visit(root);
	InnerOrder(right);
}

int main()
{
	BSTreeNode node_4;
	node_4.m_nValue = 4;
	node_4.m_pLeft = NULL;
	node_4.m_pRight = NULL;

	BSTreeNode node_8;
	node_8.m_nValue = 8;
	node_8.m_pLeft = NULL;
	node_8.m_pRight = NULL;

	BSTreeNode node_12;
	node_12.m_nValue = 12;
	node_12.m_pLeft = NULL;
	node_12.m_pRight = NULL;

	BSTreeNode node_16;
	node_16.m_nValue = 16;
	node_16.m_pLeft = NULL;
	node_16.m_pRight = NULL;

	BSTreeNode node_6;
	node_6.m_nValue = 6;
	node_6.m_pLeft = &node_4;
	node_6.m_pRight = &node_8;

	BSTreeNode node_14;
	node_14.m_nValue = 14;
	node_14.m_pLeft = &node_12;
	node_14.m_pRight = &node_16;

	BSTreeNode node_10;
	node_10.m_nValue = 10;
	node_10.m_pLeft = &node_6;
	node_10.m_pRight = &node_14;

	InnerOrder(&node_10);

	BSTreeNode *temp = header;
	cout << "Iterate from header" << endl;
	while (temp != NULL)
	{
		cout << "Current Node is : " << temp->m_nValue << endl;
		temp = temp->m_pRight;
	}

	temp = tail;
	cout << "Iterate from tail" << endl;
	while (temp != NULL)
	{
		cout << "Current Node is : " << temp->m_nValue << endl;
		temp = temp->m_pLeft;
	}

}
