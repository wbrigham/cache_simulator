#ifndef DDLIST_H
#define DDLIST_H

#include "Node.h"

class DDList
{
	public:
		Node *head;
		Node *tail;
		DDList *prev;
		DDList *next;
	
	public:
		DDList(Node *node);
		void addHead(Node *newHead);
		bool isEmpty();
		void deleteNode(Node *node);
};

#endif
