#ifndef SORTED_LIST_H
#define SORTED_LIST_H

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

class SortedList
{
	Node* head;
public:
	SortedList(void)
	{	
		head = nullptr;
	}
	~SortedList(void);
	bool isEmpty() { return static_cast<bool>(!head); }
	// appendNode: 리스트에 노드를 삽입한 후에 정렬 상태를 유지한다. 새로운 노드의 포인터를 반환한다.
	Node* appendNode(float value);
	// deleteNode : 리스트 앞에서부터 순회하며 value를 가진 노드를 찾는다. 가장 먼저 찾은 노드를 삭제하고 true를 반환한다.
	bool deleteNode(float value);
	// findNode : 리스트 앞에서부터 순회하며 value를 가진 노드를 찾고 노드의 인덱스를 반환한다.
	int findNode(float value);
	// displayNodes : 리스트를 앞에서부터 순회하며 노드들의 value를 출력한다.
	void displayNodes(void); 
};

#endif
