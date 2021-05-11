#ifndef LRUCache_H
#define LRUCache_H

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <vector>


struct Node {
	long unsigned int data;
	struct Node *prev;
	struct Node *next;
};
struct Node* head = NULL;

class LRUCache
{
	private:
		std::vector<long unsigned int> cache;
		size_t size;
		int hit = 0;
		int miss = 0;
		int counter = 0;
		int track = 0;
		
	
	public:
		LRUCache(size_t Size);
		
		void deleteHit(Node* head, int n);
		void deleteNode();
		void display() const;
		void write(long unsigned int data);
		void read(long unsigned int data);
};

#endif
