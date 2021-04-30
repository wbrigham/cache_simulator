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
	// if fine name isn't passed in
	if(argc != 2)
	{
		// print error and quit
		cout << "Usage: as3 input_file\n";
		return 0;
	}

	cout << "Execution will take about 20 seconds, please wait...\n";


	// for loop counter
	int i;

	// the input file
	ifstream infile(argv[1]);

	// data from input file, read one at a time
	int read;

	// caches
	block caches[NUM_CACHES];

	// initialize the caches to have varying sizes and replacement policies
	for(i=0;i<NUM_CACHES;++i)
		caches[i].init(64*(int)pow(2,i%5),(i>19));

	// while there is data to be read
	while(infile >> read)
	{
		// put the data in each cache, and set the "way" assiciativity different
		// for each
		for(i=0;i<NUM_CACHES;++i)
			caches[i].access(read,(int)pow(2,(i/5))%16+(int)pow(2,(i/5))/16);
	}


	// close input file
	infile.close();

	return 0;
}
