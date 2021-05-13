#ifndef NODE_H
#define NODE_H

class Node
{
	public:
		long unsigned int data;
		Node *prev;
		Node *next;

	public:
		Node(long unsigned int d);
};

#endif
