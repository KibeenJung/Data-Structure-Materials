
#include <iostream>
#include "sorted_list.h"

Node* SortedList::appendNode(float value)
{
	Node* newNode = new Node(value, nullptr);
	if (isEmpty())
	{
		head = newNode;
	}
	else if (value <= head->value)
	{
	    newNode->next = head;
	    head = newNode;
	}
	else
	{
	    Node* curNode = head;
	    while (curNode->next)
	    {
	        if (value <= curNode->next->value) break;
	        curNode = curNode->next;
	    }
	    newNode->next = curNode->next;
	    curNode->next = newNode;
	}
	return newNode;
}

void SortedList::displayNodes(void)
{
	Node* nodePtr = head;
	while (nodePtr)
	{
		std::cout << nodePtr->value << " ";
		nodePtr = nodePtr->next;
	}
	std::cout << std::endl;
}

int SortedList::findNode(float value)
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

bool SortedList::deleteNode(float value)
{
	if(isEmpty()) return false;
	if (head->value == value)
	{
	    Node* delNode = head;
	    head = head->next;
	    delete delNode;
	    return true;
	}
	else
	{
	    Node* nodePtr = head;
	    while (nodePtr->next)
	    {
	        if (value == nodePtr->next->value)
	        {
	            Node* delNode = nodePtr->next;
	            nodePtr->next = nodePtr->next->next;
	            delete delNode;
	            return true;
	        }
	        nodePtr = nodePtr->next;
	    }
	}
    return false;
}

SortedList::~SortedList(void)
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
