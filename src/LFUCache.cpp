#include "../inc/LFUCache.h"

LFUCache::LFUCache(int cap) : capacity(cap), size(0), hit(0), miss(0), records{0}, heads{0}, headList{nullptr} {}

LFUCache::~LFUCache() {
	delete headList;
}

LFUCache::LFUCache(const LFUCache& rhs) : capacity(rhs.capacity), size(rhs.size), hit(rhs.hit), miss(rhs.miss), records(rhs.records), heads(rhs.heads), headList(rhs.headList) {}

LFUCache & LFUCache::operator=(const LFUCache& rhs) {
	if (this != &rhs) {
		capacity = rhs.capacity;
		size = rhs.size;
		hit = rhs.hit;
		miss = rhs.miss;
		records = rhs.records;
		heads = rhs.heads;
		headList = rhs.headList;
	}
	return *this;
}

void LFUCache::write(int key, long unsigned int value) {
	auto data = records.find(key);
	if (data != records.end()) {
		Node *node = data->second;
		node->value = value;
		node->freq++;
		DDList *currList = heads[node];
		move(node, currList);
	}
	else {
		int newKey = -1;
		if (size == capacity) {
			Node *node = headList->tail;
			newKey = node->key;
			headList->deleteNode(node);
			changeHead(headList);
			records.erase(node->key);
			heads.erase(node);
			size--;
		}
		if (newKey != -1) {
			key = newKey;
		}
		Node *node = new Node(key, value, 1);
		if (headList == nullptr) {
			headList = new DDList(node);
		}
		else {
			if (headList->head->freq == node->freq) {
				headList->addHead(node);
			}
			else {
				DDList *newList = new DDList(node);
				newList->next = headList;
				headList->prev = newList;
				headList = newList;
			}
		}
		records[key] = node;
		heads[node] = headList;
		size++;
	}
}

void LFUCache::move(Node *node, DDList* prevList) {
	prevList->deleteNode(node);
	DDList *oldList = changeHead(prevList) ? prevList->prev : prevList;
	DDList *newList = prevList->next;
	if (newList == nullptr) {
		DDList *nextList = new DDList(node);
		if (oldList != nullptr) {
			oldList->next = nextList;
		}
		nextList->prev = oldList;
		if (headList == nullptr) {
			headList = nextList;
		}
		heads[node] = nextList;
	}
	else {
		if (newList->head->freq == node->freq) {
			newList->addHead(node);
			heads[node] = newList;
		}
		else {
			DDList *nextList = new DDList(node);
			if (oldList != nullptr) {
				oldList->next = nextList;
			}
			nextList->prev = oldList;
			nextList->next = newList;
			newList->prev = nextList;
			if (headList == newList) {
				headList = nextList;
			}	
			heads[node] = nextList;
		}
	}
}

bool LFUCache::changeHead(DDList *nodeList) {
	if (nodeList->isEmpty()) {
		if (headList == nodeList) {
			headList = nodeList->next;
			if (headList != nullptr) {
				headList->prev = nullptr;
			}
		}	
		else {
			nodeList->prev->next = nodeList->next;
			if (nodeList->next != nullptr) {
				nodeList->next->prev = nodeList->prev;
			}
		}
		return true;
	}
	return false;
}

long unsigned int LFUCache::read(int key, long unsigned int hex) {
	auto data = records.find(key);
	if (data == records.end()) {
		miss++;
		return -1;
	}
	Node *node = records[key];
	node->freq++;
	DDList *currNodeList = heads[node];
	move(node, currNodeList);
	if (node->value == hex) {
		hit++;
	}
	else {
		miss++;
	}
	return node->value;
}

int LFUCache::getHits() const {return hit;}

int LFUCache::getMisses() const {return miss;}
