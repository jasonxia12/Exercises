#include <iostream>

using namespace std;

struct LinkNode
{
	LinkNode():m_value(0), m_pNext(NULL), m_pMin(NULL) {}
	LinkNode(const int value):m_value(value), m_pNext(NULL), m_pMin(NULL) {}

	int m_value;
	LinkNode *m_pNext;
	LinkNode *m_pMin;
};

class MinStack
{
public:
	MinStack():m_link(NULL) {}
	~MinStack() { int temp; while (m_link != NULL) Pop(temp); }

	bool Push(const int value);
	bool Pop(int& value);
	bool Min(int& value);
	bool Top(int& value);
private:
	LinkNode* m_link;
};

bool MinStack::Push(const int value)
{
	LinkNode* newNode = new LinkNode(value);

	if (newNode == NULL) 
		return false;

	if (m_link && m_link->m_pMin->m_value < value)
		newNode->m_pMin = m_link->m_pMin;
	else
		newNode->m_pMin = newNode;
	newNode->m_pNext = m_link;
	m_link = newNode;
	
	return true;
}

bool MinStack::Pop(int& value)
{
	if (m_link == NULL)
		return false;

	value = m_link->m_value;

	LinkNode* pNode = m_link;
	m_link = pNode->m_pNext;
	delete pNode;
	
	return true;
}

bool MinStack::Top(int& value)
{
	if (m_link == NULL)	
		return false;

	value = m_link->m_value;
}

bool MinStack::Min(int& value)
{
	if (m_link == NULL)
		return false;

	value = m_link->m_pMin->m_value;
}

int main()
{
	MinStack testStack;

	int testCaseSize = 20;
	int testCaseMin = 0;
	int testCaseMax = 100;
	int value;
	srand(time(NULL));
	for (int i = 0; i < testCaseSize; i++)
	{
		value = rand()%(testCaseMax-testCaseMin)+testCaseMin;
		testStack.Push(value);
		cout << "push value : " << value << endl;
	}

	cout << "=====================" << endl;
	for (int i = 0; i < testCaseSize; i++)
	{
		testStack.Min(value);
		cout << "current min : " << value << endl;
		testStack.Top(value);
		cout << "current top : " << value << endl; 
		testStack.Pop(value);
		cout << endl;
	}
	return 0;
}

	
