/**
 * @file Exec_007.cpp
 * @brief Test if two linked list is crossed or not
 * @author Peng Xia
 * @version 0.1
 * @date 2011-08-18
 */
#include <iostream>

using namespace std;

struct LinkNode
{
	LinkNode(int value):m_value(value), m_pNext(NULL) {}

	LinkNode* m_pNext;
	int m_value;
};

bool LinkCrossed(LinkNode* header_1, LinkNode* header_2, LinkNode*& crossAt)
{
	int size_1 = 0, size_2 = 0, size_delta = 0;

	LinkNode* pTemp_1 = header_1;
	// Count the node number in link 1
	while (pTemp_1 != NULL)
	{
		size_1++;
		pTemp_1 = pTemp_1->m_pNext;
	}
	// cout << "link 1 has " << size_1 << " nodes" << endl;
	LinkNode* pTemp_2 = header_2;
	// Count the node number in link 2
	while (pTemp_2 != NULL)
	{
		size_2++;
		pTemp_2 = pTemp_2->m_pNext;
	}
	// cout << "link 2 has " << size_2 << " nodes" << endl;
	
	pTemp_1 = header_1;
	pTemp_2 = header_2;

	// Align these two link from the end
	if (size_1 > size_2)
	{
		for (int i = 0; i < size_1-size_2; i++)
		{
			pTemp_1 = pTemp_1->m_pNext;
		}
	}
	else
	{
		for (int i = 0; i < size_2-size_1; i++)
		{
			pTemp_2 = pTemp_2->m_pNext;
		}
	}

	// Check if there are any node which is the same
	bool fCrossed = false;
	while (pTemp_1 != NULL)
	{
		// Found node in both link, so they are crossed
		if (pTemp_1 == pTemp_2)
		{
			crossAt = pTemp_1;
			fCrossed = true;
			break;
		}
		pTemp_1 = pTemp_1->m_pNext;
		pTemp_2 = pTemp_2->m_pNext;
	}
	return fCrossed;
}

void DumpLink(LinkNode* header)
{
	int count = 0;
	while (header != NULL)
	{
		if (count % 10 == 0 && count != 0)
			cout << endl;
		if (count != 0) 
			cout << "->";
		count++;
		cout << "node" << header->m_value;
		header = header->m_pNext;
	}
	cout << endl;
}

int main()
{
	int TestCaseMaxLen = 20;
	// Create test case which is crossed
	srand(time(NULL));
	cout << endl << "====== Tesing Corssed Links ======" << endl;
	int size1 = 0;
	int size2 = 0; 
	while (size1 == 0)
		size1 = rand()%TestCaseMaxLen;
	while (size2== 0)
		size2 = rand()%TestCaseMaxLen;
	int sizeOverlapped;
	int nodeId = 0;
	LinkNode* header1 = NULL;
	LinkNode* header2 = NULL;
	if (size1 > size2)
		sizeOverlapped = rand()%size2+1;
	else
		sizeOverlapped = rand()%size1+1;
	for (int i = 0; i < size1-sizeOverlapped; i++)
	{
		LinkNode* pTempNode = new LinkNode(nodeId++);
		pTempNode->m_pNext = header1;
		header1 = pTempNode;
	}
	for (int i = 0; i < size2-sizeOverlapped; i++)
	{
		LinkNode* pTempNode = new LinkNode(nodeId++);
		pTempNode->m_pNext = header2;
		header2 = pTempNode;
	}
	LinkNode* overlapped = NULL;
	for (int i = 0; i < sizeOverlapped; i++)
	{
		LinkNode* pTempNode = new LinkNode(nodeId++);
		pTempNode->m_pNext = overlapped;
		overlapped = pTempNode;
	}
	cout << "Link will crossed at node" << nodeId-1 << endl;

	if (header1 == NULL)
		header1 = overlapped;
	else
	{
		LinkNode* tail = header1;
		while (tail != NULL && tail->m_pNext != NULL)
			tail = tail->m_pNext;
		tail->m_pNext = overlapped;
	}
	if (header2 == NULL)
		header2 = overlapped;
	else
	{
		LinkNode* tail = header2;
		while (tail != NULL && tail->m_pNext != NULL)
			tail = tail->m_pNext;
		tail->m_pNext = overlapped;
	}
	cout << "Link 1:" << endl;
	DumpLink(header1);
	cout << "Link 2:" << endl;
	DumpLink(header2);

	LinkNode* crossAt;
	bool fCrossed = LinkCrossed(header1, header2, crossAt);
	if (fCrossed)
		cout << "*** Result: Link crossed at node" << crossAt->m_value << endl;
	else
		cout << "*** Result: Link is not crossed" << endl;
	

	while (header1 != NULL && header1 != crossAt)
	{
		LinkNode* temp = header1;
		header1 = header1->m_pNext;
		delete temp;
	}
	while (header2 != NULL)
	{
		LinkNode* temp = header2;
		header2 = header2->m_pNext;
		delete temp;
	}

	// Test uncrossed link
	cout << endl << "====== Tesing Non-Corssed Links ======" << endl;
	header1 = NULL;
	header2 = NULL;
	nodeId = 0;
	for (int i = 0; i < size1; i++)
	{
		LinkNode* pTempNode = new LinkNode(nodeId++);
		pTempNode->m_pNext = header1;
		header1 = pTempNode;
	}
	for (int i = 0; i < size2; i++)
	{
		LinkNode* pTempNode = new LinkNode(nodeId++);
		pTempNode->m_pNext = header2;
		header2 = pTempNode;
	}
	cout << "Link 1:" << endl;
	DumpLink(header1);
	cout << "Link 2:" << endl;
	DumpLink(header2);

	fCrossed = LinkCrossed(header1, header2, crossAt);
	if (fCrossed)
		cout << "*** Result: Link crossed at node" << crossAt->m_value << endl;
	else
		cout << "*** Result: Link is not crossed" << endl;

	while (header1 != NULL)
	{
		LinkNode* temp = header1;
		header1 = header1->m_pNext;
		delete temp;
	}
	while (header2 != NULL)
	{
		LinkNode* temp = header2;
		header2 = header2->m_pNext;
		delete temp;
	}

	return 0;
}
