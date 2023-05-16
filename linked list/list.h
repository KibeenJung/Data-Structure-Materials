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
	// appendNode: 리스트의 헤드에 value를 가진 노드를 추가한다.
	Node* appendNode(float value);
	// insertNode: index 위치에 value를 가진 노드를 삽입한다. 기존의 index 위치에 있던 노드와 그 뒤에 있던 노드들은 한 칸 씩 뒤로 밀린다. index는 0부터 시작한다.
	Node* insertNode(int index, float value);
	// removeNode : index 위치에 있는 노드를 삭제한다 (삭제 시 동적해제 필수). index 뒤에 위치해 있던 노드들은 한칸씩 앞으로 밀린다.
	bool removeNode(int index);
	// deleteNode : 리스트 앞에서부터 순회하며 value를 가진 노드를 찾는다. 가장 먼저 찾은 노드를 삭제한다.
	int deleteNode(float value);
	// findNode : 리스트 앞에서부터 순회하며 value를 가진 노드를 찾고 노드의 인덱스를 반환한다.
	int findNode(float value);
	// displayNodes : 리스트를 앞에서부터 순회하며 노드들의 value를 출력한다.
	void displayNodes(void); 
};

#endif
