#ifndef NODE_H
#define NODE_H

class Node
{
	public:
		int key;
		long unsigned int value;
		int freq;
		Node *prev;
		Node *next;

	public:
		Node(int k, long unsigned int v, int f);
};

#endif
