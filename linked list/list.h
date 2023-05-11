#ifndef LIST_H
#define LIST_H

struct Node
{
	float value;
	Node* next;
	
	Node(void) {}
	Node(float value, Node* next)
	{
		this->value = value;
		this->next = next;
	}
};

class List
{
	Node* head;
public:
	List(void)
	{	
		head = nullptr;
	}
	~List(void);
	Node* appendNode(float value);
	Node* insertNode(int index, float value);
	bool removeNode(int index);
	int deleteNode(float value);
	int findNode(float value);
	void displayNodes(void); 
};

#endif
