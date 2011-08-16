#include <iostream>

struct BinTreeNode {
	BinTreeNode():m_value(0), m_left(NULL), m_right(NULL) {}
	BinTreeNode(int value):m_value(value), m_left(NULL), m_right(NULL) {}
	int m_value;
	BinTreeNode *m_left;
	BinTreeNode *m_right;
};

/**
 * @brief Generate a random binary tree with n int nodes
 *
 * @param n		The node count of the generated binary tree.
 * @param min	The minium number of the int value
 * @param max	The maxium number of the int value
 *
 * @return The root node of the generated binary tree.
 */
BinTreeNode* GenTestBinTree(int n, int min, int max)
{
	if (n <= 0) 
		return NULL;

	// Initialize random number generator
	srand(time(NULL));

	// Generate a number
	int value = rand()%(max-min)+min;
	BinTreeNode *root = new BinTreeNode(value);
	if (root == NULL)
		return NULL;

	for (int i = 0; i < n-1; i++)
	{
		value = rand()%(max-min)+min;	
		BinTreeNode *pNewNode= new BinTreeNode(value);

		BinTreeNode *pParent= root;
		bool fSuccess = false;
		while (!fSuccess)
		{
			int insertLeft = rand()%2;
			if (insertLeft)
			{
				if (pParent->m_left == NULL)
				{
					pParent->m_left = pNewNode;
					fSuccess = true;
				}
				pParent = pParent->m_left;
			}
			else
			{
				if (pParent->m_right == NULL)
				{
					pParent->m_right = pNewNode;
					fSuccess = true;
				}
				pParent = pParent->m_right;
			}
		} // while
	} // for
	return root;
}

void DelAllNodes(BinTreeNode* root)
{
	// Delete all nodes in left sub tree
	if (root->m_left != NULL)
	{
		DelAllNodes(root->m_left);
	}
	// Delete all nodes in right sub tree 
	if (root->m_right != NULL)
	{
		DelAllNodes(root->m_right);
	}
	// Delete the root node and set it to NULL
	delete root;
}


void DumpBinTreeImpl(FILE *f, const BinTreeNode *root)
{
	static int nodeId = 0;
	if (root == NULL) return;

	fprintf(f, "\tnode%p [label=\"<f0>|<f1>%d|<f2>\"]\n", root, root->m_value);
	if (root->m_left)
	{
		fprintf(f, "\t\"node%p\":f0 -> \"node%p\":f1\n", root, root->m_left);
	}
	/*
	else
	{
		fprintf(f, "\tnullnode%d [label=\"null\"]\n", nodeId);
		fprintf(f, "\tnode%p -> nullnode%d\n", root, nodeId++);
	}
	*/
	if (root->m_right)
	{
		fprintf(f, "\t\"node%p\":f2 -> \"node%p\":f1\n", root, root->m_right);	
	}
	/*
	else
	{
		fprintf(f, "\tnullnode%d [label=\"null\"]\n", nodeId);
		fprintf(f, "\tnode%p -> nullnode%d\n", root, nodeId++);
	}
	*/

	DumpBinTreeImpl(f, root->m_left);
	DumpBinTreeImpl(f, root->m_right);
}

void DumpBinTree(const BinTreeNode *root)
{
	FILE *f = fopen("bintree.dot", "w");
	fprintf(f, "digraph G {\n");
	fprintf(f, "\tnode [shape = record, height=0.1]\n");
	DumpBinTreeImpl(f, root);
	fprintf(f, "}\n");
	fclose(f);
}

int main()
{
	BinTreeNode *root;

	root = GenTestBinTree(30, 1, 100);
	DumpBinTree(root);
		
}


	

