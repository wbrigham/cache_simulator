// Will Brigham Betty Hosler and Zach Chua
// function definitions

#include <cache.h>

// empty constructor
cache::cache() {}

// destructor frees up memory
cache::~cache(){
	delete lru;
	delete lfu;
	delete rr;
}

void cache::init(int s, bool replace){
	size =s;
	method = replace;

	// initialize
	lru= new int[size];
	lfu = new int[size];
	rr = new int[size];
	reset();
}

void cache::reset(){

	for(int i =0; i <size; ++i){
		lru[i]=0;
		lfu[i]=0;
		rr[i]=0;
	}
	
	// reset counters
	misses = 0;
	total = 0;
}

void cache::access(unsigned int addr, int method){
}

double cache::rate(){
	return (double)misses/(double)total*100;
}
