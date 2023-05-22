
#include <iostream>
#include "list.h"

Node* List::appendNode(float value)
{
	Node* newNode = new Node(value, nullptr);
	if (!head)
	{
		head = newNode;
	}
	else
	{
		newNode->next = head;
		head = newNode;
	}
	return newNode;
}

void List::displayNodes(void)
{
	Node* nodePtr = head;
	while (nodePtr)
	{
		std::cout << nodePtr->value << " ";
		nodePtr = nodePtr->next;
	}
	std::cout << std::endl;
}


Node* List::insertNode(int index, float value)
{
	if (index < 0) return nullptr;
	Node* newNode = new Node(value, nullptr);
	
	if (index == 0)
	{
		newNode->next = head;
		head = newNode;
	}
	else
	{
		Node* nodePtr = head;
		int i;
		for (i = 0; nodePtr->next && i < (index - 1); i++)
		{
			nodePtr = nodePtr->next;
		}
		newNode->next = nodePtr->next;
    	    	nodePtr->next = newNode;   
	}
	return newNode;
}

int List::findNode(float value)
{
	Node* nodePtr = head;
	int index = 0;
	while (nodePtr)
	{
		if (value == nodePtr->value) return index;
		nodePtr = nodePtr->next;
		index += 1;
	}
	return -1;
}

bool List::removeNode(int index)
{
	if (index < 0) return false;
	
	if (index == 0)
	{
		Node* delNode = head;
		head = head->next;
		delete delNode;
		return true;
	}
	else
	{
		Node* nodePtr = head;
		int currIndex = 0;
		for (int i = 0; nodePtr->next && i < (index - 1); i++)
		{
			nodePtr = nodePtr->next;
		}
		if (!nodePtr->next) return false;
		Node* delNode = nodePtr->next;
		nodePtr->next = nodePtr->next->next;
		delete delNode;
		return true;
	}
}

int List::deleteNode(float value)
{
    int index = 0;
	for (Node* curNode = head; curNode->next; curNode = curNode->next)
	{
	    if (curNode->next->value == value)
	    {
	        Node* delNode = curNode->next;
	        curNode->next = curNode->next->next;
	        delete delNode;
	        return index;
	    }
	    index += 1;
	}
	return -1;
}

/*
int List::deleteNode(float value)
{
	int index = findNode(value);
	if (!removeNode(index))
	{
		index = -1;
	}
	return index;
}
*/

List::~List(void)
{
	Node* nodePtr = head;
	std::cout << "destructor: ";
	while (nodePtr)
	{
		Node* delNode = nodePtr;
		nodePtr = nodePtr->next;
		std::cout << delNode->value << " ";
		delete delNode;
	}
	std::cout << std::endl;
}
