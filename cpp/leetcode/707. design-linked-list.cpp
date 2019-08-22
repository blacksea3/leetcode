#include "public.h"

//112ms, 10.17%
//加入dump节点, 加入自定义struct
//单链表

class MyLinkedList {
private:
	struct Node
	{
		int val;
		Node* next;
		Node(int inputVal)
		{
			val = inputVal;
			next = nullptr;
		}
	};
	Node* dump;

public:
	/** Initialize your data structure here. */
	MyLinkedList() {
		Node* tempNode = new Node(-1);
		dump = tempNode;
	}

	/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
	int get(int index) {
		if (index < 0) return -1;

		int curIndex = 0;
		Node* curNode = dump;
		while (curIndex < index)
		{
			if (!(curNode->next)) return -1;
			curNode = curNode->next;
			curIndex++;
		}
		return (curNode->next) ? curNode->next->val : -1;
	}

	/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
	void addAtHead(int val) {
		Node* newNode = new Node(val);
		Node* nextNode = dump->next;
		dump->next = newNode;
		newNode->next = nextNode;
	}

	/** Append a node of value val to the last element of the linked list. */
	void addAtTail(int val) {
		Node* curNode = dump;
		while (curNode->next)
		{
			curNode = curNode->next;
		}
		Node* newNode = new Node(val);
		curNode->next = newNode;
	}

	/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
	void addAtIndex(int index, int val) {
		//此处如果index<=0, 都是默认头部插入节点

		int curIndex = 0;
		Node* curNode = dump;
		while (curIndex < index)
		{
			if (!(curNode->next)) return;
			curNode = curNode->next;
			curIndex++;
		}
		Node* newNode = new Node(val);
		Node* nextNode = curNode->next;
		curNode->next = newNode;
		newNode->next = nextNode;
	}

	/** Delete the index-th node in the linked list, if the index is valid. */
	void deleteAtIndex(int index) {
		if (index < 0) return;

		int curIndex = 0;
		Node* curNode = dump;
		while (curIndex < index)
		{
			if (!(curNode->next)) return;
			curNode = curNode->next;
			curIndex++;
		}
		Node* needDelNode = curNode->next;
		if (!needDelNode) return;
		else
		{
			Node* nextNextNode = needDelNode->next;
			curNode->next = nextNextNode;
			delete needDelNode;
		}
	}
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
