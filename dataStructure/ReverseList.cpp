#include <iostream>


struct Node
{
	//Node();
	Node(int value): val(value), next(NULL){}
	int 		val;
	Node*		next;
};

Node  *ReverseList(Node* head)
{
	if(!head)
	{
		std::cout << "Empty Input!!" << std::endl;
		return NULL;
	}
	if(!head->next)
	{
		return head;
	}
	Node* preNode = head;
	Node* curNode = head->next;
	head->next = NULL;
	Node* tmpNode;
	while(curNode)
	{
		tmpNode = curNode->next;
		curNode->next = preNode;
		preNode = curNode;
		curNode = tmpNode;
	}
	return preNode;
}
void printList(Node* head)
{
	Node* curNode = head;
	while(curNode)
	{
		std::cout << curNode->val << "\t";
		curNode = curNode->next;
	}
	std::cout << std::endl;
}

int main()
{
	Node* head = new Node(1);
	Node* curNode = head;
	Node* node;
	for(int i = 2; i < 11; i++)
	{
		node = new Node(i);
		curNode->next = node;
		curNode = node;
	}
	std::cout << "Origin List: " << std::endl;
	printList(head);
	Node *reversedHead = ReverseList(head);
	std::cout << "Reversed List: " << std::endl;
	printList(reversedHead);
	return 0;
}
