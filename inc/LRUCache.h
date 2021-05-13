#ifndef LRUCache_H
#define LRUCache_H

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <vector>
#include "Node.h"


/*struct Node {
	long unsigned int data;
	struct Node *prev;
	struct Node *next;
};


struct Node* head = NULL;*/

class LRUCache
{
	private:
		int hit = 0;
		int miss = 0;
		int counter = 0;
		int track = 0;
		struct Node *head = NULL;
		
	
	public:
		LRUCache();
		
		void updateHits();
		void updateMisses();
		void deleteNode();
		void deleteHit(Node *find, int n);
		int getHits() const;
		int getMisses() const;
		void write(long unsigned int data);
		void read(long unsigned int data);
};

#endif
