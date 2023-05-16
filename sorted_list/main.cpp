/*
appendNode
5 
4 5 
4 5 7 
2 4 5 7 
2 4 5 7 8 
2 4 5 6 7 8 
findNode:3
findNode:0
findNode:5
findNode:-1
deleteNode
4 5 6 7 8 
4 5 6 7 
4 5 6 7 
4 5 7 
destructor: 4 5 7
*/

#include <iostream>
#include "sorted_list.h"

using namespace std;

int main()
{
	SortedList list;
	cout << "appendNode" << endl;
	list.appendNode(5);
	list.displayNodes();
	list.appendNode(4);
	list.displayNodes();
	list.appendNode(7);
	list.displayNodes();
	list.appendNode(2);
	list.displayNodes();
	list.appendNode(8);
	list.displayNodes();
	list.appendNode(6);
	list.displayNodes();
	
	cout << "findNode:" << list.findNode(6) << endl;
	cout << "findNode:" << list.findNode(2) << endl;
	cout << "findNode:" << list.findNode(8) << endl;
	cout << "findNode:" << list.findNode(32) << endl;
	
	cout << "deleteNode" << endl;
	list.deleteNode(2);
	list.displayNodes();
	list.deleteNode(8);
	list.displayNodes();
	list.deleteNode(3);
	list.displayNodes();
	list.deleteNode(6);
	list.displayNodes();
	
	return 0;
}
