#include "doubly_list.h"
#include <iostream>

using namespace std;

Node* DoublyList::appendHead(float value)
{
    Node* newNode = new Node(value, nullptr, nullptr);
    if (isEmpty())
	{
		head = tail = newNode;
	}
	else
	{
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
	return newNode;
}

Node* DoublyList::appendTail(float value)
{
    Node* newNode = new Node(value, nullptr, nullptr);
    if (isEmpty())
	{
		head = tail = newNode;
	}
	else
	{
	    newNode->prev = tail;
	    tail->next = newNode;
	    tail = newNode;
	}
	return newNode;
}

Node* DoublyList::insertNode(int index, float value)
{
    if (index < 0) return nullptr;
	Node* newNode = new Node(value, nullptr, nullptr);
	
	if (index == 0)
	{
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
	else
	{
		Node* nodePtr = head;
		int i;
		for (i = 0; nodePtr->next && i < index; i++)
		{
			nodePtr = nodePtr->next;
		}
		if (i == index)
		{
		    nodePtr->prev->next = newNode;
		    newNode->prev = nodePtr->prev;
		    nodePtr->prev = newNode;
		    newNode->next = nodePtr;
		}
		else
		{
		    nodePtr->next = newNode;
		    newNode->prev = nodePtr;
		    tail = newNode;
		}
	}
	return newNode;
}

bool DoublyList::removeNode(int index)
{
	if (index < 0) return false;
	
	if (index == 0)
	{
		Node* delNode = head;
		head->next->prev = nullptr;
		head = head->next;
		if (!head)
		{
		    tail = nullptr;
		}
		delete delNode;
		return true;
	}
	else
	{
		Node* nodePtr = head;
		int currIndex = 0;
		int i;
		for (i = 0; nodePtr->next && i < index; i++)
		{
			nodePtr = nodePtr->next;
		}
		if (i > index) 
		{
		    return false;
		}
		else if (nodePtr == tail)
		{
		    nodePtr->prev->next = nullptr;
		    tail = nodePtr->prev;
		}
		else
		{
		    nodePtr->prev->next = nodePtr->next;
		    nodePtr->next->prev = nodePtr->prev;
		}
		delete nodePtr;
		return true;
	}
}
	
int DoublyList::deleteNode(float value)
{
	int index = findNode(value);
	if (!removeNode(index))
	{
		index = -1;
	}
	return index;
}
 
int DoublyList::findNode(float value)
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
	
void DoublyList::displayNodes(void)
{
	Node* nodePtr = head;
	while (nodePtr)
	{
		std::cout << nodePtr->value << " ";
		nodePtr = nodePtr->next;
	}
	std::cout << std::endl;
}

DoublyList::~DoublyList(void)
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
