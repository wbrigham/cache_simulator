#include "../inc/DDList.h"

DDList::DDList(Node *node) : head(node), tail(node), prev(nullptr), next(nullptr) {}

void DDList::addHead(Node *newHead) {
	newHead->next = head;
	head->prev = newHead;
	head = newHead;
}
bool DDList::isEmpty() {
	return head == nullptr;
}

void DDList::deleteNode(Node *node) {
	if (head == tail) {
		head = nullptr;
		tail = nullptr;
	}
	else {
		if (node == head) {
			head = node->next;
			head->prev = nullptr;
		}
		else if (node == tail) {
			tail = node->prev;
			tail->next = nullptr;
		}
		else {
			node->prev->next = node->next;
			node->next->prev = node->prev;
		}
	}
	node->next = nullptr;
	node->prev = nullptr;
}
