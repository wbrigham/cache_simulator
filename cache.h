// Will Brigham and Zach Chua and Betty Hosler
// cache simulator

// methods will be labeled as integers 1 (LRU), 2 (LFRU), 3 (RR)
class cache{

  private:

  public:
    // constructor with replacement method and size
    cache(int,bool);

    //default constructor
    cache();

    // simulates cache access taking address and way of cache
    void access(unsigned int, int);

    ~cache();
};


