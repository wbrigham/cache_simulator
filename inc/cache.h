c// Will Brigham and Zach Chua and Betty Hosler
// cache simulator

// methods will be labeled as integers 1 (LRU), 2 (LFRU), 3 (RR)
class cache{
public:
	cache(int,bool);
	
	cache();
	void init(int,bool);
	
	void reset();
	
	void access(unsigned int,int);
	
	double rate();

	~cache();

private:
	bool *valid;
	
	int *tag;
	
	int *lru;
	
	bool replacement_method;

	int size;
	
	int misses;
	
	int total;

	int find_tag(int,int,int);
	
	int lru_offset(int,int);
	
};
