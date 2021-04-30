<<<<<<< HEAD
// main
=======
//Microsoft Preternship Project Team:
//Will Brigham wbrigham@nd.edu
//Elizabeth Hosler ehosler@nd.edu
//Zachary Chua zchua@nd.edu
//
//This is a cache simulator. It will take data from an input trace file passed on the command line. It will then siulate the data in the file....
>>>>>>>

#define NUM_CACHES 8

#include <math.h>
#include <fstream.h>
#include <stdio.h>
#include "block.h"

int main(int argc,char **argv)
{
	if(argc != 2)
	{
		// print error and quit
		cout << "Usage: Invalid File\n";
		return 0;
	}

	// the input file
	ifstream infile(argv[1]);

	// data from input file, read one at a time
	int read;

	// caches
	block caches[NUM_CACHES];

	// initialize the caches to have varying sizes and replacement policies
	for(int i=0;i<NUM_CACHES;++i)

	// while there is data to be read
	while(infile >> read)
	{
		// put the data in each cache, and set the "way" assiciativity different
		// for each
		for(i=0;i<NUM_CACHES;++i)
	}


	// close input file
	infile.close();

	return 0;
}
