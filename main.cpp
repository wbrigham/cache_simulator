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

int main(int argc,char **argv){

	if(argc != 2)
	{
		// print error and quit
		cout << "Usage:input_file\n";
		return 0;
	}

	// for loop counter
	int i;

	// the input file
	ifstream infile(argv[1]);
	
	// data from input file, read one at a time
	int read;

	// caches
	cache caches[NUM_CACHES];	
	
	// initialize the caches to have varying sizes and replacement policies
	for(i=0;i<NUM_CACHES;++i)
		caches[i].init();

	// while there is data to be read
	while(infile >> read){
		for(i=0;i<NUM_CACHES;++i)
			caches[i].access(read,);
	}
	
	infile.close();
	
	return 0;
}
