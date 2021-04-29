i// Will Brigham and Zach Chua and Betty Hosler
// cache simulator

// methods will be labeled as integers 1 (LRU), 2 (LFRU), 3 (RR)

class cache
{
public:
	// constructor, sets replacement method and size
	cache(int,bool);
	
	// the default constructor can be used and then init can be called
	// later to set the size/replacement method
	cache();
	void init(int,bool);
	
	// resets cache
	void reset();
	
	// simulates a cache access, takes address and "way" of cache
	void access(unsigned int,int);
	
	// returns current miss rate
	double rate();

	~cache();

private:
	// array for valid bits
	bool *valid;
	
	// holds cache tags
	int *tag;
	
	// holds data for lru/fifo replacement
	int *lru;
	
	// gets set to replacement method in constructor
	bool replacement_method;

	// size of cache
	int size;
	
	// counts misses
	int misses;
	
	// counts total accesses
	int total;
	
	// finds a tag in a sub-block of cache, returns offset from base
	int find_tag(int,int,int);
	
	// same as above but also updates fifo array to record access
	int fifo_offset(int,int);
	
	// decrements all values in a subarray of lru
	void decrement_all(int,int,int);
};
