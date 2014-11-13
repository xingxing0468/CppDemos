#include <iostream>
#include <list>

struct treeNode
{
	treeNode(int inValue = 0)
	{
		value = 0;
		leftChild = NULL;
		rightChild = NULL;
	};

	treeNode *leftChild;
	treeNode *rightChild;
	int value;
}

treeNode *buildBinaryTreeFromOneSortedArray(int value[], int begin, int end)
{
	if(begin > end) return NULL;
	int mid = ( begin + end )/2;
	treeNode *root = new treeNode();
	root->value = value[mid];
	std::cout << "Begin:" << begin << "  end:" << end << "  mid" << mid << std::endl;
	std::cout << "root value: " << root->value << std::endl;
	std::cout << std::endl;
	root->leftChild  = buildBinaryTreeFromOneSortedArray(value, 0, mid -1);
	root->rightChild = buildBinaryTreeFromOneSortedArray(value, mid + 1, end); 
	return root;
};

void PrintTreeStructure(treeNode* root)
{
	std::list<treeNode*> nodeList;
	std::list<treeNode*> tempList;
	nodeList.push_back(root);
	//std::cout << root->value << std::endl;
	while(!nodeList.empty())
	{
		tempList.clear();
		for(std::list<treeNode*>::iterator iter = nodeList.begin(); iter != nodeList.end(); iter++)
		{
			std::cout << (*iter)->value << "  ";
			tempList.push_back((*iter)->leftChild);
			tempList.push_back((*iter)->rightChild);
		}
		nodeList.clear();
		std:copy(tempList.begin(), tempList.end(), std::back_inserter(nodeList));
		std::cout << std::endl;
	}
	return;
}

int main()
{
	int value[] = {1,2,3,4,5,5,6,6,6,7,8,9};
	treeNode *root = buildBinaryTreeFromOneSortedArray(value, 0, 11);
	//PrintTreeStructure(root);
	return 0;
}
