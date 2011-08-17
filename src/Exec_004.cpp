/**
 * @file Exec_004.cpp
 * @brief Find all path of a binary tree which sum up to a K
 * @author Peng Xia
 * @version 0.1
 * @date 2011-08-18
 */
#include <iostream>
#include <list>
using namespace std;


/**
 *	This is the Node structure
 */
struct Node 
{
	Node():left(NULL), right(NULL), value(0) {} /** The constructuror */
	struct Node* left;	/** the pointer to left node */
	struct Node* right;	/** the pointer to right node */
	int value;			/** the data */
};

/**
*	This function will print the node values in the pathList
*	@param pathList The list contains the path
*/
void PrintPath(list<Node*> pathList)
{

	cout << "Find a path: " << endl;
	for (list<Node*>::iterator it = pathList.begin(); it != pathList.end(); ++it)
		cout << "\tList Node: " << (*it)->value << endl; 
}

/**
*	This function is used to find the path which:
*		1) start from binary tree's root
*		2) the node vaoue in the path sum up to "sum"
*	@param root	The root node of the binary tree
*	@param sum	The subpath will sum up to this value
*	@param path	The list used to recored current path
*	
*	@note In this fucntion, we did not considered overflow of the sum.
*/
void FindPath(Node* root, int sum, list<Node*> &path)
{
	// check for NULL
	if (root == NULL)
		return;
	
	// push the root node of this tree in the list
	path.push_back(root);
	// if the root value equals sum, that means we fond a path
	if (root->value == sum)
		PrintPath(path);
	// find path in left/right sub tree
	FindPath(root->left, sum-root->value, path);
	FindPath(root->right, sum-root->value, path);
	// we have check subtrees which root is root, pop it
	path.pop_back();
}

/**
 *	This is the main fucntion which contains a simple test binary tree
 */
int main()
{

	// Build a test tree
	Node nodes[15];

	for (int i = 0; i < 7; i++)
	{
		nodes[i].left = &nodes[i*2+1];
		nodes[i].right = &nodes[i*2+2];
	}
	nodes[0].value = 2;
	nodes[1].value = 98;
	nodes[2].value = 50;
	nodes[3].value = 3;
	nodes[4].value = 5;
	nodes[5].value = 48;
	nodes[6].value = 30;
	nodes[7].value = -3;
	nodes[8].value = 3;
	nodes[9].value = 5;
	nodes[10].value = -5;
	nodes[11].value = 0;
	nodes[12].value = 1;
	nodes[13].value = 10;
	nodes[14].value = 20;

	// the aux list used by FindPath
	list<Node*> path;
	// call FinPath to find the paths sum up 100
	FindPath(&nodes[0], 100, path);
}

