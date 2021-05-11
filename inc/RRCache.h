#ifndef RRCache_H
#define RRCache_H

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <vector>

class RRCache
{
	private:
		std::vector<long unsigned int> cache;
		size_t size;
		int hit = 0;
		int miss = 0;
		
		bool isFull() const;
		long unsigned int randomDelete() const;
	
	public:
		RRCache(size_t Size);
		
		void updateHits();
		void updateMisses();
		int getHits() const;
		int getMisses() const;
		void printCache() const;
		void write(long unsigned int data);
		void read(long unsigned int data);
};

#endif
