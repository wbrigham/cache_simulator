#include "../inc/RRCache.h"

RRCache::RRCache(size_t Size) : cache(std::vector<long unsigned int>(0)), size(Size), hit(0), miss(0) {}

bool RRCache::isFull() const {
	if (cache.size() >= size)
		return true;
	else
		return false;
}

long unsigned int RRCache::randomDelete() const {
	srand((unsigned) time(0));
	return rand() % cache.size();
}

void RRCache::updateHits() {
	hit = hit + 1;
}

void RRCache::updateMisses() {
	miss = miss + 1;
}

int RRCache::getHits() const {return hit;}

int RRCache::getMisses() const {return miss;}

void RRCache::printCache() const {
	for (unsigned int i = 0; i < cache.size(); i++) {
		std::cout << cache.at(i) << std::endl;
	}
}

void RRCache::write(long unsigned int data) {
	if (!isFull()) {
		cache.push_back(data);
	}
	else {
		long unsigned int index = randomDelete();
		cache.at(index) = data;
	}
}

void RRCache::read(long unsigned int data) {
	bool found = false;
	for (unsigned int i = 0; i < cache.size(); i++) {
		if (cache.at(i) == data) {
			found = true;
			break;
		}
	}
	if (found)
		updateHits();
	else
		updateMisses();
}
