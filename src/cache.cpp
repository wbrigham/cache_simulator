// Will Brigham Betty Hosler and Zach Chua
// function definitions

#include <cache.h>
cache::cache(int s,bool replacement)
{	
	size=s;
	replacement_method=replacement;

	valid=new bool[size];
	
	tag=new int[size];
	
	lru=new int[size];
	
	reset();
}

cache::cache()
{

}

cache::~cache()
{
	delete valid;
	delete tag;
	delete lru;
}

void cache::init(int s,bool replacement)
{
	size=s;
	replacement_method=replacement;

	valid=new bool[size];
	tag=new int[size];
	lru=new int[size];
	reset();
}

void cache::reset()
{
	for(int i=0;i<size;++i)
	{
		valid[i]=0;
		lru[i]=0;
		tag[i]=0;
	}

	misses=0;
	total=0;
}

void cache::access(unsigned int addr,int way)
{
	++total;
	
	int index=(int)(addr/16)%(size/way) * way;
	
	int target_tag=addr/size*16;
	
	int target_index=find_tag(index,way,target_tag);
	
	if(valid[index] && target_index)
	{
		if(replacement_method==0)
		{
			if(lru[index+target_index-1]!=way-1)
			{
				lru[index+target_index-1]=way-1;
			}
		}
	}
	else
	{
		++misses;

		valid[index]=1;

		tag[index+lru_offset(index,way)]=target_tag;
	}
}

int cache::find_tag(int index,int way,int target)
{
	for(int i=0;i<way;++i)
		if(tag[index+i]==target)
			return 1+i;
	
	return 0;
}

double cache::rate()
{
	return (double)misses/(double)total*100;
}

int cache::lru_offset(int base, int way){
	for(int i=0;i<way;++i)
	{
		if(lru[i+base]==0)
		{
			lru[i+base]=way;

			return i;				
		}
	}

	return 0;
}

