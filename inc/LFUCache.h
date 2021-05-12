#ifndef LFUCache_H
#define LFUCache_H

#include <iostream>
#include <utility>
#include <unordered_map>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include "DDList.h"

class LFUCache
{
	private:
		int capacity;
		int size;
		int hit;
		int miss;
		std::unordered_map<int, Node *> records;
		std::unordered_map<Node *, DDList *> heads;
		DDList *headList;

	public:
		LFUCache(int cap);
		~LFUCache();
		LFUCache(const LFUCache& rhs);
		LFUCache& operator=(const LFUCache& rhs);

		void write(int key, long unsigned int value);
		void move(Node *node, DDList* prevList);
		bool changeHead(DDList *list);
		long unsigned int read(int key, long unsigned int hex);
		int getHits() const;
		int getMisses() const;
};

#endif
