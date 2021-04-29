// Will Brigham and Zach Chua and Betty Hosler
// cache simulator

// methods will be labeled as integers 1 (LRU), 2 (LFRU), 3 (RR)
class cache{

	private:
		// lru data
		int *lru;

		// lfu data
		int *lfu;

		// rr data
		int *rr;

		// cache size
		int size;

		// misses counter
		int misses;

		// total number of times accessed
		int toal;

	public:
    	//default constructor
    	cache();
		void init(int, bool);

    	// simulates cache access taking address and way of cache
    	void access(unsigned int, int);
	
		// reset cache
		void reset();

		// miss rate
		double rate();

    	~cache();
};


